/*
 * AppException.h
 *
 *  Created on: Jan 5, 2020
 *      Author: LavishK1
 */

#ifndef APP_EXECPTIONS_APPEXCEPTION_H_
#define APP_EXECPTIONS_APPEXCEPTION_H_

#include <exception>
#include <string>

#define throw_exception(msg) Veronix::App::Exception::AppException(msg, __FILE__, __LINE__)

namespace Veronix
{
namespace App
{
namespace Exception
{

class AppException : public std::exception
{
	std::string exceptionMsg;
	std::string exceptionLocation;
public:
	explicit AppException(const char *, const char *, int);
	virtual ~AppException();

	virtual const char * what() const throw();
	virtual const char * where() const throw();
};

} /* namespace Exception */
} /* namespace App */
} /* namespace Veronix */

#endif /* APP_EXECPTIONS_APPEXCEPTION_H_ */
