 ///
 /// @file    Mylog.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-24 11:28:37
 ///
 
#include "Mylog.h"

#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Priority.hh>

#include <iostream>
using std::cout;
using std::endl;
using namespace log4cpp;

Mylog * Mylog::_pInstance = getInstance();
Mylog * Mylog::getInstance()
{
	if(NULL == _pInstance)
		_pInstance = new Mylog;
	return _pInstance;
}

Mylog::Mylog()
: _cat(log4cpp::Category::getRoot())
{
	PatternLayout * p1 = new PatternLayout();	
	p1->setConversionPattern("%d:%p %c: %m%n");

	PatternLayout * p2 = new PatternLayout();	
	p2->setConversionPattern("%d:%p %c: %m%n");

	OstreamAppender * osApp = new OstreamAppender("osApp", &cout);
	osApp->setLayout(p1);

	RollingFileAppender * rollingApp = 
		new RollingFileAppender("rollingApp",
								"wd.log");
	rollingApp->setLayout(p2);

	_cat.addAppender(osApp);
	_cat.addAppender(rollingApp);
	_cat.setPriority(Priority::DEBUG);
}


void Mylog::info(const string & msg)
{
	_cat.info(msg);
}

void Mylog::warn(const string & msg)
{
	_cat.warn(msg);
}

void Mylog::error(const string & msg)
{
	_cat.error(msg);
}

void Mylog::debug(const string & msg)
{
	_cat.debug(msg);
}

void logInfo(const string & msg)
{
	Mylog * p = Mylog::getInstance();
	p->info(msg);
}
void logWarn(const string & msg)
{
	Mylog * p = Mylog::getInstance();
	p->warn(msg);

}
void logError(const string & msg)
{
	Mylog * p = Mylog::getInstance();
	p->error(msg);
}
void logDebug(const string & msg)
{
	Mylog * p = Mylog::getInstance();
	p->debug(msg);
}
