 ///
 /// @file    Thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-15 10:57:56
 ///
 
#ifndef __WANGDAO_THREAD_H__
#define __WANGDAO_THREAD_H__

#include "Noncopyable.h"

#include <pthread.h>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;



namespace zx
{

class Thread : Noncopyable
{
public:
	typedef function<void()> ThreadCallback;
	Thread(ThreadCallback cb);
	~Thread();

	void start();
	void join();

private:
	static void * threadFunc(void *);
private:
	pthread_t      _pthId;
	ThreadCallback _cb;
	bool           _isRunning;
};

}//end of namespace zx 


#endif 
