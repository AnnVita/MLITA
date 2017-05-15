#include "stdafx.h"
#include <vector>
#include <fstream>
#include <iostream>

typedef std::vector<std::vector<char>> Matrix;

namespace
{
	const std::string INPUT_FILE_NAME = "input.txt";
	const std::string OUTPUT_FILE_NAME = "output.txt";
}

static size_t width = 0;
static size_t height = 0;

void ReadData(Matrix& matrix);
int CalculatePerimeter(const Matrix& matrix);
void FillOutside(Matrix& matrix, size_t i, size_t j);
void PrintResult(int perimeter);

int main()
{
	try
	{
		Matrix matrix;
		ReadData(matrix);
		
		FillOutside(matrix, 0, 0);
		for (size_t row = 0; row < height + 2; ++row)
		{
			for (size_t col = 0; col < width + 2; ++col)
			{
				std::cout << matrix[row][col] << " ";
			}
			std::cout << std::endl;
		}
		PrintResult(CalculatePerimeter(matrix));
	}
	catch (const std::exception& err)
	{
		std::ofstream output(OUTPUT_FILE_NAME);
		output << err.what();
	}
	return EXIT_SUCCESS;
}

void ReadData(Matrix & matrix)
{
	std::ifstream input(INPUT_FILE_NAME);
	
	char value = 0;
	input >> height;
	input >> width;
	Matrix tmp(height + 2, std::vector<char>(width + 2, '0'));

	for (size_t row = 1; row < height + 1; ++row)
	{
		for (size_t col = 1; col < width + 1; ++col)
		{
			input >> value;
			tmp[row][col] = value;
		}
	}

	std::swap(matrix, tmp);
}

int CalculatePerimeter(const Matrix & matrix)
{
	int perimeter = 0;

	for (size_t row = 1; row < matrix.size(); ++row)
	{
		for (size_t col = 1; col < matrix[row].size(); ++col)
		{
			if ('1' == matrix[row][col])
			{
				int numberOfWalls = 0;
				if ('2' == matrix[row - 1][col]) //top
				{
					++numberOfWalls;
				}
				if ('2' == matrix[row][col + 1]) //right
				{
					++numberOfWalls;
				}
				if ('2' == matrix[row + 1][col]) //bottom
				{
					++numberOfWalls;
				}
				if ('2' == matrix[row][col - 1]) //left
				{
					++numberOfWalls;
				}
				perimeter += numberOfWalls;
			}
		}
	}

	return perimeter;
}

void FillOutside(Matrix & matrix, size_t i, size_t j)
{
	if ('0' == matrix[i][j])
	{
		matrix[i][j] = '2';
		if (i < matrix.size() - 1)
		{
			FillOutside(matrix, i + 1, j);
		}
		if (i > 0)
		{
			FillOutside(matrix, i - 1, j);
		}
		if (j < matrix[i].size() - 1)
		{
			FillOutside(matrix, i, j + 1);
		}
		if (j > 0)
		{
			FillOutside(matrix, i, j - 1);
		}
	}
}

void PrintResult(int perimeter)
{
	std::ofstream output(OUTPUT_FILE_NAME);
	output << perimeter;
}