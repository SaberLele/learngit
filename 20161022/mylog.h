 ///
 /// @file    log4cpp.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-21 21:42:32
 ///

#ifndef _MYLOG_H
#define _MYLOG_H

#include <sstream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using log4cpp::Priority;
using std::string;
using std::ostringstream;

//将文件行号转化成string类型
inline string int_string(int line)
{
	ostringstream oss;
	oss << line;
	return oss.str();
}
#define set(msg) string(msg).append(" ## ")\
	.append(__FILE__).append(":")\
	.append(__func__).append(":")\
	.append(int_string(__LINE__))\
	.append(" ## ").c_str()
#define logError(msg) log->error(set(msg))
#define logWarn(msg) log->warn(set(msg))
#define logInfo(msg) log->info(set(msg))
#define logDebug(msg) log->debug(set(msg))


//单例模式
class Mylog
{
	public:
		static Mylog * getInstance();
		static void destory();
		
		void setPriority(Priority priority);
		void warn(const char * msg);
		void error(const char * msg);
		void debug(const char * msg);
		void info(const char *msg);

	private:
		Mylog();

		static Mylog * _log;
		log4cpp::Category& _infoCategory;
};


Mylog* Mylog::_log=NULL;

Mylog* Mylog:: getInstance()
{
	if(_log==NULL)
	{
		_log=new Mylog;
	}
	return _log;
}

void Mylog::destory()
{
	if(_log)
	{
		_log->_infoCategory.info("I will destory");
		_log->_infoCategory.shutdown();
		delete _log;
	}
}
 //构造函数
Mylog::Mylog()
:_infoCategory(log4cpp::Category::getRoot())
{
	log4cpp::PatternLayout* pLayout1=
		new log4cpp::PatternLayout();
	pLayout1->setConversionPattern("%d: %p %c %x: %m%n");
	log4cpp::PatternLayout* pLayout2=
		new log4cpp::PatternLayout();
	pLayout2->setConversionPattern("%d: %p %c %x: %m%n");

	//将数据输出终端
	log4cpp::Appender* osAppender=
		new log4cpp::OstreamAppender("osAppender",&cout);
	osAppender->setLayout(pLayout1);
	
	//将数据输出到日志文件
	log4cpp::Appender* rollflieAppender=
		new log4cpp::RollingFileAppender
		("rollfileAppender","mylog.txt",5*1024,1);
	rollflieAppender->setLayout(pLayout2);

	_infoCategory.addAppender(osAppender);
	_infoCategory.addAppender(rollflieAppender);
	_infoCategory.setPriority(log4cpp::Priority::DEBUG);
}

void Mylog::setPriority(Priority priority)
{
	if(priority.ERROR)
		_infoCategory.setPriority(log4cpp::Priority::ERROR);
	if(priority.WARN)
		_infoCategory.setPriority(log4cpp::Priority::WARN);
	if(priority.INFO)
		_infoCategory.setPriority(log4cpp::Priority::INFO);
	if(priority.DEBUG)
		_infoCategory.setPriority(log4cpp::Priority::DEBUG);
	else
		_infoCategory.setPriority(log4cpp::Priority::DEBUG);
}

void Mylog::warn(const char* msg)
{
	_infoCategory.warn(msg);
}
void Mylog::error(const char* msg)
{
	_infoCategory.error(msg);
}
void Mylog::info(const char* msg)
{
	_infoCategory.info(msg);
}
void Mylog::debug(const char* msg)
{
	_infoCategory.debug(msg);
}

#endif
