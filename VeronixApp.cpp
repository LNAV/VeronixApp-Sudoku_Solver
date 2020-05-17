/*
 * VeronixApp.cpp
 *
 *  Created on: May 18, 2019
 *      Author: LavishK1
 */

#include <SudokuConsoleViewController.h>
#include "VeronixApp.h"
#include "AppDefines.h"
#include "APP/GridSolver.h"
#include "APP/Helper/InputHelper.h"

namespace Veronix
{
namespace App
{

VeronixApp::VeronixApp()
{
	DEF_COUT( "VeronixApp::VeronixApp" );

}

VeronixApp::~VeronixApp()
{
	DEF_COUT( "VeronixApp::~VeronixApp" );
}

void VeronixApp::start()
{
	DEF_COUT( "This is a Start" );
	try
	{
		helper::InputHelper inputProcessor;
		const Array::TabularArray<int> & gridValues = inputProcessor.getSudokuGridData(/*helper::console_read*/);

		sudosolver::container::GridContainer gridContainer(gridValues);
		viewcontroller::SudokuViewController sudokuView(gridContainer);

		DEF_COUT( "Before Solving Sudoku: " );
		sudokuView.displaySudoku();

		sudosolver::GridSolver gridSolver(gridContainer);
		gridSolver.solveGrid();

		DEF_COUT( "After Solving Sudoku: " );
		sudokuView.displaySudoku();

	}
	catch (const std::string e)
	{
		DEF_COUT( "Exception Thrown" << e );
	}
	catch (const char * e)
	{
		DEF_COUT( "Exception Thrown int *: " << e );
	}
	catch (...)
	{
		DEF_COUT("Exception is thrown somewhere");
	}

	DEF_COUT( "Start Ended Here" );
}

} /* namespace App */
} /* namespace Veronix */
