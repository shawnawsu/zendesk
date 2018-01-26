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
      'help' => t('The unique identifier for the ticket.'),
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
    'subject' => array(
      'title' => t('Subject'),
      'help' => t('The ticket subject line.'),
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
    ),
    'url' => array(
      'title' => t('Ticket URL'),
      'help' => t('The URL to view this ticket on Zendesk.'),
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
      'help' => t('The external ID of this ticket, if any.'),
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
      'help' => t('The date the ticket was created.'),
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
      'help' => t('The date the ticket was last updated.'),
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
      'help' => t('The priority level assigned to the ticket.'),
      'field' => array(
        'handler' => 'views_handler_field_machine_name',
        'options callback' => 'zendesk_ticket_priority_options',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_in_operator',
        'options callback' => 'zendesk_ticket_priority_options',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'status' => array(
      'title' => t('Status'),
      'help' => t('The status of the ticket.'),
      'field' => array(
        'handler' => 'views_handler_field_machine_name',
        'options callback' => 'zendesk_ticket_status_options',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_in_operator',
        'options callback' => 'zendesk_ticket_status_options',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'recipient' => array(
      'title' => t('Recipient'),
      'help' => t('The e-mail address of the original ticket recipient.'),
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
      'help' => t('The Zendesk user ID of the person who requested this ticket.'),
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
      'help' => t('The Zendesk user ID of the person who submitted this ticket.'),
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
      'help' => t('The Zendesk user ID of the agent assigned to this ticket.'),
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
      'help' => t('The Zendesk ID of the organization to which this ticket belongs.'),
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

  // Create a field table for each ticket field. Each of these fields stores
  // their values in the same table (similar in some ways to a Drupal field
  // table or an EAV model) and so the extra join is the distinguishing factor
  // between each Views pseudo-table.

  $ticket_fields = entity_load('zendesk_ticket_field', FALSE);

  foreach ($ticket_fields as $field_def) {
    // Bail on inactive fields.
    if (!$field_def->active) {
      continue;
    }
    // @TODO: Exclude field definitions that are stored directly on the tickets
    // table.

    // With that done, make a pseudotable name and generate a Views data
    // definition for it.
    $table = 'zendesk_ticket_field_' . $field_def->id;
    $data[$table] = zendesk_ticket_field_views_data($field_def);
  }

  return $data;
}

/**
 * Generate the jointable definition for a specific ticket field.
 */
function zendesk_ticket_field_views_data($field_def) {
  // Form the base table definition with a join to the tickets table.
  $table = [
    'table' => [
      'group' => t('Zendesk ticket'),
      'join' => [
        'zendesk_tickets' => [
          // The real table is the field values table.
          'table' => 'zendesk_ticket_field_values',
          'field' => 'ticket_id',
          // Joined to zendesk_tickets on the ticket ID
          'left_field' => 'id',
          'extra' => [
            'field_id' => [
              'field' => 'field_id',
              'value' => $field_def->id,
              'numeric' => TRUE,
            ],
          ],
        ],
      ],
    ],
  ];

  // Add the value column depending on the type of the field in question.
  switch ($field_def->type) {
    case 'tagger':
      $table['value'] = [
        'title' => t($field_def->title),
        'help' => t($field_def->description) ?: t($field_def->title),
        'field' => array(
          'handler' => 'views_handler_field_machine_name',
          'options callback' => 'zendesk_get_options_from_field',
          'options arguments' => [$field_def->id],
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_in_operator',
          'options callback' => 'zendesk_get_options_from_field',
          'options arguments' => [$field_def->id],
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ];

      break;
    case 'text':
      $table['value'] = [
        'title' => t($field_def->title),
        'help' => t($field_def->description) ?: t($field_def->title),
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
      ];

      // Some text fields are used for URLs.
      if (stripos($field_def->title, 'URL') !== FALSE) {
        $table['value']['field']['handler'] = 'views_handler_field_url';
      }

      break;
    case 'integer':
      $table['value'] = [
        'title' => t($field_def->title),
        'help' => t($field_def->description) ?: t($field_def->title),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_numeric',
        ),
        'argument' => array(
          'handler' => 'views_handler_argument_numeric',
        ),
      ];

      break;
    default:
      // By default we do nothing. This leaves us with a joined table that is
      // inaccessible as no columns are defined, so it is meaningless.
  }

  return $table;
}

