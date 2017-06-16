#include "stdafx.h"

int main(int argc, char * argv[])
{
	if (argc == 2)
		FILE_NAME = argv[1];

	std::vector<std::pair<size_t, int>> numbers;
	std::ifstream input(FILE_NAME);
	size_t vectorSize;
	input >> vectorSize;
	numbers.resize(vectorSize);
	for (size_t i = 0; i < vectorSize; ++i)
	{
		numbers[i].first = i + 1;
		input >> numbers[i].second;
	}

	auto lessByFirst = [](std::pair<size_t, int> a, std::pair<size_t, int> b) {
		return a.first < b.first;
	};
	auto lessBySecond = [](std::pair<size_t, int> a, std::pair<size_t, int> b) {
		return abs(a.second) > abs(b.second);
	};
	std::sort(numbers.begin(), numbers.end(), lessBySecond);

	size_t minDifference = INT_MAX;
	std::pair<size_t, size_t> indexes;
	for (size_t i = 0; i < vectorSize - 1; ++i)
	{
		size_t abcDifference = abs(numbers[i + 1].second - numbers[i].second);
		if (abcDifference < minDifference)
		{
			minDifference = abcDifference;
			indexes.first = numbers[i].first;
			indexes.second = numbers[i + 1].first;
		}
	}

	//copy(numbers.begin(), numbers.begin(), std::ostream_iterator<int>(std::cout, " "));
	/*for (size_t i = 0; i < vectorSize; ++i)
	{
		std::cout << numbers[i].second << ' ';
	}*/
	std::cout << minDifference << std::endl;
	std::cout << indexes.second << ' ' << indexes.first;
    return 0;
}
