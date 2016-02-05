<?php
/**
 * @file
 * Describes plugin for example block content type.
 */

$plugin = array(
  'title' => t('Add CTools to your panel'),
  'description' => t('Add CTools with random 3 Views to your panel'),
  'single' => TRUE,
  'content_types' => array('no_context_content_type'),
  'render callback' => 'ctools_example_block_render',
  'defaults' => array(),

  'edit form' => 'ctools_example_block_edit_form',
  'category' => array(t('Add CTools to your panel'), -9),
);


function ctools_example_block_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = check_plain("");
  $block->content = views_embed_view($conf['view_name'], 'page');

  return $block;
}

function ctools_example_block_edit_form($form, &$form_state) {

  $conf = $form_state['conf'];

  $form['override_title']['#access'] = FALSE;
  $form['override_title_text']['#access'] = FALSE;
  $form['override_title_markup']['#access'] = FALSE;
  $form['override_title_heading']['#access'] = FALSE;


  $form['view_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter view machine name'),
    '#default_value' => $form_state['view_name'],
  );
  return $form;
}

function ctools_example_block_edit_form_submit($form, &$form_state) {
  if (isset($form_state['values']['view_name'])) {
    $form_state['conf']['view_name'] = $form_state['values']['view_name'];

  }
}
