 ///
 /// @file    Condition.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-15 14:44:18
 ///
 
#ifndef __WANGDAO_CONDITION_H__
#define __WANGDAO_CONDITION_H__


#include "Noncopyable.h"
#include <pthread.h>

namespace zx
{

class MutexLock;
class Condition
: Noncopyable
{
public:
	Condition(MutexLock & mutex);
	~Condition();

	void wait();
	void notify();
	void notifyAll();

private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};

}//end of namespace zx
#endif
