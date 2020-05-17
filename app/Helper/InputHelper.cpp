/*
 * InputHelper.cpp
 *
 *  Created on: Dec 31, 2019
 *      Author: LavishK1
 */

#include "InputHelper.h"

#include "AppDefines.h"
#include <unordered_set>

namespace Veronix
{
namespace App
{
namespace helper
{

const int demoGridValues[constants::squareSize][constants::squareSize] =
{
		{0, 0, 3, 0, 2, 0, 6, 0, 0},
		{9, 0, 0, 3, 0, 5, 0, 0, 1},
		{0, 0, 1, 8, 0, 6, 4, 0, 0},
		{0, 0, 8, 1, 0, 2, 9, 0, 0},
		{7, 0, 0, 0, 0, 0, 0, 0, 8},
		{0, 0, 6, 7, 0, 8, 2, 0, 0},
		{0, 0, 2, 6, 0, 9, 5, 0, 0},
		{8, 0, 0, 2, 0, 3, 0, 0, 9},
		{0, 0, 5, 0, 1, 0, 3, 0, 0}
};

const std::unordered_set<char> nullSet = {'.', '-', '_', '*'};

InputHelper::InputHelper() : sudokuData(constants::squareSize, constants::squareSize)
{

}

InputHelper::~InputHelper()
{

}
int InputHelper::readValuesFromConsole(int row, int col)
{
	if (row < 0 || row >= constants::squareSize || col < 0 || col > constants::squareSize)
		throw "invalid row or col for input";


	char input;
	while (true)
	{
		std::cin >> input;
		if (input >= '0' && input <='9')
			break;

		if (nullSet.find(input) != nullSet.end())
		{
			input = '0';
			break;
		}
	}

	return input - '0';
}

int InputHelper::readValuesFromFile(int row, int col)
{
	if (row < 0 || row >= constants::squareSize || col < 0 || col > constants::squareSize)
		throw "invalid row or col for input";

	return 0;
}

int InputHelper::useDemoDataValues(int row, int col)
{
	if (row < 0 || row >= constants::squareSize || col < 0 || col > constants::squareSize)
		throw "invalid row or col for input";

	return demoGridValues[row][col];
}

const Array::TabularArray<int>& InputHelper::getSudokuGridData(InputFormat format)
{
	int (InputHelper::* read_func)(int, int) = nullptr;

	switch (format)
	{
	case console_read:
		DEF_COUT("Reading Values from console");
		read_func = readValuesFromConsole;
		break;

	case file_read:
		read_func = readValuesFromFile;
		break;

	case undefined:
	default:
		DEF_COUT("useing Demo-Data Values");
		read_func = useDemoDataValues;
		break;

	}

	for (int row = constants::valueZero; row < constants::squareSize; ++row)
		for (int col = constants::valueZero; col < constants::squareSize; ++col)
			sudokuData[row][col] = (this->*read_func)(row, col);

	return sudokuData;
}

} /* namespace helper */
} /* namespace App */
} /* namespace Veronix */
