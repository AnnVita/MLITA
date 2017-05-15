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
			m_groundArray[i].push_back(temp == '#');
		}
	}
}

size_t CGroundAnalyzer::GetBedsNum()
{
	for (size_t i = 0; i < m_rows; ++i)
	{
		for (size_t j = 0; j < m_colomns; ++j)
		{
			if (m_groundArray[i][j])
			{
				CheckNearPlaces(i, j);
				++m_bedsNum;
			}
		}
	}
	return m_bedsNum;
}

void CGroundAnalyzer::CheckNearPlaces(size_t i, size_t j)
{
	if (((i < m_rows) && (j < m_colomns)) && m_groundArray[i][j])
	{
		m_groundArray[i][j] = false;
		CheckNearPlaces(i, j + 1);
		CheckNearPlaces(i + 1, j);
		CheckNearPlaces(i - 1, j);
		CheckNearPlaces(i, j - 1);
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