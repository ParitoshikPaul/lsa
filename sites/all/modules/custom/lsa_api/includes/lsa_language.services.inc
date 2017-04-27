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

    );
    return $api;
}


function lsa_api_resource_retrieve()
{
    $lang = language_list();
    return $lang;
}