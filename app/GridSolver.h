/*
 * GridSolver.h
 *
 *  Created on: Dec 14, 2019
 *      Author: LavishK1
 */

#ifndef APP_GRIDSOLVER_H_
#define APP_GRIDSOLVER_H_

#include "SudokuContainer/GridContainer.h"
#include "SudokuController/GridController.h"

namespace Veronix
{
namespace App
{
namespace sudosolver
{

class GridSolver
{
public:
	explicit GridSolver(container::GridContainer &);
	virtual ~GridSolver();

	bool solveGrid();

private:
	container::GridContainer &gridContainer;
	controller::GridController gridController;
};

} /* namespace sudosolver */
} /* namespace App */
} /* namespace Veronix */

#endif /* APP_GRIDSOLVER_H_ */
