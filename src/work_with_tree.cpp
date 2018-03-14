//
// Created by nadya on 26.10.16.
//

#include "list_node.h"
#include "list.h"
#include "work_with_tree.h"

tree_node* get_tree_by_freq(double* table)
{
  list prior_q;
  for (size_t i = 0; i < NUMBER_OF_CHARS; ++i)
  {
    if (table[i] > 0)
    {
      tree_node* current_tree = new tree_node(NULL, NULL);
      current_tree->frequency = table[i];
      current_tree->character = i;
      list_node* current_node = new list_node(NULL, NULL, current_tree->frequency, current_tree);
      prior_q.push_back(current_node);
    }
  }

  list_node* first_min;
  list_node* second_min;
  while (prior_q.size > 1)
  {
    first_min = prior_q.pop_min();
    second_min = prior_q.pop_min();

    list_node* new_elem = new list_node(NULL, NULL, first_min->frequency + second_min->frequency, NULL);
    new_elem->subtree = new tree_node(first_min->subtree, second_min->subtree);

    prior_q.push_back(new_elem);
    delete first_min;
    delete second_min;
  }
  first_min = prior_q.pop_min();

  tree_node* result = first_min->subtree;
  delete first_min;
  return result;
}


void set_code_by_tree(tree_node* tree, std::string s)
{
  if (tree->left_child == NULL)
  {
    tree->code = s;
    return;
  }
  set_code_by_tree(tree->left_child, s + '0');
  set_code_by_tree(tree->right_child, s + '1');
  return;
}

void get_codes(tree_node* tree, std::string* codes)
{
  if (tree->left_child == NULL)
  {
    codes[tree->character] = tree->code;
    return;
  }
  get_codes(tree->left_child, codes);
  get_codes(tree->right_child, codes);
  return;

}
