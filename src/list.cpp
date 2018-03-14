//
// Created by nadya on 21.10.16.
//

#include "list.h"

list::list()
        : head(NULL)
        , tail(NULL)
        , size(0)
{
}


list::list(list_node *first)
        : head(first)
        , tail(first)
        , size(1)
{
}

void list::push_back(list_node *new_node)
{
  if (size == 0)
  {
    ++size;
    head = new_node;
    tail = new_node;
    return;
  }
  size++;
  tail->right = new_node;
  new_node->left = tail;
  tail = new_node;
  return;
}

list_node* list::pop_min()
{
  list_node *current = head;
  list_node *min = head;
  while (current != NULL)
  {
    if (current->frequency < min->frequency)
      min = current;
    current = current->right;
  }
  if (min == head)
  {
    head = min->right;
    if (min->right != NULL)
      min->right->left = NULL;
    --size;
    return min;
  }
  if (min == tail)
  {
    tail = min->left;
    if (min->left != NULL)
      min->left->right = NULL;
    --size;
    return min;
  }
  min->left->right = min->right;
  min->right->left = min->left;
  size--;
  return min;
}

list::~list()
{
  list_node *current = head;
  while (current != NULL)
  {
    list_node *tmp = current->right;
    delete current;
    current = tmp;
  }
}
