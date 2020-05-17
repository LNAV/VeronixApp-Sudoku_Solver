/*
 * SudokuView.cpp
 *
 *  Created on: Dec 31, 2constants::valueZero19
 *      Author: LavishK1
 */

#include <SudokuConsoleView.h>
#include "AppDefines.h"

namespace Veronix
{
namespace App
{
namespace view
{

SudokuConsoleView::SudokuConsoleView() : sudokuVals(constants::squareSize, constants::squareSize)
{

}

SudokuConsoleView::~SudokuConsoleView()
{

}

bool SudokuConsoleView::updateSudokuView(int row, int col, int value)
{
	if (row < constants::valueZero || row > constants::squareSize || col < constants::valueZero || col > constants::squareSize)
		return false;

	sudokuVals[row][col] = value;
	return true;
}

void SudokuConsoleView::displayView()
{
	for (int row = constants::valueZero; row < constants::squareSize; ++row)
	{
		if (row % constants::boxSize == constants::valueZero)
			std::cout << std::endl;
		for (int col = constants::valueZero; col < constants::squareSize; ++col)
		{
			if (col % constants::boxSize == constants::valueZero)
				std::cout << " ";
			std::cout << sudokuVals[row][col] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl;
}


} /* namespace view */
} /* namespace App */
} /* namespace Veronix */
