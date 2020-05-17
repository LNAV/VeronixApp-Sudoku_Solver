/*
 * AppException.cpp
 *
 *  Created on: Jan 5, 2020
 *      Author: LavishK1
 */

#include <AppException.h>

namespace Veronix
{
namespace App
{
namespace Exception
{

AppException::AppException(const char *what, const char *file, int line): exceptionMsg(what), exceptionLocation(file)
{
	exceptionLocation += ": ";
	exceptionLocation += std::to_string(line);
}

AppException::~AppException()
{

}

const char* AppException::what() const throw ()
{
	return exceptionMsg.c_str();
}

const char* AppException::where() const throw ()
{
	return exceptionLocation.c_str();
}

} /* namespace Exception */
} /* namespace App */
} /* namespace Veronix */
