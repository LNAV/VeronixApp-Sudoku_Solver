/*
 * TableController.h
 *
 *  Created on: Dec 26, 2019
 *      Author: LavishK1
 */

#ifndef APP_SUDOKUCONTROLLER_TABLECONTROLLER_H_
#define APP_SUDOKUCONTROLLER_TABLECONTROLLER_H_

#include "SudokuContainer/WraperContainer/TableContainer.h"

namespace Veronix
{
namespace App
{
namespace sudosolver
{
namespace controller
{

class TableController
{
public:
	explicit TableController();
	virtual ~TableController();

	bool checkTableForNewClue(container::TableContainer &);

private:
	bool checkTableRow(container::TableRow &);
	void updateTableRowForReserve(container::TableRow &, int);
};

} /* namespace controller */
} /* namespace sudosolver */
} /* namespace App */
} /* namespace Veronix */

#endif /* APP_SUDOKUCONTROLLER_TABLECONTROLLER_H_ */
