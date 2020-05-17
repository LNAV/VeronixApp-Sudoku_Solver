/*
 * TableContainer.cpp
 *
 *  Created on: Dec 26, 2019
 *      Author: LavishK1
 */

#include <TableContainer.h>

namespace Veronix
{
namespace App
{
namespace sudosolver
{
namespace container
{

TableContainer::TableContainer() : tableCells(constants::squareSize, constants::squareSize)
{

}

TableContainer::~TableContainer()
{

}

void TableContainer::fillContainerWithCells(basecontainer::CellContainer **allCells)
{
	for (int rowId = constants::valueZero; rowId < constants::squareSize; ++rowId)
	{
		for (int colId = constants::valueZero; colId < constants::squareSize; ++colId)
		{
			int lineId = getLineId(rowId, colId);
			int cellId = getCellId(rowId, colId);
			tableCells[lineId][cellId] = allCells[rowId] + colId;
		}
	}
}

TableRow & TableContainer::operator[](int index)
{
	if (index < constants::valueZero || index >= constants::squareSize)
		throw "Invalid Row index";

	return tableCells[index];
}

const TableRow & TableContainer::operator[](int index) const
{
	if (index < constants::valueZero || index >= constants::squareSize)
		throw "Invalid Row index";

	return tableCells[index];
}

} /* namespace container */
} /* namespace sudosolver */
} /* namespace App */
} /* namespace Veronix */
