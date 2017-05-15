#include "stdafx.h"
#include "CTortoise.h"

CTortoise::CTortoise(std::istream & input)
{
	input >> m_rows;
	input >> m_colomns;
	m_groundArray.resize(m_rows);
	for (size_t i = 0; i < m_rows; ++i)
	{
		for (size_t j = 0; j < m_colomns; ++j)
		{
			int temp;
			input >> temp;
			m_groundArray[i].push_back(temp);
		}
	}
	m_endPoint = {m_rows - 1, m_colomns - 1};
}

void CTortoise::FindPath()
{
	for (int i = m_rows - 1; i >= 0; --i)
	{
		for (int j = m_colomns - 1; j >= 0; --j)
		{
			CountValue({i, j});
		}
	}

	std::pair<size_t, size_t> currPoint = m_endPoint;
	m_path.push_back(currPoint);
	while (currPoint != std::pair<size_t, size_t>{0, 0})
	{
		if (currPoint.first > 0 && currPoint.second > 0)
		{
			(m_groundArray[currPoint.first - 1][currPoint.second] < m_groundArray[currPoint.first][currPoint.second - 1]) ? --currPoint.first : --currPoint.second;
		}
		else
		{
			(currPoint.first == 0) ? --currPoint.second : --currPoint.first;
		}
		m_path.push_back(currPoint);
	}
}

void CTortoise::CountValue(std::pair<size_t, size_t> point)
{
	int right;
	int down;

	bool hasRightWay = (point.first + 1 < m_rows);
	bool hasDownWay = (point.second + 1 < m_colomns);
	
	if (hasRightWay && hasDownWay)
	{
		right = m_groundArray[point.first][point.second] + m_groundArray[point.first + 1][point.second];
		down = m_groundArray[point.first][point.second] + m_groundArray[point.first][point.second + 1];
		if (right < down)
		{
			m_groundArray[point.first][point.second] = right;
		}
		else
		{
			m_groundArray[point.first][point.second] = down;
		}
	}
	else if (hasRightWay)
	{
		m_groundArray[point.first][point.second] += m_groundArray[point.first + 1][point.second];
	}
	else if (hasDownWay)
	{
		m_groundArray[point.first][point.second] += m_groundArray[point.first][point.second + 1];
	}
}

void CTortoise::PrintInfo(std::ostream & output)
{
	output << m_groundArray[0][0] << std::endl;
	for (size_t i = m_path.size() - 1; i > 0; --i)
	{
		output << m_path[i].first + 1 << " " << m_path[i].second + 1 << std::endl;
	}
	output << m_path[0].first + 1 << " " << m_path[0].second + 1 << std::endl;
}
