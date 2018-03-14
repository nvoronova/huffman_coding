//
// Created by nadya on 21.10.16.
//

#include "list_node.h"

list_node::list_node(list_node *new_left, list_node *new_right, double new_freq, tree_node *new_subtree)
        : frequency(new_freq)
        , subtree(new_subtree)
        , left(new_left)
        , right(new_right)
{
}

list_node::~list_node()
{
}

