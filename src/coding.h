//
// Created by nadya on 26.10.16.
//

#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

#include <string>

void table_to_code(double* table, std::string* codes);

void read_and_get_table(const char* s, double* table_freq, int& input_size);

int push_and_print_buffer(size_t* size_buf, short* buffer, std::string code, std::ofstream& output_str);

int write_freq_table_to_file(double* table, std::ofstream& output_str);

void write_arh_file(const char* input_file_name, const char* output_file_name, std::string* codes,
                    double* freq_table, int& output_size, int& help_size);

void coding(const char* input_file_name, const char* output_file_name,
            int& input_size, int& output_size, int& help_size);

#endif //HUFFMAN_CODING_H
