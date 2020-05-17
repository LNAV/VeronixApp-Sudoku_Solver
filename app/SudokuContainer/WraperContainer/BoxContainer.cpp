/*
 * BoxContainer.cpp
 *
 *  Created on: Dec 14, 2019
 *      Author: LavishK1
 */

#include "BoxContainer.h"

namespace Veronix
{
namespace App
{
namespace sudosolver
{
namespace container
{

BoxContainer::BoxContainer()
{

}

BoxContainer::~BoxContainer()
{

}

int BoxContainer::getLineId(int rowId, int colId)
{
	return (rowId / constants::boxSize) * constants::boxSize + colId / constants::boxSize;
}

int BoxContainer::getCellId(int rowId, int colId)
{
	return (rowId % constants::boxSize) * constants::boxSize + colId % constants::boxSize;
}


} /* namespace container */
} /* namespace sudosolver */
} /* namespace App */
} /* namespace Veronix */
