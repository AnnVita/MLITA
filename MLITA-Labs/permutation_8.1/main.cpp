#include "stdafx.h"

template<class It>
bool NextCombination(It first, It last);

int main()
{
	std::string word;
	std::vector<std::vector<char>> permutation;
	std::vector<char> firstPer;

	std::ifstream input(INPUT_NAME);
	input >> word;
	std::sort(word.begin(), word.end());

	for (size_t i = 0; i < word.length(); i++)
	{
		firstPer.push_back(word[i]);
	}

	permutation.push_back(firstPer);

	for (;;)
	{
		
		int firtToReplacePosition = -1;
		int secondToReplacePosition = -1;
		for (int i = permutation.back().size() - 2; i >= 0; i--)
		{
			if (permutation.back()[i] < permutation.back()[i + 1])
			{
				firtToReplacePosition = i;
				break;
			}
		}
		if (firtToReplacePosition >= 0)
		{
			std::vector<char> newPermutation = permutation.back();
			if (NextCombination(newPermutation.begin(), newPermutation.end()))
			{
				permutation.push_back(newPermutation);
			}

		}
		else
		{
			break;
		}

	}
	std::ofstream output(OUTPUT_NAME);

	for (size_t i = 0; i < permutation.size(); i++)
	{
		for (size_t j = 0; j < permutation[i].size(); j++)
		{
			output << permutation[i][j];
		}
		output << std::endl;
	}

    return 0;
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