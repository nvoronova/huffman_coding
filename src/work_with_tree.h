//
// Created by nadya on 26.10.16.
//

#ifndef HUFFMAN_WORK_WITH_TREE_H
#define HUFFMAN_WORK_WITH_TREE_H

#include "tree_node.h"

const int NUMBER_OF_CHARS = 257;

tree_node* get_tree_by_freq(double* table);

void set_code_by_tree(tree_node* tree, std::string s);

void get_codes(tree_node* tree, std::string* codes);

#endif //HUFFMAN_WORK_WITH_TREE_H
