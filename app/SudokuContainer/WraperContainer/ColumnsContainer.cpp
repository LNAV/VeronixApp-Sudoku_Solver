/*
 * ColumnsContainer.cpp
 *
 *  Created on: Dec 15, 2019
 *      Author: LavishK1
 */

#include "ColumnsContainer.h"

namespace Veronix
{
namespace App
{
namespace sudosolver
{
namespace container
{

ColumnsContainer::ColumnsContainer()
{

}

ColumnsContainer::~ColumnsContainer()
{

}

int ColumnsContainer::getLineId(int rowId, int colId)
{
	return colId;
}

int ColumnsContainer::getCellId(int rowId, int colId)
{
	return rowId;
}

} /* namespace container */
} /* namespace sudosolver */
} /* namespace App */
} /* namespace Veronix */
