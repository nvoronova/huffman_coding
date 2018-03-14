//
// Created by nadya on 21.10.16.
//

#ifndef HUFFMAN_LIST_NODE_H
#define HUFFMAN_LIST_NODE_H

#include "tree_node.h"

struct list_node
{
  double frequency;
  tree_node *subtree;
  list_node *left;
  list_node *right;

  list_node(list_node *new_left, list_node *new_right, double new_freq, tree_node *new_subtree);

  ~list_node();
};

#endif //HUFFMAN_LIST_NODE_H
