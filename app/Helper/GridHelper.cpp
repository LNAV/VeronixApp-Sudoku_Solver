/*
 * GridHelper.cpp
 *
 *  Created on: Jan 1, 2020
 *      Author: LavishK1
 */

#include "GridHelper.h"

namespace Veronix
{
namespace App
{
namespace helper
{

GridHelper::GridHelper()
{


}

GridHelper::~GridHelper()
{

}

bool GridHelper::findNewClue(sudosolver::container::GridContainer &grid)
{
	//TODO
	findNewClueInTable(grid.getRowContainer());
	findNewClueInTable(grid.getColContainer());
	findNewClueInTable(grid.getBoxContainer());
	return true;
}

bool GridHelper::findNewClueInTable(sudosolver::container::TableContainer &table)
{
	//TODO
	for (int index = constants::valueZero; index < constants::squareSize; ++index)
		findNewClueInTableRow(table[index]);
	return true;
}

bool GridHelper::findNewClueInTableRow(sudosolver::container::TableRow &tableRow)
{
	//TODO
	return true;
}

} /* namespace helper */
} /* namespace App */
} /* namespace Veronix */
