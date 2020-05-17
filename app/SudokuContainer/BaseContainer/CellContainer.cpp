/*
 * CellContainer.cpp
 *
 *  Created on: Dec 14, 2019
 *      Author: LavishK1
 */

#include <BaseContainer/CellContainer.h>
#include <Execptions/AppException.h>

namespace Veronix
{
namespace App
{
namespace sudosolver
{
namespace container
{

namespace basecontainer
{
const int minCellValue = constants::valueOne;
const int maxCellValue = constants::squareSize;
std::unordered_set<int> CellContainer::universalValuesSet;

CellContainer::CellContainer(int val) : value(val), rowId(constants::valueZero), colId(constants::valueZero)
{
	initializeCellSet();
}

CellContainer::~CellContainer()
{

}

void CellContainer::initializeCellSet()
{
	if (value)
		return;

	initUniversalSet();
	unusedValuesSet = universalValuesSet;
}


void CellContainer::initUniversalSet()
{
	if(universalValuesSet.size() > constants::valueZero)
		return;

	for (int val = minCellValue; val <= maxCellValue; ++val)
		universalValuesSet.insert(val);
}


bool CellContainer::setCellValue(int val)
{
	if (val < minCellValue || val > maxCellValue)
		throw_exception("Invalid Value to be assigned");

	if (unusedValuesSet.find(val) == unusedValuesSet.end())
		return false;

	value = val;
	if (value)
		unusedValuesSet.clear();
	return true;
}

bool CellContainer::setRowAndColId(int row, int col)
{
	if (rowId || colId)
		throw_exception("can't change row or col Id once set for cell");

	rowId = row;
	colId = col;
}

void CellContainer::updateValueSet(int val)
{
	if (value)
		return;

	if ((val < minCellValue) || (val > maxCellValue))
		throw_exception("Invalid Value Range");

	unusedValuesSet.erase(val);

	if (unusedValuesSet.size() <= constants::valueZero)
		throw_exception("Reserved Values UnderFlow");
}

bool CellContainer::autoFillCheck()
{
	if (unusedValuesSet.size() != constants::valueOne)
		return false;

	int autoVal = *unusedValuesSet.begin();
	if ((autoVal < minCellValue) || (autoVal > maxCellValue))
		throw_exception("Invalid Reserve value");

	value = autoVal;
	unusedValuesSet.clear();
	return true;
}

CellContainer& CellContainer::operator=(int val)
{
	setCellValue(val);
	return *this;
}

bool CellContainer::operator==(int val) const
{
	return value == val;
}

bool CellContainer::operator==(const CellContainer &cell) const
{
	return value == cell.value;
}

bool CellContainer::operator!=(int val) const
{
	return value != val;
}

bool CellContainer::operator!=(const CellContainer &cell) const
{
	return value != cell.value;
}

int CellContainer::getCellValue() const
{
	return value;
}

int CellContainer::getCellColId() const
{
	return colId;
}

bool CellContainer::compareValueSet(const std::unordered_set<int> &unusedSet) const
{
	return (unusedValuesSet.size() > constants::valueZero) &&
			(unusedValuesSet == unusedSet);
}

bool CellContainer::compareValueSet(const CellContainer &cell) const
{
	return compareValueSet(cell.unusedValuesSet);
}

bool CellContainer::operator^(const std::unordered_set<int> &unusedSet) const
{
	return compareValueSet(unusedSet);
}

bool CellContainer::operator^(const CellContainer &cell) const
{
	return compareValueSet(cell.unusedValuesSet);
}

int CellContainer::getCellRowId() const
{
	return rowId;
}


} /* namespace basecontainer */
} /* namespace container */
} /* namespace sudosolver */
} /* namespace App */
} /* namespace Veronix */
