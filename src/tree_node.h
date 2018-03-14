//
// Created by nadya on 21.10.16.
//

#ifndef HUFFMAN_TREE_NODE_H
#define HUFFMAN_TREE_NODE_H

#include <string>
struct tree_node
{
  tree_node *left_child;
  tree_node *right_child;
  tree_node *parent;
  double frequency;
  int character;
  std::string code;

  tree_node(tree_node *new_left_child, tree_node *new_right_child);

  ~tree_node();
};


#endif //HUFFMAN_TREE_NODE_H
