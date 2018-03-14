//
// Created by nadya on 26.10.16.
//


#include <cstdio>
#include <iostream>
#include <fstream>
#include "work_with_tree.h"

int read_table_from_code_file(double* freq_table, std::ifstream& input_str)//FILE* input)
{
  input_str.read(reinterpret_cast<char*>(freq_table), sizeof(double)*NUMBER_OF_CHARS);
  return sizeof(double)*NUMBER_OF_CHARS;
}


void decode_file(const char* code_input_name, const char* decode_output_name, int& input_size,
                 int& output_size, int& help_size)
{
  std::ifstream input_str(code_input_name);
  std::ofstream output_str(decode_output_name);

  int size_input = 0;
  int amount_table = 0;
  int size_output = 0;
  double freq_table[NUMBER_OF_CHARS] = {};

  amount_table = read_table_from_code_file(freq_table, input_str);
  size_input = amount_table;

  tree_node* tree = get_tree_by_freq(freq_table);
  tree_node* current = tree;


  short buffer = 0;
  size_t size = 0;

  bool get_eof = false;
  while ((input_str.good()))
  {
    input_str.read(reinterpret_cast<char*>(&buffer), 1);
    if ((input_str.gcount() == 1)&&(!get_eof))
    {
      ++size_input;
      size = 8;
      while (size > 0)
      {
        if ((buffer & 128) == 0)
          current = current->left_child;
        else
          current = current->right_child;
        size--;
        buffer = (buffer << 1);

        if (current->left_child == NULL)
        {
          if (current->character != NUMBER_OF_CHARS - 1)
          {
            char c = static_cast<char>(current->character);
            output_str.write(&c, 1);
            current = tree;
            ++size_output;
          } else
          {
            size = 0;
            get_eof = true;
          }
        }

      }
    }
  }

  input_size = size_input;
  output_size = size_output;
  help_size = amount_table;
  
  delete tree;
  return;
}
