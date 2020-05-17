/*
 * SudokuViewController.h
 *
 *  Created on: Dec 31, 2019
 *      Author: LavishK1
 */

#ifndef APP_VIEWLAYOUT_SUDOKUCONSOLEVIEWCONTROLLER_H_
#define APP_VIEWLAYOUT_SUDOKUCONSOLEVIEWCONTROLLER_H_

#include "SudokuConsoleView.h"
#include "SudokuContainer/GridContainer.h"

namespace Veronix
{
namespace App
{
namespace viewcontroller
{

class SudokuViewController
{
public:
	explicit SudokuViewController(const sudosolver::container::GridContainer &);
	virtual ~SudokuViewController();

	bool displaySudoku();
	bool displaySudokuFromConatiner(const sudosolver::container::TableContainer &);

private:
	view::SudokuConsoleView consoleView;
	const sudosolver::container::GridContainer &gridContainer;
};

} /* namespace viewcontroller */
} /* namespace App */
} /* namespace Veronix */

#endif /* APP_VIEWLAYOUT_SUDOKUCONSOLEVIEWCONTROLLER_H_ */
