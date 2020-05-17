/*
 * AppDefines.h
 *
 *  Created on: May 18, 2019
 *      Author: LavishK1
 */

#ifndef APPDEFINES_H_
#define APPDEFINES_H_

#include <iostream>

#define _Log_Enable

#define LOGAPI_FILE __FILE__
#define LOGAPI_LINE __LINE__

#ifdef _Log_Enable
#define DEF_COUT(X)  std::cout << "(" << LOGAPI_FILE << ":" << LOGAPI_LINE << ")" << X << std::endl
#else
#define DEF_COUT(X) do{}while(0);
#endif

namespace constants
{

const int valueZero = 0;
const int valueOne = 1;
const int squareSize = 9;
const int boxSize = 3;
}

#endif /* APPDEFINES_H_ */
