#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#define MAX_NUM_OF_ARG 2

using namespace std;

bool CheckArgCount(int);
vector<int> ReadHeap(ifstream &);
vector<int> BuildFenwickTree(vector<int> &, size_t);
void Update(vector<int> &, int, int);
int Rsq(vector<int> &, int);
void PrintTree(vector<int> &);

int main(int argc, char * argv[])
{
	if (CheckArgCount(argc))
	{
		cout << "Invalid arguments count\n"
			<< "Usage: practice.exe <input file> \n";
		return EXIT_FAILURE;
	}

	ifstream input(argv[1]);

	auto heap = ReadHeap(input);
	auto fenwickTree = BuildFenwickTree(heap, heap.size());

	int tmp = 0;
	int i, j = 0;
	cout << "1) Add" << endl << "2) Rsq" << endl;
	while (cin >> tmp)
	{
		i, j = 0;
		switch (tmp)
		{
		case 1:
		{
			cout << "give me position and value: ";
			cin >> i >> j;
			Update(fenwickTree, i, j);
			PrintTree(fenwickTree);
			break;
		}
		case 2:
		{
			cout << "give me range values: ";
			cin >> i >> j;
			cout << Rsq(fenwickTree, j) - Rsq(fenwickTree, i - 1) << endl;
			break;
		}
		default:
			break;
		}
	}

	return EXIT_SUCCESS;
}

bool CheckArgCount(int argc)
{
	return (argc != MAX_NUM_OF_ARG);
}

vector<int> ReadHeap(ifstream & input)
{
	int tmp = 0;
	vector<int> result;

	input >> tmp;
	result.reserve(tmp + 1);
	while (!input.eof())
	{
		input >> tmp;
		result.push_back(tmp);
	}

	return result;
}

vector<int> BuildFenwickTree(vector<int> & heap, size_t n)
{
	vector<int> fenwickTree;
	for (size_t i = 0; i < n; i++)
	{
		fenwickTree.push_back(0);
	}

	for (size_t i = 0; i < n; i++)
	{
		Update(fenwickTree, i, heap[i]);
	}

	return fenwickTree;
}

void Update(vector<int> & fenwickTree, int i, int value)
{
	while (i < fenwickTree.size())
	{
		fenwickTree[i] += value;
		i = i | (i + 1);
	}
}

int Rsq(vector<int> & heap, int i)
{
	int result = 0;

	while (i >= 0)
	{
		result += heap[i];
		i = (i & (i + 1)) - 1;
	}

	return result;
}

void PrintTree(vector<int> & fenwickTree)
{
	for (size_t i = 0; i < fenwickTree.size(); ++i)
	{
		cout << fenwickTree[i] << '[' << i << ']' << endl;;
	}
}