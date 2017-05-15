#include "stdafx.h"
#include "CGroundAnalyzer.h"

CGroundAnalyzer::CGroundAnalyzer()
{
	std::ifstream input(FILE_NAME);
	input >> m_rows;
	input >> m_colomns;
	m_groundArray.resize(m_rows + 2);
	for (size_t i = 0; i < m_rows + 2; ++i)
	{
		m_groundArray[i].resize(m_colomns + 2);
		for (size_t j = 0; j < m_colomns + 2; ++j)
		{
			Cell tempCell;
			if (!((i == 0) || (j == 0) || (j == m_colomns + 1)))
			{
				char tempCh;
				if (input >> tempCh)
				{
					tempCell.value = (tempCh == '1');
				}
			}
			m_groundArray[i][j] = tempCell;
		}
	}
	MarkInsideCells(0, 0);
}

void CGroundAnalyzer::MarkInsideCells(size_t i, size_t j)
{
	if (!m_groundArray[i][j].value && m_groundArray[i][j].inside)
	{
		m_groundArray[i][j].inside = false;
		if (i > 0)
		{
			MarkInsideCells(i - 1, j);
		}
		if (j > 0)
		{
			MarkInsideCells(i, j - 1);
		}
		if (i < m_groundArray.size() - 1)
		{
			MarkInsideCells(i + 1, j);
		}
		if (j < m_groundArray[i].size() - 1)
		{
			MarkInsideCells(i, j + 1);
		}
	}

}

size_t CGroundAnalyzer::GetWallsNum()
{
	/*for (size_t i = 0; i < m_rows; ++i)
	{
		for (size_t j = 0; j < m_colomns; ++j)
		{
			if (m_groundArray[i][j].value)
			{
				CheckNearPlaces(i, j);
			}
		}
	}*/
	for (size_t i = 1; i < m_groundArray.size(); ++i)
	{
		for (size_t j = 1; j < m_groundArray[i].size(); ++j)
		{
			CheckNearPlaces(i, j);
		}
	}
	return m_wallNum;
}

void CGroundAnalyzer::CheckNearPlaces(size_t i, size_t j)
{
	if (m_groundArray[i][j].value)
	{
		m_wallNum += int(!m_groundArray[i][j - 1].inside) + int(!m_groundArray[i + 1][j].inside)
			+ int(!m_groundArray[i][j + 1].inside) + int(!m_groundArray[i - 1][j].inside);
	}
	/*
	if (i == 0)
	{
		m_wallNum += 1;
	}
	if (i == m_rows - 1)
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
	if (i < m_rows - 1)
	{
		if (!m_groundArray[i + 1][j])
		{
			m_wallNum += 1;
		}
	}
	if (j == 0)
	{
		m_wallNum += 1;
	}
	if (j == m_colomns - 1)
	{
		m_wallNum += 1;
	}
	if (j > 0)
	{
		if (!m_groundArray[i][j - 1])
		{
			m_wallNum += 1;
		}
	}
	if (j < m_colomns - 1)
	{
		if (!m_groundArray[i][j + 1])
		{
			m_wallNum += 1;
		}
	}
	*/
	
}