<?php


function lsa_api_services_resource() {
    $api = array(
        'languages' => array(
            'operations' => array(
                'index' => array(
                    'help' => 'Language Listing',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'lsa_api',
                        'name' => 'includes/lsa_language.services',
                    ),
                    'callback' => 'lsa_api_resource_retrieve',
                    'access arguments' => array('access content'),
                ),
            ),
        ),
        'lsa_search' => array(
            'operations' => array(
                'index' => array(
                    'help' => 'Search Listing',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'lsa_api',
                        'name' => 'includes/lsa_language.services',
                    ),
                    'callback' => 'lsa_api_search_resource_retrieve',
                    'access arguments' => array('access content'),
                ),
            ),
        ),
    );
    return $api;
}


function lsa_api_resource_retrieve()
{
    $lang = language_list();
    $languages = array();
    foreach ($lang as $key => $language){
        $languages[] = array('value' => $key, 'name' => $language->name);
    }
   return $languages;
}
function lsa_api_search_resource_retrieve()
{
    $data = array();
    $nodes = node_load_multiple($nids = array(), $conditions = array('status' => 1));
    foreach($nodes as $node):
        $data[] = array("nid"=>$node->nid, "title"=> $node->title, "description"=> text_summary($node->body['und'][0]['value'], $format=null, 100), "image"=> file_create_url($node->field_business_logo['und'][0]['uri']), "fb"=>$node->field_facebook_link['und'][0]['value'], "tw"=>$node->field_twitter_link['und'][0]['value'], "inst"=>$node->field_instagram_link['und'][0]['value'],"link"=>$node->field_linkedin_link['und'][0]['value'],"you"=>$node->field_youtube_link['und'][0]['value'],"sky"=>$node->field_skype_link['und'][0]['value']);
    endforeach;

    return $data    ;
}