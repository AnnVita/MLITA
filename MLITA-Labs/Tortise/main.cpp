#include "stdafx.h"
#include "CTortoise.h"

int main()
{
	CTortoise tortoise(std::cin);
	tortoise.FindPath();
	tortoise.PrintInfo(std::cout);
	return 0;
}

