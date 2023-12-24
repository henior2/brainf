#include "brainf.h"
#include "lang.h"

int transpile(char* input_file, char* output_file)
{
	std::ifstream input(input_file);
	std::ofstream output(output_file);
	std::string output_s;
	if (!input.is_open())
	{
		std::cout << error_cant_input;
		return 1;
	}
	if (!output.is_open())
	{
		std::cout << error_cant_output;
		return 1;
	}

	char c;
	int parentheses = 0;

	output_s += "#include <stdio.h>\nint main(){char a[30000];char*p=a;";
	while (input.get(c))
	{
		switch (c)
		{
		case '>':
			output_s += "if(p<a+30000) ++p; else p=a;";
			break;
		case '<':
			output_s += "if(p>a) --p; else p=a+30000;";
			break;
		case '+':
			output_s += "++*p;";
			break;
		case '-':
			output_s += "--*p;";
			break;
		case '.':
			output_s += "putchar(*p);";
			break;
		case ',':
			output_s += "*p=getchar();";
			break;
		case '[':
			output_s += "while(*p){";
			parentheses++;
			break;
		case ']':
			output_s += "}";
			if(--parentheses < 0)
			{
				std::cout << error_parentheses;
				return 1;
			}
			break;
		}
	}
	if(parentheses > 0)
	{
		std::cout << error_parentheses;
		return 1;
	}
	output_s += "return 0;}";
	output << output_s;
	input.close();
	output.close();
	return 0;
}