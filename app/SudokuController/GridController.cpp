/*
 * GridController.cpp
 *
 *  Created on: Dec 24, 2019
 *      Author: LavishK1
 */

#include "GridController.h"

namespace Veronix
{
namespace App
{
namespace sudosolver
{
namespace controller
{

GridController::GridController(container::GridContainer &gridContainer): gridContainer(gridContainer)
{

}

GridController::~GridController()
{

}

bool GridController::startSolvingGrid()
{
	bool newClueFound = true;
	while(newClueFound)
	{
		newClueFound = false;
		newClueFound |= tableController.checkTableForNewClue(gridContainer.getRowContainer());
		newClueFound |= tableController.checkTableForNewClue(gridContainer.getColContainer());
		newClueFound |= tableController.checkTableForNewClue(gridContainer.getBoxContainer());
	}

	return gridContainer.isGridSolved();
}



} /* namespace controller */
} /* namespace sudosolver */
} /* namespace App */
} /* namespace Veronix */
