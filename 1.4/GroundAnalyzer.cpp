#include "stdafx.h"
#include "CGroundAnalyzer.h"

CGroundAnalyzer::CGroundAnalyzer()
{
	std::ifstream input(FILE_NAME);
	input >> m_rows;
	input >> m_colomns;
	m_groundArray.resize(m_rows);
	for (size_t i = 0; i < m_rows; ++i)
	{
		for (size_t j = 0; j < m_colomns; ++j)
		{
			char temp;
			input >> temp;
			m_groundArray[i].push_back(temp == '1');
		}
	}
}

size_t CGroundAnalyzer::GetWallsNum()
{
	for (size_t i = 0; i < m_rows; ++i)
	{
		for (size_t j = 0; j < m_colomns; ++j)
		{
			if (m_groundArray[i][j])
			{
				CheckNearPlaces(i, j);
			}
		}
	}
	return m_wallNum;
}

void CGroundAnalyzer::CheckNearPlaces(size_t i, size_t j)
{
	if (i == 0 || j == 0)
	{
		m_wallNum += 1;
	}
	if (i > 0)
	{
		if (!m_groundArray[i - 1][j])
		{
			m_wallNum += 1;
		}
	}
	if (i < m_rows)
	{
		if (!m_groundArray[i + 1][j])
		{
			m_wallNum += 1;
		}
	}
	if (j > 0)
	{
		if (!m_groundArray[i][j - 1])
		{
			m_wallNum += 1;
		}
	}
	if (j < m_colomns)
	{
		if (!m_groundArray[i][j + 1])
		{
			m_wallNum += 1;
		}
	}
}

void CGroundAnalyzer::Print() const
{
	for (size_t i = 0; i < m_rows; ++i)
	{
		for (size_t j = 0; j < m_colomns; ++j)
		{
			std::cout << m_groundArray[i][j] << " ";
		}
		std::cout << std::endl;
	}
}