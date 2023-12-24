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

	output_s += "#include <stdio.h>\n#define A putchar(*p);\n#define B *p=getchar();\n#define C if(p<a+30000) ++p; else p=a;\n#define D if(p>a) --p; else p=a+30000;\n#define E ++*p;\n#define F --*p;\n#define G while(*p)\nint main(){char a[30000];char*p=a;";
	while (input.get(c))
	{
		switch (c)
		{
		case '>':
			output_s += "C ";
			break;
		case '<':
			output_s += "D ";
			break;
		case '+':
			output_s += "E ";
			break;
		case '-':
			output_s += "F ";
			break;
		case '.':
			output_s += "A ";
			break;
		case ',':
			output_s += "B ";
			break;
		case '[':
			output_s += "G{";
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