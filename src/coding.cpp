//
// Created by nadya on 26.10.16.
//

#include <iostream>
#include <fstream>
#include "coding.h"
#include "tree_node.h"
#include "work_with_tree.h"

void table_to_code(double* table, std::string* codes)
{

  tree_node* tree = get_tree_by_freq(table);
  set_code_by_tree(tree, "");
  get_codes(tree, codes);

  delete tree;
  return;
}

void read_and_get_table(const char* s, double* table_freq, int& input_size)
{
  std::ifstream input_str(s);

  int table[NUMBER_OF_CHARS] = {};
  short buffer = 0;
  while (input_str.good())
  {
    input_str.read(reinterpret_cast<char*>(&buffer), 1);
    if (1 == input_str.gcount())
      ++table[buffer];
  }

  ++table[NUMBER_OF_CHARS - 1];
  int sum = 0;
  for (int i = 0; i < NUMBER_OF_CHARS; ++i)
    sum += table[i];

  input_size = sum - 1;
  for (int i = 0; i < NUMBER_OF_CHARS; ++i)
  {
    table_freq[i] = static_cast<double>(table[i]) / sum;
  }
  return;
}

int push_and_print_buffer(size_t* size_buf, short* buffer, std::string code, std::ofstream& output_str)
{
  int is_print = 0;
  char c;
  size_t i = 0;
  while (i < code.size())
  {
    c = code[i];
    *buffer = ((*buffer) << 1);
    *buffer = (*buffer | (c - '0'));
    ++(*size_buf);
    i++;
    if (*size_buf == 8)
    {
      output_str.write(reinterpret_cast<char*>(buffer), 1);
      *buffer = 0;
      *size_buf = 0;
      ++is_print;
    }
  }
  return is_print;
}
int write_freq_table_to_file(double* table, std::ofstream& output_str)
{
  output_str.write(reinterpret_cast<char*>(table), NUMBER_OF_CHARS*sizeof(double));
  return NUMBER_OF_CHARS*sizeof(double);
}

void write_arh_file(const char* input_file_name, const char* output_file_name, std::string* codes,
                    double* freq_table, int& output_size, int& help_size)
{
  std::ifstream input_str(input_file_name);
  std::ofstream output_str(output_file_name);

  int amount_table = write_freq_table_to_file(freq_table, output_str);
  int size_of_file = amount_table;

  short buffer_in = 0;
  short buffer_out = 0;
  size_t size_buf_out = 0;
  while (!input_str.eof())
  {
    input_str.read(reinterpret_cast<char*>(&buffer_in), 1);
    if (input_str.gcount() == 1)
      size_of_file += push_and_print_buffer(&size_buf_out, &buffer_out, codes[buffer_in], output_str);
  }

  size_of_file += push_and_print_buffer(&size_buf_out, &buffer_out, codes[NUMBER_OF_CHARS - 1], output_str);

  if (size_buf_out != 0)
  {
    std::string s(8 - size_buf_out, '0');
    size_of_file += push_and_print_buffer(&size_buf_out, &buffer_out, s, output_str);
  }

  output_size = size_of_file;
  help_size = amount_table;
}

void coding(const char* input_file_name, const char* output_file_name, int& input_size,
            int& output_size, int& help_size)
{
  double table[NUMBER_OF_CHARS];
  read_and_get_table(input_file_name, table, input_size);

  std::string codes[NUMBER_OF_CHARS];
  table_to_code(table, codes);

  write_arh_file(input_file_name, output_file_name, codes, table, output_size, help_size);

}
