<?php
/**
 * A minimal Zendesk API PHP implementation
 *
 * @package Zendesk
 *
 * @author  Julien Renouard <renouard.julien@gmail.com> (deeply inspired by Darren Scerri <darrenscerri@gmail.com> Mandrill's implemetation)
 *
 * @version 1.0
 *
 */
class zendesk
{
  /**
   * API Constructor. If set to test automatically, will return an Exception if the ping API call fails
   *
   * @param string $apiKey API Key.
   * @param string $user Username on Zendesk.
   * @param string $subDomain Your subdomain on zendesk, without https:// nor trailling dot.
   * @param string $suffix .json by default.
   * @param bool $test=true Whether to test API connectivity on creation.
   */
  public function __construct($apiKey, $user, $subDomain, $suffix = '.json', $test = false)
  {
    $this->api_key = $apiKey;
    $this->user    = $user;
    $this->base    = 'https://' . $subDomain . '.zendesk.com/api/v2';
    $this->suffix  = $suffix;
    if ($test === true && !$this->test())
    {
      throw new Exception('Cannot connect or authentice with the Zendesk API');
    }
  }

  public function curl($url, $json, $action) {
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
    curl_setopt($ch, CURLOPT_MAXREDIRS, 10 );
    curl_setopt($ch, CURLOPT_USERPWD, $this->user."/token:".$this->api_key);
    switch ($action) {
      case "POST":
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "POST");
        curl_setopt($ch, CURLOPT_POSTFIELDS, $json);
        break;
      case "GET":
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "GET");
        break;
      case "DELETE":
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "DELETE");
        break;
      case "PUT":
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "PUT");
        curl_setopt($ch, CURLOPT_POSTFIELDS, $json);
        break;
      case "UPLOAD":
        // In this case the $json is an array with a Drupal file object
        $file_object = $json['file'];
        $file = fopen($file_object->uri, 'r');
        $filesize = $file_object->filesize;
        $filedata = '';
        while (!feof($file)) {
          $filedata .= fread($file, 8192);
        }
        //Check for a token.
        if (isset($json['token'])) {
          $token = $json['token'];
        }
        else {
          $token = NULL;
        }
        curl_setopt($ch, CURLOPT_POSTFIELDS, $filedata);
        curl_setopt($ch, CURLOPT_INFILE, $file);
        curl_setopt($ch, CURLOPT_INFILESIZE, $filesize);
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "POST");
        curl_setopt($ch, CURLOPT_BINARYTRANSFER, TRUE);
        $url .= '?' . http_build_query(array("filename" => $file_object->filename, "token" => $token));
        break;
      default:
        break;
    }
    // Different headers for a file transfer.
    switch ($action) {
      case "UPLOAD":
        curl_setopt($ch, CURLOPT_HTTPHEADER, array('Content-type: application/binary'));
        break;
      default:
        curl_setopt($ch, CURLOPT_HTTPHEADER, array('Content-type: application/json'));
        break;
    }

    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_USERAGENT, "MozillaXYZ/1.0");
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_TIMEOUT, variable_get('zendesk_curl_timeout', 10));

    $output = curl_exec($ch);
    if ($output === FALSE) {
      throw new Exception(curl_error($ch), curl_errno($ch));
    }
    curl_close($ch);
    $decoded = json_decode($output);
    return is_null($decoded) ? $output : $decoded;
  }

  /**
   * Perform an API call.
   *
   * @param string $url='/tickets' Endpoint URL. Will automatically add the suffix you set if necessary (both '/tickets.json' and '/tickets' are valid)
   * @param array $json=array() An associative array of parameters
   * @param string $action Action to perform POST/GET/PUT
   *
   * @return mixed Automatically decodes JSON responses. If the response is not JSON, the response is returned as is
   */
  public function call($url, $json, $action)
  {
    if (substr_count($url, $this->suffix) == 0)
    {
      $url .= '.json';
    }
    $url = $this->base . $url;
    return $this->curl($url, $json, $action);
  }

  /**
   * Tests the API using /users/ping
   *
   * @return bool Whether connection and authentication were successful
   */
  public function test()
  {
    return $this->call('/tickets', '', 'GET');
  }
}
