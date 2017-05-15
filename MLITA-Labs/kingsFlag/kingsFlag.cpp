#include "stdafx.h"
static std::string FILE_NAME = "input.txt";

int main(int argc, char * argv[])
{
	if (argc == 2)
		FILE_NAME = argv[1];
	
	std::ifstream input(FILE_NAME);
	size_t gamesNum;
	std::pair<size_t, size_t> flagCoordinates = {1, 1};
	std::pair<size_t, size_t> beginCoordinates;
	double distance;
	input >> gamesNum;

	for (size_t i = 0; i < gamesNum; ++i)
	{
		input >> beginCoordinates.first;
		input >> beginCoordinates.second;
		distance = ((sqrt(beginCoordinates.first * beginCoordinates.first + beginCoordinates.second * beginCoordinates.second)));
		//distance = 
		//size_t result = ((distance / 2 + 1) % 2 == 0) ? 2 : 1;
		std::cout << std::round(distance) << std::endl;
	}
    return 0;
}