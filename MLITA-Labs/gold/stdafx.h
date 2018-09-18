// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <tchar.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>

static std::string INPUT_NAME = "input.txt";
static std::string OUTPUT_NAME = "output.txt";

struct Chain
{
	size_t quantity;
	double length;
};


// TODO: reference additional headers your program requires here
