#include "stdafx.h"

static std::string FILE_NAME = "input.txt";
struct Doctor
{
	bool found = false;
	size_t signsNum;
	std::vector<size_t> doctorSignsI;
};

static std::vector<Doctor> g_doctorsInfo;
static std::stack<size_t> g_stack;

void ProcessSort(size_t position = 0)
{
	if (!g_doctorsInfo[position].found)
	{
		g_doctorsInfo[position].found = true;
		for (size_t i = 0; i < g_doctorsInfo[position].doctorSignsI.size(); ++i)
		{
			ProcessSort(g_doctorsInfo[position].doctorSignsI[i]);
		}
		g_stack.push(position);
	}
}

int main(int argc, char * argv[])
{
	if (argc == 2)
		FILE_NAME = argv[1];

	std::ifstream input(FILE_NAME);
	size_t numOfDoctors;
	bool isValid = true;

	input >> numOfDoctors;
	for (size_t i = 0; i < numOfDoctors; ++i)
	{
		Doctor temp;
		input >> temp.signsNum;
		if (temp.signsNum == 0)
		{
			isValid = false;
		}
		for (size_t i = 0; i < temp.signsNum; ++i)
		{
			size_t tempSize;
			input >> tempSize;
			temp.doctorSignsI.push_back(tempSize - 1);
		}
		g_doctorsInfo.push_back(temp);
	}

	if (isValid)
	{
		std::cout << "YEP" << std::endl;
		for (size_t i = 0; i < numOfDoctors; ++i)
		{
			ProcessSort(i);
		}

		for (; !g_stack.empty();)
		{
			std::cout << g_stack.top() + 1 << std::endl;
			g_stack.pop();
		}
	}
	else
	{
		std::cout << "NOP" << std::endl;
	}


    return 0;
}

