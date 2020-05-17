/*
 * RowsContainer.cpp
 *
 *  Created on: Dec 15, 2019
 *      Author: LavishK1
 */

#include "RowsContainer.h"

namespace Veronix
{
namespace App
{
namespace sudosolver
{
namespace container
{

RowsContainer::RowsContainer()
{

}

RowsContainer::~RowsContainer()
{

}

int RowsContainer::getLineId(int rowId, int colId)
{
	return rowId;
}

int RowsContainer::getCellId(int rowId, int colId)
{
	return colId;
}


} /* namespace container */
} /* namespace sudosolver */
} /* namespace App */
} /* namespace Veronix */
