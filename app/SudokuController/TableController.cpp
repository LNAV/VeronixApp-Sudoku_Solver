/*
 * TableController.cpp
 *
 *  Created on: Dec 26, 2019
 *      Author: LavishK1
 */

#include <TableController.h>

namespace Veronix
{
namespace App
{
namespace sudosolver
{
namespace controller
{

TableController::TableController()
{

}

TableController::~TableController()
{

}

void TableController::updateTableRowForReserve(container::TableRow &cells, int reserveValue)
{
	for (int cellId = constants::valueZero; cellId < constants::squareSize; ++cellId)
		cells[cellId]->updateValueSet(reserveValue);
}

bool TableController::checkTableRow(container::TableRow &cells)
{
	bool foundNewValue = false;
	while(true)
	{
		int cellsUpdated = constants::valueZero;
		for (int cellId = constants::valueZero; cellId < constants::squareSize; ++cellId)
		{
			container::basecontainer::CellContainer &cell = *cells[cellId];
			if (cell.autoFillCheck())
				cellsUpdated++;

			if (cell != constants::valueZero)
				updateTableRowForReserve(cells, cell);
		}

		if (cellsUpdated > constants::valueZero)
		{
			foundNewValue = true;
			continue;
		}

		break;
	}

	return foundNewValue;
}

bool TableController::checkTableForNewClue(container::TableContainer &container)
{
	bool isNewClueFound = false;
	for (int row = constants::valueZero; row < constants::squareSize; ++row)
	{
		isNewClueFound |= checkTableRow(container[row]);
	}

	return isNewClueFound;

}


} /* namespace controller */
} /* namespace sudosolver */
} /* namespace App */
} /* namespace Veronix */
