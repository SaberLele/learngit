 ///
 /// @file    MutexLock.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-19 08:04:11
 ///
 
#include <unistd.h>
#include <pthread.h> 
#include <iostream>
using std::cout;
using std::endl;

class MutexLock
{
	public:
		MutexLock();
		~MutexLock();

		void lock();
		void unlock();
		pthread_mutex_t * getMutexPtr();
	private:
		pthread_mutex_t _mutex;
};

MutexLock::MutexLock()
{
	cout << "MutexLock()" << endl;
	pthread_mutex_init(&_mutex,NULL);
}

MutexLock::~MutexLock()
{
	cout << "~MutexLock()" << endl;
	pthread_mutex_destroy(&_mutex);
}

void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
}
void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
}
pthread_mutex_t * MutexLock::getMutexPtr()
{
	return &_mutex;
}


class Condition
{
	private:
		pthread_cond_t _cond;
		MutexLock& _mutex;
	public:
		Condition(MutexLock &mutex);
		~Condition();
		void wait();
		void notify();
		void notifyall();
};

Condition::Condition(MutexLock &mutex)
:_mutex(mutex)
{
	pthread_cond_init(&_cond,NULL);
}

Condition::~Condition()
{
	pthread_cond_destroy(&_cond);
}

void Condition::wait()
{
	pthread_cond_wait(&_cond,_mutex.getMutexPtr());
}

void Condition::notify()
{
	pthread_cond_signal(&_cond);
}
void Condition::notifyall()
{
	pthread_cond_broadcast(&_cond);
}

MutexLock mutex;
Condition cond(mutex);

void * pth_func(void * p)
{
	mutex.lock();
	cout << "I am waiting" << endl;
	cond.wait();
	cout << "byebye" << endl;
	mutex.unlock();
	
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t pthid;
	pthread_create(&pthid, NULL, pth_func, NULL);
	sleep(3);
	cond.notify();
	pthread_join(pthid,NULL);
	return 0;
}


