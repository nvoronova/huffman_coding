//
// Created by nadya on 21.10.16.
//

#ifndef HUFFMAN_LIST_H
#define HUFFMAN_LIST_H

#include "list_node.h"

struct list
{
  list_node *head;
  list_node *tail;
  size_t size;

  list();

  list(list_node *first);

  void push_back(list_node *new_node);

  list_node *pop_min();

  ~list();

};


#endif //HUFFMAN_LIST_H
