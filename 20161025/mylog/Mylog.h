 ///
 /// @file    Mylog.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-24 11:24:48
 ///

#ifndef __WANGDAO_MYLOG_H__
#define __WANGDAO_MYLOG_H__

#include <log4cpp/Category.hh>
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;


class Mylog
{
public:
	static Mylog * getInstance();
	static void destroy();

	void warn(const string & msg);
	void info(const string & msg);
	void error(const string & msg);
	void debug(const string & msg);
private:
	Mylog();
	~Mylog();
private:
	log4cpp::Category & _cat;
	static Mylog * _pInstance;
};

inline string int2str(int num)
{
	std::ostringstream oss;
	oss << num;
	return oss.str();
}

#define postfix(msg)	string(msg).append("[").append(__FILE__)\
	   .append(":").append(__FUNCTION__)\
	   .append(":").append(int2str(__LINE__)).append("]")


void logInfo(const string & msg);
void logWarn(const string & msg);
void logError(const string & msg);
void logDebug(const string & msg);

#define LogInfo(msg) logInfo(postfix(msg))
#define LogWarn(msg) logWarn(postfix(msg))
#define LogError(msg) logError(postfix(msg))
#define LogDebug(msg) logDebug(postfix(msg))


#endif
