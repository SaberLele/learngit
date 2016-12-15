 ///
 /// @file    Threadpool.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-16 11:00:47
 ///
 
#ifndef __WANGDAO_THREADPOOL_H__
#define __WANGDAO_THREADPOOL_H__
#include "Buffer.h"
#include "Task.h"

#include <iostream>
#include <vector>
#include <memory>
using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;


namespace zx
{
class Thread;

class Threadpool 
{
	friend class WorkerThread;
public:
	Threadpool(size_t threadNum, size_t bufSize);
	~Threadpool();

	void start();
	void stop();

	void addTask(Task);
private:
	Task getTask();
	void threadFunc();//交给工作线程来执行
	
private:
	size_t _threadNum;
	size_t _bufSize;
	vector<shared_ptr<Thread> > _threads;
	Buffer _buffer;
	bool _isExit;
};

}// end of namespace zx

#endif
