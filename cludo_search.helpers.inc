<?php

/**
 * @file
 *    helper functions for the Cludo Searchmodule
 *
 * @see cludo_search_appliance.module
 */
/**
 * default module settings
 */
define('CS_DEFAULT_SEARCHURL', '');
define('CS_DEFAULT_CUSTOMERID', 'default_customerId');
define('CS_DEFAULT_ENGINEID', 'default_engineId');

/**
 * Minimize redundant trips to the db when looking for module settings.
 * Hooks that change module settings should run this function with
 * $refresh = TRUE so other hooks can just get settings without a db
 * query.
 *
 */
function _cludo_search_get_settings($refresh = FALSE) {

  $settings = &drupal_static(__FUNCTION__, NULL, $refresh);

  if (!isset($settings)) {
    $field_keys = array(
      'searchUrl',
      'customerId',
      'engineId',
    );

    // Settings fall back to default constants.
    foreach ($field_keys as $field) {
      $settings[$field] = variable_get(
          'cludo_search_' . $field, constant('CS_DEFAULT_' . strtoupper($field))
      );
    }
  }

  return $settings;
}
