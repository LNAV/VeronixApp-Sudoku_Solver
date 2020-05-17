/*
 * GridHelper.h
 *
 *  Created on: Jan 1, 2020
 *      Author: LavishK1
 */

#ifndef APP_HELPER_GRIDHELPER_H_
#define APP_HELPER_GRIDHELPER_H_

#include "SudokuContainer/GridContainer.h"

namespace Veronix
{
namespace App
{
namespace helper
{

class GridHelper
{
public:
	explicit GridHelper();
	virtual ~GridHelper();

	bool findNewClue(sudosolver::container::GridContainer &);

private:
	bool findNewClueInTable(sudosolver::container::TableContainer &);
	bool findNewClueInTableRow(sudosolver::container::TableRow &);
};

} /* namespace helper */
} /* namespace App */
} /* namespace Veronix */

#endif /* APP_HELPER_GRIDHELPER_H_ */
