#include <iostream>
#include <fstream>
#include <cstring>
#include "brainf.h"
#include "lang.h"
#include "config.h"


int main(int argc, char* argv[])
{
	
	char* input_file = nullptr;
	char* output_file = nullptr;
	bool debug = false;
	bool compile = false;
	
	for (int i = 1; i < argc; ++i)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '-')
			{
				if (strcmp(argv[i], "--help") == 0)
				{
					std::cout << str_help;
				} else
				if (strcmp(argv[i], "--version") == 0)
				{
					std::cout << str_version;
				}
			}
			else
			{
			
			for (int j = 1; argv[i][j] != 0; ++j)
			{
				switch (argv[i][j])
				{
				case 'o':
					if (output_file != nullptr)
					{
						std::cout << error_too_many_output;
						return 1;
					}
					if (i + 1 >= argc)
					{
						std::cout << error_no_output;
						return 1;
					}
					output_file = argv[++i];
					break;
				case 'd':
					debug = true;
					break;
				case 'h':
					std::cout << str_help;
					return 0;
				case 'v':
					std::cout << version << str_version;
					return 0;
				case 'c':
					compile = true;
					break;
				}
			}
			}
			
		}
		else if (input_file == nullptr)
		{
			input_file = argv[i];
		}
		else
		{
			std::cout << error_too_many_params;
			return 1;
		}
	}

	if (debug)
	{
		std::cout << warn_debug;
	}

	if (input_file == nullptr)
	{
		std::cout << error_no_input << str_help;
		return 1;
	}
	if (output_file == nullptr)
	{
		output_file = new char[strlen(input_file) + 3];
		strcpy(output_file, input_file);
		strcat(output_file, ".c");
	}

	int out = transpile(input_file, output_file);
	if (out == 0)
	{
		std::cout << str_trans_success;
		if (compile)
		{
			char* input_file_o = new char[strlen(input_file) + 4];
			strcpy(input_file_o, input_file);
			strcat(input_file_o, ".out");

			// kill me pls
			char* compile_command = new char[strlen(output_file) + strlen(compiler) + strlen(input_file_o) + strlen(compiler_flags) + 10];
			strcpy(compile_command, compiler);
			strcat(compile_command, " -o ");
			strcat(compile_command, input_file_o);
			strcat(compile_command, " ");
			strcat(compile_command, compiler_flags);
			strcat(compile_command, " ");
			strcat(compile_command, output_file);
			out = system(compile_command);
			if (out == 0)
				std::cout << str_comp_success;
			else
			{
				std::cout << str_comp_fail;
			}
		}
	}
	else
		std::cout << str_trans_fail;


	return out;
}