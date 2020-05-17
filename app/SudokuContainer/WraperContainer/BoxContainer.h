/*
 * BoxContainer.h
 *
 *  Created on: Dec 14, 2019
 *      Author: LavishK1
 */

#ifndef APP_SUDOKUCONTAINER_WRAPERCONTAINER_BOXCONTAINER_H_
#define APP_SUDOKUCONTAINER_WRAPERCONTAINER_BOXCONTAINER_H_

#include "TableContainer.h"

namespace Veronix
{
namespace App
{
namespace sudosolver
{
namespace container
{

class BoxContainer : public TableContainer
{
private:
	explicit BoxContainer();
	virtual ~BoxContainer();

	int getLineId(int, int);
	int getCellId(int, int);
	friend class GridContainer;
};

} /* namespace container */
} /* namespace sudosolver */
} /* namespace App */
} /* namespace Veronix */

#endif /* APP_SUDOKUCONTAINER_WRAPERCONTAINER_BOXCONTAINER_H_ */
