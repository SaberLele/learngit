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
#include <functional>
using std::cout;
using std::endl;
using std::function;

namespace zx
{
	class Thread
	:private Noncopyable
	{
		public:
			typedef function<void()> ThreadCallback;
			Thread(ThreadCallback);
			virtual ~Thread();
	
			void start();
			void join();

		private:
			static void* threadFunc(void*);
	//		virtual void run()=0;
		private:
			pthread_t _pthId;
			bool _isRunning;
			ThreadCallback _cb;
	};	

} //end of namespace

#endif
