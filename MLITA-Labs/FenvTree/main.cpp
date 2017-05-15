#include "stdafx.h"

using namespace std;

static vector<int> fenvArray;
static size_t numbersNum;

void Add(int i, int d);
int Rsq(int i);

int main()
{
	ifstream input(FILE_NAME);
	input >> numbersNum;

	vector<int> intArray;

	for (size_t i = 0; i < numbersNum; ++i)
	{
		int temp;
		input >> temp;
		intArray.push_back(temp);
		fenvArray.push_back(0);
	}

	for (size_t i = 0; i < numbersNum; ++i)
	{
		Add(i, intArray[i]);
	}

	string userAnswer = "";

	while (userAnswer != "...")
	{
		cout << ">";
		cin >> userAnswer;
		if (userAnswer == "add")
		{
			int tempI;
			int tempD;
			cout << "enter i : ";
			cin >> tempI;
			cout << "enter D : ";
			cin >> tempD;
			Add(tempI, tempD);
		}
		else if (userAnswer == "rsq")
		{
			int tempI;
			int tempD;
			cout << "enter i : ";
			cin >> tempI;
			cout << "enter j : ";
			cin >> tempD;
			cout << "result = " << Rsq(tempD) - Rsq(tempI - 1) << endl;
		}
	}

    return 0;
}

void Add(int i, int d)
{
	/*
	while (i < numbersNum)
	{
		fenvArray[i] += d;
		i = i | (i + 1);
	}*/
	for (; i < numbersNum; i = (i | (i + 1)))
		fenvArray[i] += d;
}

int Rsq(int i)
{
	int result = 0;
	while (i >= 0)
	{
		result += fenvArray[i];
		i = (i & (i + 1)) - 1;
	}
	return result;
}
/*
int Rsq(int i, int j)
{
	int result = 0;
	while (i >= 0)
	{
		result += fenvArray[i];
		i = i & (i + 1) - 1;
	}
	return result;
}
*/