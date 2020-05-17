/*
 * SudokuView.h
 *
 *  Created on: Dec 31, 2019
 *      Author: LavishK1
 */

#ifndef APP_VIEWLAYOUT_SUDOKUCONSOLEVIEW_H_
#define APP_VIEWLAYOUT_SUDOKUCONSOLEVIEW_H_

#include "App/Arrays/TabularArray.hpp"

namespace Veronix
{
namespace App
{
namespace view
{

class SudokuConsoleView
{
public:
	explicit SudokuConsoleView();
	virtual ~SudokuConsoleView();

	bool updateSudokuView(int, int, int);
	void displayView();

private:
	Array::TabularArray<int> sudokuVals;
};

} /* namespace view */
} /* namespace App */
} /* namespace Veronix */

#endif /* APP_VIEWLAYOUT_SUDOKUCONSOLEVIEW_H_ */
