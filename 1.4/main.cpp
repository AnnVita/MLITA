#include "stdafx.h"
#include "CGroundAnalyzer.h"

int main()
{
	CGroundAnalyzer groundAnalyzer;
	std::ofstream output(OSTREAM_FILE_NAME);
	output << groundAnalyzer.GetWallsNum() << std::endl;
	return 0;
}

