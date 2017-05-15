#pragma once

class CTortoise
{
public:
	CTortoise(std::istream & input);
	void FindPath();
	void PrintInfo(std::ostream & output);

private:

	void CountValue(std::pair<size_t, size_t> point);

	std::vector<std::vector<int>> m_groundArray;
	std::vector<std::pair<size_t, size_t>> m_path;

	size_t m_rows;
	size_t m_colomns;
	std::pair<size_t, size_t> m_endPoint;
};