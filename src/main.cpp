#include <iostream>
#include <string.h>
#include <getopt.h>
#include "coding.h"
#include "decoding.h"

int main(int argc, char* argv[])
{
  using namespace std;

  bool is_coding = false;
  bool is_decoding = false;
  bool is_input_file = false;
  bool is_output_file = false;
  char* input_filename;
  char* output_filename;

  const char* short_options = "cuf:o:";
  const struct option long_options[] =
          {
                  {"file",   required_argument, NULL, 'f'},
                  {"output", required_argument, NULL, 'o'},
                  {NULL, 0,                     NULL, 0}
          };


  int rez = 0;
  int option_index = -1;

  while ((rez = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1)
  {
    switch (rez)
    {
      case 'c':
      {
        is_coding = true;
        break;
      }
      case 'u':
      {
        is_decoding = true;
        break;
      }
      case 'f':
      {
        input_filename = optarg;
        is_input_file = true;
        break;
      }
      case 'o':
      {
        output_filename = optarg;
        is_output_file = true;
        break;
      }
      default:
      {
        cout << "Wrong format of parameters" << endl;
        return 0;
        break;
      }
    };
  };

  if ((is_coding)&&(is_decoding))
  {
    cout << "Wrong format of parameters -- can't do coding and decoding in one run" << endl;
    return 0;
  }

  if (!is_input_file)
  {
    cout << "Wrong format of parameters -- no input file" << endl;
    return 0;
  }

  if (!is_output_file)
  {
    cout << "Wrong format of parameters -- no output file" << endl;
    return 0;
  }

  int input_size = 0;
  int output_size = 0;
  int help_size = 0;

  if (is_decoding)
  {
    decode_file(input_filename, output_filename, input_size, output_size, help_size);
    cout << input_size << endl << output_size << endl << help_size << endl;
  }


  if (is_coding)
  {
    coding(input_filename, output_filename, input_size, output_size, help_size);
    cout << input_size << endl << output_size << endl << help_size << endl;
  }
  return 0;
}
