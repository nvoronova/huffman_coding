//
// Created by nadya on 26.10.16.
//

#ifndef HUFFMAN_DECODING_H
#define HUFFMAN_DECODING_H

#include <cstdio>
#include <fstream>

int read_table_from_code_file(double* freq_table, std::ifstream& input_str);

void decode_file(const char* code_input_name, const char* decode_output_name, int& input_size,
                 int& output_size, int& help_size);

#endif //HUFFMAN_DECODING_H
