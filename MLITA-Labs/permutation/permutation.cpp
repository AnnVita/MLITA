#include "stdafx.h"

static std::string FILE_NAME = "input.txt";


template<class It>
bool NextCombination(It first, It last);
void MakePermutations(std::vector<int> & numbers, std::vector<std::vector<int>> & result, size_t neesfulNumOfPermutations);


int main(int argc, char * argv[])
{
	if (argc == 2)
		FILE_NAME = argv[1];

	size_t num;
	size_t permutationsNum;
	std::vector<int> numbers;
	std::vector<std::vector<int>> result;


	std::ifstream input(FILE_NAME);
	input >> num;
	input >> permutationsNum;
	for (size_t i = 0; i < num; ++i)
	{
		int temp;
		input >> temp;
		numbers.push_back(temp);
	}

	MakePermutations(numbers, result, permutationsNum);

	for (int j = 0; j < result.size(); ++j)
	{
		copy(result[j].begin(), result[j].end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
	}

    return 0;
}

void MakePermutations(std::vector<int> & numbers, std::vector<std::vector<int>> & result, size_t neesfulNumOfPermutations)
{
	const size_t vectorSize = numbers.size();
	for (size_t i = 0; i < neesfulNumOfPermutations; i++)
	{
		if (NextCombination(numbers.begin(), numbers.end()))
		{
			result.push_back(numbers);
		}
	}
}


template<class It>
bool NextCombination(It first, It last)
{
	if (first == last) return false;
	
	auto ptrFromLast = last;
	if (first == --ptrFromLast) return false;
	

	while (true)
	{
		auto i1 = ptrFromLast;
		auto i2 = last;

		if (*--ptrFromLast < *i1)
		{
			i2 = last;
			while (!(*ptrFromLast < *--i2));
			std::iter_swap(ptrFromLast, i2);
			std::reverse(i1, last);
			return true;
		}

		if (ptrFromLast == first) 
		{
			std::reverse(first, last);
			return false;
		}
	}
}