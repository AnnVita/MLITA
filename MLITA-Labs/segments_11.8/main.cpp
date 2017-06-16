#include "stdafx.h"

class CSegmentsAnalyze
{
public:
	CSegmentsAnalyze(std::string fileName = INPUT_NAME);
	void CountK();
	void ConfigureResult(std::string fileName = OUTPUT_NAME);
private:
	std::vector<std::pair<Point, Point>> m_segment;
	std::vector<double> m_K;
	std::vector<bool> m_isVertical;
};

CSegmentsAnalyze::CSegmentsAnalyze(std::string fileName)
{
	std::ifstream input(fileName);
	for (size_t i = 0; i < 2; i++)
	{
		m_segment.push_back({});
		input >> m_segment[i].first.first;
		input >> m_segment[i].first.second;
		input >> m_segment[i].second.first;
		input >> m_segment[i].second.second;
		if (m_segment[i].first.first > m_segment[i].second.first)
		{
			std::swap(m_segment[i].first, m_segment[i].second);
		}
		m_K.push_back(0.0);
		m_isVertical.push_back(false);
	}
}

void CSegmentsAnalyze::CountK()
{
	for (size_t i = 0; i < 2; i++)
	{
		if (m_segment[i].first.second == m_segment[i].second.second)
		{
			m_K[i] = 0;
		}
		else
		{
			if (m_segment[i].first.first == m_segment[i].second.first)
			{
				m_K[i] = 0;
				m_isVertical[i] = true;
			}
			else
			{
				m_K[i] = (double)(m_segment[i].second.second - m_segment[i].first.second) / (double)(m_segment[i].second.first - m_segment[i].first.first);
			}
		}
	}
	std::cout << m_K[0] << ' ' << m_K[1] << std::endl;

}

void CSegmentsAnalyze::ConfigureResult(std::string fileName)
{
	CountK();
	if (m_K[0] == m_K[1] && !m_isVertical[0] && !m_isVertical[1])
	{
		std::cout << NO;
	}
	else if (m_isVertical[0] || m_isVertical[1])
	{
		if (m_segment[0].first.first <= m_segment[1].second.first && m_segment[1].second.first <= m_segment[0].second.first ||
			m_segment[0].first.first <= m_segment[1].first.first && m_segment[1].first.first <= m_segment[0].second.first)
		{
			std::cout << YES;
		}
		else
		{
			std::cout << NO;
		}
	}
	else
	{
		double temp0 = 0;
		double temp1 = 0;
		if (!m_isVertical[0])
		{
			temp0 = m_segment[0].first.second - m_K[0] * m_segment[0].first.first;
		}
		if (!m_isVertical[1])
		{
			temp1 = m_segment[1].first.second - m_K[1] * m_segment[1].first.first;
		}
		double tempX = (temp1 - temp0) / (m_K[0] - m_K[1]);
		double tempY = m_K[0] * tempX + temp0;

		if ((tempX <= m_segment[0].second.first) && (tempX >= m_segment[0].first.first) && (tempX <= m_segment[1].second.first) && (tempX >= m_segment[1].first.first))
		{
			std::cout << YES;
		}
		else
		{
			std::cout << NO;
		}
	}
}

int main()
{
	CSegmentsAnalyze segmentAnalyze;
	segmentAnalyze.ConfigureResult();
    return 0;
}

