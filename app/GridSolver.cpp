/*
 * GridSolver.cpp
 *
 *  Created on: Dec 14, 2019
 *      Author: LavishK1
 */

#include "GridSolver.h"

namespace Veronix
{
namespace App
{
namespace sudosolver
{

GridSolver::GridSolver(container::GridContainer &gridContainer): gridContainer(gridContainer), gridController(gridContainer)
{

}

GridSolver::~GridSolver()
{

}

bool GridSolver::solveGrid()
{
	return gridController.startSolvingGrid();
}


} /* namespace sudosolver */
} /* namespace App */
} /* namespace Veronix */
