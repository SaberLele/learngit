 ///
 /// @file    WorkThread.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-16 05:04:07
 ///

#include "WorkThread.h"
#include "Threadpool.h"
#include <iostream>

namespace zx
{

	WorkerThread::WorkerThread(Threadpool & threadpool)
	:_threadpool(threadpool)
	{}

	void WorkerThread::run()
	{
		_threadpool.threadFunc();
	}

}//end of namespace zx
