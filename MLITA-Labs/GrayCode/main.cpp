#include "stdafx.h"

static std::string FILE_NAME = "input.txt";
static const auto N = 10;

int main(int argc, char * argv[])
{
	if (argc == 2)
		FILE_NAME = argv[1];


	std::fstream input(FILE_NAME);
	std::vector<bool> code;
	while (!input.eof())
	{
		int temp;
		input >> temp;
		code.push_back((temp != 0));
	}

	std::vector <int> stack;
	std::vector<bool> beginCode = code;
	for (size_t j = 0; j < N; ++j)
	{
		for (size_t i = 0; i < code.size(); ++i)
		{
			if (code[i])
			{
				stack.push_back(i);
			}
			beginCode[i] = false;
		}
		if (stack.size() % 2 == 0)
		{
			code[code.size() - 1] = !code[code.size() - 1];
		}
		else
		{
			if (stack[stack.size() - 1] == 0)
			{
				code = beginCode;
			}
			else
			{
				code[stack[stack.size() - 1] - 1] = !code[stack[stack.size() - 1] - 1];
			}
		}
		copy(code.begin(), code.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
		stack.clear();
	}
	return 0;
}

