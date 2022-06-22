<?php

/**
 * @file
 * complaints.features.inc
 */

/**
 * Implements hook_default_Workflow().
 */
function complaints_default_Workflow() {
  $workflows = array();

  // Exported workflow: 'workflow'
  $workflows['workflow'] = entity_import('Workflow', '{
    "name" : "workflow",
    "tab_roles" : { "-1" : "-1", "4" : "4", "3" : "3" },
    "options" : {
      "name_as_title" : "0",
      "fieldset" : "0",
      "options" : "radios",
      "schedule" : "1",
      "schedule_timezone" : "1",
      "comment_log_node" : "0",
      "comment_log_tab" : "0",
      "watchdog_log" : "1",
      "history_tab_show" : 1
    },
    "states" : {
      "(creation)" : {"weight":"-50","sysid":"1","state":"(creation)","status":"1","name":"(creation)"},
      "closed" : {"weight":"-46","sysid":"0","state":"closed","status":"1","name":"closed"},
      "in_progress" : {"weight":"-48","sysid":"0","state":"in progress","status":"1","name":"in_progress"},
      "open" : {"weight":"-49","sysid":"0","state":"open","status":"1","name":"open"},
      "rejected" : {"weight":"-47","sysid":"0","state":"rejected","status":"1","name":"rejected"}
    },
    "transitions" : {
      "_creation_to_closed" : {"roles":{"-1":-1,"4":4,"3":3},"name":"_creation_to_closed","label":"","rdf_mapping":[],"start_state":"(creation)","end_state":"closed"},
      "_creation_to_in_progress" : {"roles":{"-1":-1,"4":4,"3":3},"name":"_creation_to_in_progress","label":"","rdf_mapping":[],"start_state":"(creation)","end_state":"in_progress"},
      "_creation_to_open" : {"roles":{"-1":-1,"4":4,"3":3},"name":"_creation_to_open","label":"","rdf_mapping":[],"start_state":"(creation)","end_state":"open"},
      "_creation_to_rejected" : {"roles":{"-1":-1,"4":4,"3":3},"name":"_creation_to_rejected","label":"","rdf_mapping":[],"start_state":"(creation)","end_state":"rejected"},
      "closed_to_closed" : {"roles":{"-1":-1,"4":4,"3":3},"name":"closed_to_closed","label":"","rdf_mapping":[],"start_state":"closed","end_state":"closed"},
      "closed_to_in_progress" : {"roles":{"-1":-1,"4":4,"3":3},"name":"closed_to_in_progress","label":"","rdf_mapping":[],"start_state":"closed","end_state":"in_progress"},
      "closed_to_open" : {"roles":{"-1":-1,"4":4,"3":3},"name":"closed_to_open","label":"","rdf_mapping":[],"start_state":"closed","end_state":"open"},
      "closed_to_rejected" : {"roles":{"-1":-1,"4":4,"3":3},"name":"closed_to_rejected","label":"","rdf_mapping":[],"start_state":"closed","end_state":"rejected"},
      "in_progress_to_closed" : {"roles":{"-1":-1,"4":4,"3":3},"name":"in_progress_to_closed","label":"","rdf_mapping":[],"start_state":"in_progress","end_state":"closed"},
      "in_progress_to_in_progress" : {"roles":{"-1":-1,"4":4,"3":3},"name":"in_progress_to_in_progress","label":"","rdf_mapping":[],"start_state":"in_progress","end_state":"in_progress"},
      "in_progress_to_open" : {"roles":{"-1":-1,"4":4,"3":3},"name":"in_progress_to_open","label":"","rdf_mapping":[],"start_state":"in_progress","end_state":"open"},
      "in_progress_to_rejected" : {"roles":{"4":4,"3":3},"name":"in_progress_to_rejected","label":"","rdf_mapping":[],"start_state":"in_progress","end_state":"rejected"},
      "open_to_closed" : {"roles":{"4":4,"3":3},"name":"open_to_closed","label":"","rdf_mapping":[],"start_state":"open","end_state":"closed"},
      "open_to_in_progress" : {"roles":{"4":4,"3":3},"name":"open_to_in_progress","label":"","rdf_mapping":[],"start_state":"open","end_state":"in_progress"},
      "open_to_open" : {"roles":{"-1":-1,"4":4,"3":3},"name":"open_to_open","label":"","rdf_mapping":[],"start_state":"open","end_state":"open"},
      "open_to_rejected" : {"roles":{"-1":-1,"4":4,"3":3},"name":"open_to_rejected","label":"","rdf_mapping":[],"start_state":"open","end_state":"rejected"},
      "rejected_to_closed" : {"roles":{"-1":-1,"4":4,"3":3},"name":"rejected_to_closed","label":"","rdf_mapping":[],"start_state":"rejected","end_state":"closed"},
      "rejected_to_in_progress" : {"roles":{"-1":-1,"4":4,"3":3},"name":"rejected_to_in_progress","label":"","rdf_mapping":[],"start_state":"rejected","end_state":"in_progress"},
      "rejected_to_open" : {"roles":{"-1":-1,"4":4,"3":3},"name":"rejected_to_open","label":"","rdf_mapping":[],"start_state":"rejected","end_state":"open"},
      "rejected_to_rejected" : {"roles":{"-1":-1,"4":4,"3":3},"name":"rejected_to_rejected","label":"","rdf_mapping":[],"start_state":"rejected","end_state":"rejected"}
    },
    "label" : "workflow",
    "typeMap" : [ "complaints" ],
    "rdf_mapping" : [],
    "system_roles" : { "-1" : "(author)", "4" : "Manager", "3" : "administrator" }
  }');

  return $workflows;
}

/**
 * Implements hook_default_entityform_type().
 */
function complaints_default_entityform_type() {
  $items = array();
  $items['complaints'] = entity_import('entityform_type', '{
    "type" : "complaints",
    "label" : "complaints",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "filtered_html" },
      "submit_button_text" : "Send",
      "submit_confirm_msg" : "Transmission succeeded",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : "filtered_html" },
      "submission_show_submitted" : 0,
      "submissions_view" : "entityforms",
      "user_submissions_view" : "entityforms",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "1" : "1", "2" : "2", "5" : "5", "4" : "4", "3" : "3" },
      "resubmit_action" : "new",
      "redirect_path" : "\\u003Cfront\\u003E",
      "instruction_pre" : { "value" : "", "format" : "filtered_html" },
      "anonymous_links" : 0,
      "session_save" : 1
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/complaints",
        "alias" : "complaints",
        "language" : "und"
      }
    }
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function complaints_node_info() {
  $items = array(
    'complaints' => array(
      'name' => t('complaints'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('complaints'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
