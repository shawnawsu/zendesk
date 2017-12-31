<?php

/**
 * @file
 * Definition of views_handler_relationship_link_reverse.
 */

/**
 * A relationship handler which looks up generic base tables via a secondary join.
 *
 * Based on views_handler_relationship_entity_reverse which assumes the base table
 * will be an entity with a specific entity reference field table as the link table.
 */
class views_handler_relationship_link_reverse extends views_handler_relationship {

  /**
   * Called to implement a relationship in a query.
   */
  function query() {
    dpm($this);
    $this->ensure_my_table();

    // First, relate our current table to the link table via the field
    $first = array(
      'left_table' => $this->table_alias,
      'left_field' => $this->field, // @TODO real_field?
      'table' => $this->definition['link table'],
      'field' => $this->definition['link field'],
    );

    if (!empty($this->options['required'])) {
      $first['type'] = 'INNER';
    }

    if (!empty($this->definition['link_join_extra'])) {
      $first['extra'] = $this->definition['link_join_extra'];
    }

    if (!empty($this->definition['join_handler']) && class_exists($this->definition['join_handler'])) {
      $first_join = new $this->definition['join_handler'];
    }
    else {
      $first_join = new views_join();
    }
    $first_join->definition = $first;
    $first_join->construct();
    $first_join->adjusted = TRUE;

    $this->first_alias = $this->query->add_table($this->definition['link table'], $this->relationship, $first_join);

    // Second, relate the link table to the entity specified using
    // the specified base fields on the base and link tables.
    $second = array(
      'left_table' => $this->first_alias,
      'left_field' => $this->definition['base link field'],
      'table' => $this->definition['base'],
      'field' => $this->definition['base field'],
    );

    if (!empty($this->options['required'])) {
      $second['type'] = 'INNER';
    }

    if (!empty($this->definition['base_join_extra'])) {
      $second['extra'] = $this->definition['base_join_extra'];
    }

    if (!empty($this->definition['join_handler']) && class_exists($this->definition['join_handler'])) {
      $second_join = new $this->definition['join_handler'];
    }
    else {
      $second_join = new views_join();
    }
    $second_join->definition = $second;
    $second_join->construct();
    $second_join->adjusted = TRUE;

    // use a short alias for this:
    // @TODO real_field?
    $alias = $this->field . '_' . $this->definition['base'];

    $this->alias = $this->query->add_relationship($alias, $second_join, $this->definition['base'], $this->relationship);
  }
}

