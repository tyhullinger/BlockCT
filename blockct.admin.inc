<?php
/**
 * @file
 * Administration page for blockct.
 */

/**
 * Menu callback to configure general settings for blockct.
 */
function blockct_settings() {
  $form = array();

  $blockct_data = _blockct_get_style_data();
  $default_theme = variable_get('theme_default', 'bartik');
  $blockct_styles = '';
  if (array_key_exists('styles', $blockct_data)) {
    $blockct_styles = $blockct_data['styles'];
  }

  // a fieldset to wrap the settings in
  $form['blockct'] = array(
    '#type' => 'fieldset',
    '#title' => t('Theme specific styles block styles'),
    '#description' => t('Current theme is set to <strong>' . $default_theme . '</strong>'),
  );

  // text area that accepts the styles to display to the user for the current
  // theme.
  $form['blockct']['style_settings'] = array(
    '#type' => 'textarea',
    '#description' => t('Enter each block style setting on its own line in the value|display format.'),
    '#default_value' => $blockct_styles,
  );

  // Don't use system_settings_form because we want
  // to have a warning screen when clearing configuration.
  $form['buttons']['submit'] = array(
    '#value' => t('Save configuration'),
    '#type' => 'submit',
    '#submit' => array('blockct_settings_save')
  );
  return $form;
}

/**
 * Submit callback: save settings.
 */
function blockct_settings_save($form, &$form_state) {
  _blockct_insert_or_update_settings($form_state['input']['style_settings']);
  drupal_set_message(t('The configuration options have been saved.'));
  cache_clear_all();
}

/**
 * Helper function to insert or update the style settings in the db.
 */
function _blockct_insert_or_update_settings($styles) {
  // check if the blockct record already has data
  $default_theme = variable_get('theme_default', 'bartik');
  $data = _blockct_get_style_data();
  if(sizeof($data) > 0) {
    // we update the db
    db_update('blockct_styles')
      ->fields(array('styles' => $styles))
      ->condition('theme', $default_theme, '=')
      ->execute();
  }
  else {
    // insert new record
    db_insert('blockct_styles')
      ->fields(array('theme' => $default_theme, 'styles' => $styles))
      ->execute();
  }
}
