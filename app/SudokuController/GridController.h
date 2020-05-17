/*
 * GridController.h
 *
 *  Created on: Dec 24, 2019
 *      Author: LavishK1
 */

#ifndef APP_SUDOKUCONTROLLER_GRIDCONTROLLER_H_
#define APP_SUDOKUCONTROLLER_GRIDCONTROLLER_H_

#include "SudokuContainer/GridContainer.h"
#include "TableController.h"

namespace Veronix
{
namespace App
{
namespace sudosolver
{
namespace controller
{

class GridController
{
public:
	explicit GridController(container::GridContainer &);
	virtual ~GridController();

	bool startSolvingGrid();

private:
	container::GridContainer &gridContainer;
	TableController tableController;
};

} /* namespace controller */
} /* namespace sudosolver */
} /* namespace App */
} /* namespace Veronix */

#endif /* APP_SUDOKUCONTROLLER_GRIDCONTROLLER_H_ */
