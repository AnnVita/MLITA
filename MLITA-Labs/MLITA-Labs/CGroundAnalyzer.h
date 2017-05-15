#pragma once
#include "stdafx.h"


class CGroundAnalyzer
{
public:
	CGroundAnalyzer();
	size_t GetBedsNum();
	void Print() const;


private:
	void CheckNearPlaces(size_t i, size_t j);

	std::vector<std::vector<bool>> m_groundArray;
	size_t m_rows;
	size_t m_colomns;
	size_t m_bedsNum = 0;
};