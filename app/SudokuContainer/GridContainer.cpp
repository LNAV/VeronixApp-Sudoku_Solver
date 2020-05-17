/*
 * GridContainer.cpp
 *
 *  Created on: Dec 15, 2019
 *      Author: LavishK1
 */

#include "GridContainer.h"

namespace Veronix
{
namespace App
{
namespace sudosolver
{
namespace container
{

GridContainer::GridContainer(const Array::TabularArray<int> &cellValues): allCells(nullptr)
{
	initAllCellsAndContainers();
	for (int row = constants::valueZero; row < constants::squareSize; ++row)
		for (int col = constants::valueZero; col < constants::squareSize; ++col)
		{
			allCells[row][col].setRowAndColId(row, col);
			allCells[row][col] = cellValues[row][col];
		}
}

GridContainer::GridContainer(const GridContainer &grid): allCells(nullptr)
{
	std::cout << "GridContainer Copy constructor" << std::endl;
	initAllCellsAndContainers();
	for (int row = constants::valueZero; row < constants::squareSize; row++)
		for (int col = constants::valueZero; col < constants::squareSize; col++)
		{
			std::cout << "Set value for row-" << row << ", col-" << col << " with Value: " << (int)grid.allCells[row][col] << std::endl;
			allCells[row][col].setRowAndColId(row, col);
			allCells[row][col] = grid.allCells[row][col];
		}
}

GridContainer::~GridContainer()
{
	for (int index = constants::valueZero; index < constants::squareSize; index++)
	{
		delete [] allCells[index];
		allCells[index] = nullptr;
	}

	delete [] allCells;
}

void GridContainer::allocateCells()
{
	if (allCells)
		throw "Cells already allocated";

	allCells = new basecontainer::CellContainer* [constants::squareSize];
	for (int index = constants::valueZero; index < constants::squareSize; index++)
	{
		allCells[index] = new basecontainer::CellContainer [constants::squareSize];
	}
}

void GridContainer::initAllCellsAndContainers()
{
	allocateCells();
	rowsContainer.fillContainerWithCells(allCells);
	colsContainer.fillContainerWithCells(allCells);
	boxContainer.fillContainerWithCells(allCells);
}

RowsContainer & GridContainer::getRowContainer()
{
	return rowsContainer;
}

ColumnsContainer & GridContainer::getColContainer()
{
	return colsContainer;
}

BoxContainer & GridContainer::getBoxContainer()
{
	return boxContainer;
}

const RowsContainer & GridContainer::getRowContainer() const
{
	return rowsContainer;
}

const ColumnsContainer & GridContainer::getColContainer() const
{
	return colsContainer;
}

const BoxContainer & GridContainer::getBoxContainer() const
{
	return boxContainer;
}

bool GridContainer::isGridSolved()
{
	for (int row = constants::valueZero; row < constants::squareSize; row++)
		for (int col = constants::valueZero; col < constants::squareSize; col++)
			if (allCells[row][col] == constants::valueZero)
				return false;

	return true;
}


} /* namespace container */
} /* namespace sudosolver */
} /* namespace App */
} /* namespace Veronix */
