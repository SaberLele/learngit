 ///
 /// @file    WorkThread.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-16 04:40:07
 ///

#ifndef __WORKTHREAD_H__
#define __WORKTHREAD_H__

#include "Thread.h"

namespace zx
{
	class Threadpool;
	class WorkerThread
	:public Thread
	{
		public:
			WorkerThread(Threadpool & threadpool);

		private:
			void run();
		private:
			Threadpool & _threadpool;
	};

}//end of namespace zx


#endif
