 ///
 /// @file    Buffer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-15 14:50:35
 ///
 
#ifndef __WANGDAO_BUFFER_H__
#define __WANGDAO_BUFFER_H__

#include "MutexLock.h"
#include "Condition.h"
#include "Task.h"

#include <queue>
using std::queue;

namespace zx
{
typedef Task Data;

class Buffer{
public:
	Buffer(size_t size);
	
	
	void push(Data data);
	Data pop();

	void wakeup();
	
	bool full() const;
	bool empty() const;

private:
	size_t _queSize;
	queue<Data>  _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	bool _flag;
};

}// end of namespace zx
#endif
