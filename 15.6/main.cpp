#include "stdafx.h"

using namespace std;

int main()
{
	std::ifstream input(FILE_NAME);
	size_t numberOfCoins;
	input >> numberOfCoins;
	vector<vector<size_t>> S;
	size_t rowsNum = (numberOfCoins + 1) / 2;

	for (int i = 0; i <= numberOfCoins; ++i)
	{
		S.push_back({});
		for (int j = 0; j <= rowsNum; ++j)
		{
			if (i == 0 || j == 0)
			{
				S[i].push_back(0);
			}
			else if (i == 1 || i == 2)
			{
				S[i].push_back(i);
			}
			else
			{
				S[i].push_back(0);
				if (i <= 2 * j)
				{
					S[i][j] = i;
				}
				else
				{
					for (size_t k = 1; k <= 2 * j; ++k)
					{
						if (k <= i && k <= rowsNum)
						{
							if (S[i - k][k] == 0)
							{
								S[i][j] = k;
							}
						}
					}
				}
			}
		}
	}
	std::ofstream output(OSTREAM_FILE_NAME);

	size_t result = (S[numberOfCoins][1] > 0) ? 1 : 2;
	output << result << endl;

    return 0;
}

