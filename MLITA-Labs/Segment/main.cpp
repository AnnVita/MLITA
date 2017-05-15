#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

static std::string FILE_NAME = "input.txt";

using Segment = std::pair<int, int>;

bool Less(Segment first, Segment second)
{
	if (first.first == second.first)
	{
		return (first.second == 1);
	}
	return first.first < second.first;
}

class CSegmentAnalyze
{
public:
	CSegmentAnalyze();
	void Print() const;
	size_t GetMinExpertsNum();

private:
	std::vector<Segment> m_segmentsInfo;
	size_t m_experts;
	size_t m_segmentsNum;
};

CSegmentAnalyze::CSegmentAnalyze()
{
	std::ifstream input(FILE_NAME);
	input >> m_segmentsNum;
	input >> m_experts;
	for (size_t i = 0; i < m_segmentsNum; ++i)
	{
		int temp;
		input >> temp;
		m_segmentsInfo.push_back(std::make_pair(temp, 1));
		input >> temp;
		m_segmentsInfo.push_back(std::make_pair(temp, -1));
	}
	std::sort(m_segmentsInfo.begin(), m_segmentsInfo.end(), Less);
}

void CSegmentAnalyze::Print() const
{
	for (size_t i = 0; i < m_segmentsNum * 2; ++i)
	{
		std::cout << m_segmentsInfo[i].first << " " << m_segmentsInfo[i].second << std::endl;
	}
}

size_t CSegmentAnalyze::GetMinExpertsNum()
{
	size_t depth = 0;
	size_t result = 0;
	for (size_t i = 0; i < m_segmentsNum * 2; ++i)
	{
		depth += m_segmentsInfo[i].second;
		if (m_segmentsInfo[i].second == -1 && depth == m_experts - 1)
			++result;
	}
	return result;
}

int main(int argc, char * argv[])
{
	if (argc == 2)
		FILE_NAME = argv[1];
	CSegmentAnalyze segments;
	std::cout << segments.GetMinExpertsNum();
    return 0;
}

