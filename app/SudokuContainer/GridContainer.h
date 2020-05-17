/*
 * GridContainer.h
 *
 *  Created on: Dec 15, 2019
 *      Author: LavishK1
 */

#ifndef APP_SUDOKUCONTAINER_GRIDCONTAINER_H_
#define APP_SUDOKUCONTAINER_GRIDCONTAINER_H_

#include "BaseContainer/CellContainer.h"
#include "WraperContainer/ColumnsContainer.h"
#include "WraperContainer/RowsContainer.h"
#include "WraperContainer/BoxContainer.h"

namespace Veronix
{
namespace App
{
namespace sudosolver
{
namespace container
{

class GridContainer
{
public:
	explicit GridContainer(const Array::TabularArray<int> &);
	virtual ~GridContainer();
	GridContainer(const GridContainer &);

	RowsContainer & getRowContainer();
	ColumnsContainer & getColContainer();
	BoxContainer & getBoxContainer();

	const RowsContainer & getRowContainer() const;
	const ColumnsContainer & getColContainer() const;
	const BoxContainer & getBoxContainer() const;

	bool isGridSolved();

private:
	void allocateCells();
	void initAllCellsAndContainers();

	basecontainer::CellContainer **allCells;
	RowsContainer rowsContainer;
	ColumnsContainer colsContainer;
	BoxContainer boxContainer;

};

} /* namespace container */
} /* namespace sudosolver */
} /* namespace App */
} /* namespace Veronix */

#endif /* APP_SUDOKUCONTAINER_GRIDCONTAINER_H_ */
