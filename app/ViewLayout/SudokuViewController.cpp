/*
 * SudokuViewController.cpp
 *
 *  Created on: Dec 31, 2019
 *      Author: LavishK1
 */

#include <SudokuConsoleViewController.h>
#include "AppDefines.h"

namespace Veronix
{
namespace App
{
namespace viewcontroller
{

SudokuViewController::SudokuViewController(const sudosolver::container::GridContainer &gridContainer) : gridContainer(gridContainer)
{

}

SudokuViewController::~SudokuViewController()
{

}

bool SudokuViewController::displaySudoku()
{
	displaySudokuFromConatiner(gridContainer.getRowContainer());
}

bool SudokuViewController::displaySudokuFromConatiner(const sudosolver::container::TableContainer &container)
{
	for (int row = constants::valueZero; row < constants::squareSize; ++row)
		for (int col = constants::valueZero; col < constants::squareSize; ++col)
			consoleView.updateSudokuView(row,col, *container[row][col]);

	consoleView.displayView();
//	consoleView.clear();
}

} /* namespace viewcontroller */
} /* namespace App */
} /* namespace Veronix */
