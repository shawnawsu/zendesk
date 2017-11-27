<?php

function zendesk_views_data() {
  $data['zendesk_tickets'] = array(
    'table' => array(
      'group' => 'Zendesk ticket',
      'base' => array(
        'field' => 'id',
        'title' => 'Zendesk tickets',
      ),
    ),
    'id' => array(
      'title' => t('Ticket ID'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'url' => array(
      'title' => t('Ticket URL'),
      'field' => array(
        'handler' => 'views_handler_field_url',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'external_id' => array(
      'title' => t('Ticket External ID'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'created_at' => array(
      'title' => t('Created At'),
      'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_date',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_date',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_date',
      ),
    ),
    'updated_at' => array(
      'title' => t('Updated At'),
      'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_date',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_date',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_date',
      ),
    ),
    'priority' => array(
      'title' => t('Priority'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'status' => array(
      'title' => t('Status'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'recipient' => array(
      'title' => t('Recipient'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'requester_id' => array(
      'title' => t('Requester ID'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
      'relationship' => array(
        'handler' => 'views_handler_relationship_link_reverse',
        'real_field' => 'requester_id',
        'link table' => 'zendesk_users',
        'link field' => 'zid',
        'base' => 'users',
        'base field' => 'uid',
        'base link field' => 'uid',
        'label' => t('Requester account'),
        'group' => t('Zendesk Reference'),
        'title' => t('Requester account'),
        'base_join_extra' => array(),
        'link_join_extra' => array(),
      ),
    ),
    'submitter_id' => array(
      'title' => t('Submitter ID'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
      'relationship' => array(
        'handler' => 'views_handler_relationship_link_reverse',
        'real_field' => 'submitter_id',
        'link table' => 'zendesk_users',
        'link field' => 'zid',
        'base' => 'users',
        'base field' => 'uid',
        'base link field' => 'uid',
        'label' => t('Submitter account'),
        'group' => t('Zendesk Reference'),
        'title' => t('Submitter account'),
        'base_join_extra' => array(),
        'link_join_extra' => array(),
      ),
    ),
    'assignee_id' => array(
      'title' => t('Assignee ID'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
      'relationship' => array(
        'handler' => 'views_handler_relationship_link_reverse',
        'real_field' => 'assignee_id',
        'link table' => 'zendesk_users',
        'link field' => 'zid',
        'base' => 'users',
        'base field' => 'uid',
        'base link field' => 'uid',
        'label' => t('Assignee account'),
        'group' => t('Zendesk Reference'),
        'title' => t('Assignee account'),
        'base_join_extra' => array(),
        'link_join_extra' => array(),
      ),
    ),
    'organization_id' => array(
      'title' => t('Organization ID'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
  );

  return $data;
}
