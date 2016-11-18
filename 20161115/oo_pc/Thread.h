 ///
 /// @file    Thread.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-15 03:39:01
 ///

#ifndef __THREAD_H__
#define __THREAD_H__

#include "Noncopyable.h"
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

namespace zx
{
	class Thread
	:private Noncopyable
	{
		public:
			Thread();
			virtual ~Thread();
	
			void start();
			void join();

		private:
			static void* threadFunc(void*);
			virtual void run()=0;
		private:
			pthread_t _pthId;
			bool _isRunning;
	};	

} //end of namespace

#endif
