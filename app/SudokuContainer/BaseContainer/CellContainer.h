/*
 * CellContainer.h
 *
 *  Created on: Dec 14, 2019
 *      Author: LavishK1
 */

#ifndef APP_SUDOKUCONTAINER_BASECONTAINER_CELLCONTAINER_H_
#define APP_SUDOKUCONTAINER_BASECONTAINER_CELLCONTAINER_H_

#include <unordered_set>
#include "AppDefines.h"

namespace Veronix
{
namespace App
{
namespace sudosolver
{
namespace container
{

class GridContainer;

namespace basecontainer
{
class CellContainer
{
	static std::unordered_set<int> universalValuesSet;
	std::unordered_set<int> unusedValuesSet;
	int value;
	int colId;
	int rowId;

	explicit CellContainer(int = constants::valueZero);
	virtual ~CellContainer();

	void initializeCellSet();
	void initUniversalSet();

	friend GridContainer;
public:
	bool setCellValue(int);
	bool setRowAndColId(int, int);
	void updateValueSet(int);
	bool autoFillCheck();
	CellContainer& operator=(int);
	bool operator==(int) const;
	bool operator==(const CellContainer &) const;
	bool operator!=(int) const;
	bool operator!=(const CellContainer &) const;

	bool compareValueSet(const std::unordered_set<int> &) const;
	bool compareValueSet(const CellContainer &) const;
	bool operator^(const std::unordered_set<int> &) const;
	bool operator^(const CellContainer &) const;
	operator int() const {return value;}

	int getCellValue() const;
	int getCellColId() const;
	int getCellRowId() const;
};

} /* namespace basecontainer */
} /* namespace container */
} /* namespace sudosolver */
} /* namespace App */
} /* namespace Veronix */

#endif /* APP_SUDOKUCONTAINER_BASECONTAINER_CELLCONTAINER_H_ */
