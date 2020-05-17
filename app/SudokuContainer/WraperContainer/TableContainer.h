/*
 * TableContainer.h
 *
 *  Created on: Dec 26, 2019
 *      Author: LavishK1
 */

#ifndef APP_SUDOKUCONTAINER_WRAPERCONTAINER_TABLECONTAINER_H_
#define APP_SUDOKUCONTAINER_WRAPERCONTAINER_TABLECONTAINER_H_

#include "BaseContainer/CellContainer.h"
#include "APP/Arrays/TabularArray.hpp"

namespace Veronix
{
namespace App
{
namespace sudosolver
{
namespace container
{

typedef Array::TabularArray<basecontainer::CellContainer *> TableData;
typedef Array::TableSubArray<basecontainer::CellContainer *> TableRow;

class TableContainer
{
public:
	TableRow & operator[](int);
	const TableRow & operator[](int) const;
	void fillContainerWithCells(basecontainer::CellContainer **allCells);

protected:
	explicit TableContainer();
	virtual ~TableContainer();

	virtual int getLineId(int, int) = 0;
	virtual int getCellId(int, int) = 0;

private:
	TableData tableCells;
};

} /* namespace container */
} /* namespace sudosolver */
} /* namespace App */
} /* namespace Veronix */

#endif /* APP_SUDOKUCONTAINER_WRAPERCONTAINER_TABLECONTAINER_H_ */
