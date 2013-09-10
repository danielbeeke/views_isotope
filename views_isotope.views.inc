<?php

/**
 * Implements hook_views_plugins().
 */
function views_isotope_views_plugins() {
  $plugins = array(
    'style' => array(
      // Default settings for all style plugins.
      'views_isotope' => array(
        'title' => t('Isotope'),
        'help' => t('Uses isotope.'),
        'handler' => 'views_plugin_style_views_isotope',
        'theme' => 'views_isotope',
        'uses row plugin' => TRUE,
        'uses row class' => TRUE,
        'uses grouping' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'help topic' => 'style-unformatted',
      ),
    ),
  );

  return $plugins;
}

/**
 * @file
 * Contains the default style plugin.
 */

/**
 * Default style plugin to render rows one after another with no
 * decorations.
 *
 * @ingroup views_style_plugins
 */
class views_plugin_style_views_isotope extends views_plugin_style_default {
  function init(&$view, &$display, $options = NULL) {
    parent::init($view, $display, $options);

    if (isset($view->dom_id)) {
      drupal_add_js(array('views_isotope' => array('views' => array('view-dom-id-' . $view->dom_id))), 'setting');
      drupal_add_js(drupal_get_path('module', 'views_isotope') . '/js/views_isotope.js');
      drupal_add_js(libraries_get_path('isotope') . '/jquery.isotope.js');
      drupal_add_css(libraries_get_path('isotope') . '/css/style.css', CSS_SYSTEM);
      drupal_add_css(drupal_get_path('module', 'views_isotope') . '/css/views_isotope.css');
    }
  }
}
