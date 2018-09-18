#include "stdafx.h"

size_t CountChainsQuantity(std::vector<Chain> & chain);
bool CompareByLength(Chain i, Chain j);
bool IsEqual(double x, double y);
bool HasNeedfulLength(Chain i);

static double newLength;

int main()
{
	size_t quantity;
	double length;
	size_t divider;
	size_t finalQuantity;

	std::ifstream input(INPUT_NAME);

	input >> quantity;
	input >> length;
	input >> divider;
	input >> finalQuantity;

	std::vector<Chain> chain;
	chain.push_back( {quantity, length} );

	size_t realFinalQuantity = CountChainsQuantity(chain);

	for (; realFinalQuantity < finalQuantity;)
	{
		size_t maxLengthChainIndex = std::max_element(chain.begin(), chain.end(), CompareByLength) - chain.begin();
		newLength = chain[maxLengthChainIndex].length / divider;
		auto it = std::find_if(chain.begin(), chain.end(), HasNeedfulLength);
		if (it != chain.end())
		{
			size_t index = it - chain.begin();
			chain[index].quantity += divider;
			--chain[maxLengthChainIndex].quantity;
			if (chain[maxLengthChainIndex].quantity == 0)
			{
				chain.erase(chain.begin() + maxLengthChainIndex);
			}
		}
		else
		{
			--chain[maxLengthChainIndex].quantity;
			chain.push_back( { divider, newLength} );
		}
		
		realFinalQuantity = CountChainsQuantity(chain);
	}

	FILE *output;
	output = fopen("output.txt", "w");
	if (realFinalQuantity == finalQuantity)
	{
		fprintf(output, "Yes\n");
		fprintf(output, "%.8f ", (*std::min_element(chain.begin(), chain.end(), CompareByLength)).length);
		fprintf(output, "%.8f", (*std::max_element(chain.begin(), chain.end(), CompareByLength)).length);
	}
	else
	{
		fprintf(output, "No\n");
	}

    return 0;
}

size_t CountChainsQuantity(std::vector<Chain> & chain)
{
	size_t result = 0;
	for (size_t i = 0; i < chain.size(); i++)
	{
		result += chain[i].quantity;
	}
	return result;
}

bool CompareByLength(Chain i, Chain j)
{
	return i.length < j.length;
}

bool IsEqual(double x, double y)
{
	return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}

bool HasNeedfulLength(Chain i)
{
	return ((i.length) == newLength);
}