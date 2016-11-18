 ///
 /// @file    Threadpool.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-16 01:18:40
 ///

#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "Buffer.h"
#include <iostream>
#include <vector>
#include <memory>
using std::vector;
using std::shared_ptr;

namespace zx
{

	class Task;
	class Thread;

	class Threadpool
	{
		friend class WorkerThread;
		public:
			Threadpool(size_t threadNum, size_t bufSize);
			~Threadpool();

			void start();
			void stop();

			void addTask(Task*);

		private:
			Task* getTask();
			void threadFunc();
		private:
			size_t _threadNum;
			size_t _bufSize;
			vector<shared_ptr<Thread> > _threads;
			Buffer _buffer;
			bool _isExit;
	};

}//end of namespace zx


#endif
