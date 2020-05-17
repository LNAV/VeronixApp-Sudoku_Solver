/*
 * InputHelper.h
 *
 *  Created on: Dec 31, 2019
 *      Author: LavishK1
 */

#ifndef APP_HELPER_INPUTHELPER_H_
#define APP_HELPER_INPUTHELPER_H_

#include "App/Arrays/TabularArray.hpp"

namespace Veronix
{
namespace App
{
namespace helper
{

typedef enum _Input_Format
{
	undefined,
	console_read,
	file_read
}InputFormat;

class InputHelper
{
public:
	explicit InputHelper();
	virtual ~InputHelper();

	const Array::TabularArray<int> &getSudokuGridData(InputFormat = undefined);

private:
	int readValuesFromConsole(int, int);
	int readValuesFromFile(int, int);
	int useDemoDataValues(int, int);
	Array::TabularArray<int> sudokuData;
};

} /* namespace helper */
} /* namespace App */
} /* namespace Veronix */

#endif /* APP_HELPER_INPUTHELPER_H_ */
