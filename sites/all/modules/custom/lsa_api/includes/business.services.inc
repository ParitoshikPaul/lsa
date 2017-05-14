<?php


function lsa_api_business_services_resource() {
    $business = array(
        'business' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieve a Business',
                    'file' => array('type' => 'inc', 'module' => 'lsa_api', 'name' => 'includes/business.services'),
                    'callback' => 'lsa_api_business_resource_retrieve',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'tid',
                            'optional' => FALSE,
                            'source' => array('path' => 0),
                            'type' => 'int',
                            'description' => 'TID of business',
                        ),
                    ),
                ),
                ),
            ),
             'products' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieve a Business',
                    'file' => array('type' => 'inc', 'module' => 'lsa_api', 'name' => 'includes/business.services'),
                    'callback' => 'lsa_api_prod_resource_retrieve',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'nid',
                            'optional' => FALSE,
                            'source' => array('path' => 0),
                            'type' => 'int',
                            'description' => 'TID of business',
                        ),
                    ),
                ),
                ),
            ),
        'events' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieve a Business',
                    'file' => array('type' => 'inc', 'module' => 'lsa_api', 'name' => 'includes/business.services'),
                    'callback' => 'lsa_api_event_resource_retrieve',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'nid',
                            'optional' => FALSE,
                            'source' => array('path' => 0),
                            'type' => 'int',
                            'description' => 'TID of business',
                        ),
                    ),
                ),
                ),
            ),
        'feedback' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieve feedback of bussiness',
                    'file' => array('type' => 'inc', 'module' => 'lsa_api', 'name' => 'includes/business.services'),
                    'callback' => 'lsa_api_feedback_resource_retrieve',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'nid',
                            'optional' => FALSE,
                            'source' => array('path' => 0),
                            'type' => 'int',
                            'description' => 'NID of business',
                        ),
                    ),
                ),
            ),
        ),
        'sub_cat' => array(
            'operations' => array(
                'retrieve' => array(
                    'help' => 'Retrieve feedback of bussiness',
                    'file' => array('type' => 'inc', 'module' => 'lsa_api', 'name' => 'includes/business.services'),
                    'callback' => 'lsa_api_sub_cat_resource_retrieve',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'tid',
                            'optional' => FALSE,
                            'source' => array('path' => 0),
                            'type' => 'int',
                            'description' => 'NID of business',
                        ),
                    ),
                ),
            ),
        ),

        );
    return $business;
}


function lsa_api_business_resource_retrieve($tid)
{
       $data = array();
    $nodes = node_load_multiple($nids = array(), $conditions = array('status' => 1));
    foreach($nodes as $node):
        if($node->field_select_business_catergorie['und']):
            foreach($node->field_select_business_catergorie['und'] as $tid_buss):
                if($tid_buss['target_id'] == $tid):
                  $data[] = array("nid"=>$node->nid, "title"=> $node->title, "description"=> text_summary($node->body['und'][0]['value'], $format=null, 100), "image"=> file_create_url($node->field_business_logo['und'][0]['uri']), "fb"=>$node->field_facebook_link['und'][0]['value'], "tw"=>$node->field_twitter_link['und'][0]['value'], "inst"=>$node->field_instagram_link['und'][0]['value'],"link"=>$node->field_linkedin_link['und'][0]['value'],"you"=>$node->field_youtube_link['und'][0]['value'],"sky"=>$node->field_skype_link['und'][0]['value']);
                endif;
            endforeach;
        endif;
    endforeach;

    return $data;
}

function lsa_api_prod_resource_retrieve($nid)
{
    $data = array();
    $bussiness = node_load($nid);
    foreach($bussiness->field_choose_from_product_list['und'] as $products):
    $product = node_load($products['target_id']);
    $data[] = array("nid"=>$product->nid, "title"=> $product->title, "description"=> text_summary($product->body['und'][0]['value'], $format=null, 50), "image"=> file_create_url($product->field_business_logo['und'][0]['uri']), "price"=> $product->field_unit_price['und'][0]['value']);
             
    endforeach;
    return $data;
}

function lsa_api_event_resource_retrieve($nid)
{
    $data = array();
    $bussiness = node_load($nid);
    foreach($bussiness->field_choose_from_event_list['und'] as $events):
    $event = node_load($events['target_id']);
     $data[] = array("nid"=>$event->nid, "title"=> $event->title, "description"=> text_summary($event->body['und'][0]['value'], $format=null, 50), "image"=> file_create_url($event->field_business_logo['und'][0]['uri']));
            
    endforeach;
    return $data;
}

function lsa_api_feedback_resource_retrieve($nid)
{
    $node = node_load($nid);
    $count = $node->comment_count;
    $comments = comment_get_thread($node, $mode,10);
    foreach($comments as $comment):
        $comment_det = comment_load($comment);
        $data[] = array("name"=>$comment_det->field_name['und'][0]['value'], "rating"=> $comment_det->field_ratings['und'][0]['value'], "feedback"=> text_summary($comment_det->comment_body['und'][0]['value'], $format=null, 20), "title"=> $comment_det->subject, "count"=> $count, "email"=> $comment_det->field_email['und'][0]['value']);

    endforeach;
return $data;
}

function lsa_api_sub_cat_resource_retrieve($tid)
{
    $data = array();
    $taxonomies = taxonomy_get_children($tid);
    foreach($taxonomies as $taxonomy):
        $data[] = array("tid"=>$taxonomy->tid, "title"=>$taxonomy->name , "cat_icon"=> file_create_url($taxonomy->field_category_icon ['und'][0]['uri']));
    endforeach;

    return $data;
}
