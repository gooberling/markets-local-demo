<?php
/**
 * @file
 * cmc_search.features.inc
 */

/**
 * Implements hook_default_search_api_index().
 */
function cmc_search_default_search_api_index() {
  $items = array();
  $items['sitewide'] = entity_import('search_api_index', '{
    "name" : "sitewide",
    "machine_name" : "sitewide",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "nid" : { "type" : "integer" },
        "vid" : { "type" : "integer" },
        "type" : { "type" : "string" },
        "title" : { "type" : "text" },
        "language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "comment_count" : { "type" : "integer" },
        "comment_count_new" : { "type" : "integer" },
        "field_instrument_code" : { "type" : "text" },
        "field_background" : { "type" : "text" },
        "field_influencing_factors" : { "type" : "text" },
        "field_currency" : { "type" : "text" },
        "field_country" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_region" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_sector" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_instrument_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_max_order_size_cfd_aud" : { "type" : "decimal" },
        "field_max_order_size_cfd_eur" : { "type" : "decimal" },
        "field_max_order_size_cfd_gbp" : { "type" : "decimal" },
        "field_max_order_size_cfd_sgd" : { "type" : "decimal" },
        "field_max_order_size_cfd_unit" : { "type" : "decimal" },
        "field_max_order_size_sb_eur" : { "type" : "decimal" },
        "field_max_order_size_sb_gbp" : { "type" : "decimal" },
        "field_max_financing_cfd" : { "type" : "decimal" },
        "field_max_financing_cfd_sg" : { "type" : "decimal" },
        "field_max_financing_sb" : { "type" : "decimal" },
        "field_is_shorting_cfd" : { "type" : "integer" },
        "field_is_shorting_sb" : { "type" : "integer" },
        "field_is_tradable_sb" : { "type" : "integer" },
        "field_is_tradable_cfd" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "search_api_access_node" : { "type" : "list\\u003cstring\\u003e" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_instrument_code" : true,
              "field_background" : true,
              "field_influencing_factors" : true,
              "field_currency" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_instrument_code" : true,
              "field_background" : true,
              "field_influencing_factors" : true,
              "field_currency" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_instrument_code" : true,
              "field_background" : true,
              "field_influencing_factors" : true,
              "field_currency" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}^\']",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_instrument_code" : true,
              "field_background" : true,
              "field_influencing_factors" : true,
              "field_currency" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
