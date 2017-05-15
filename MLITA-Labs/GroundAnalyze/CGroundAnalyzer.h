#pragma once
#include "stdafx.h"


class CGroundAnalyzer
{
public:
	CGroundAnalyzer();
	size_t GetWallsNum();

private:
	struct Cell 
	{
		bool value = false;
		bool inside = true;
	};

	void MarkInsideCells(size_t i = 0, size_t j = 0);
    void CheckNearPlaces(size_t i, size_t j);

	std::vector<std::vector<Cell>> m_groundArray;
	size_t m_rows;
	size_t m_colomns;
	size_t m_wallNum = 0;
};