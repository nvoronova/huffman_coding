//
// Created by nadya on 21.10.16.
//

#include "tree_node.h"

tree_node::tree_node(tree_node *new_left_child, tree_node *new_right_child)
        : left_child(new_left_child)
        , right_child(new_right_child)
        , parent(NULL)
        , frequency(0.0)
        , character(0)
        , code("")
{
  if (left_child != NULL)
    left_child->parent = this;
  if (right_child != NULL)
    right_child->parent = this;
}
tree_node::~tree_node()
{
  if (left_child != NULL)
    delete left_child;
  if (right_child != NULL)
    delete right_child;
}
