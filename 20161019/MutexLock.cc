 ///
 /// @file    MutexLock.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-19 08:04:11
 ///
#include <pthread.h> 
#define N 1000000
#include <iostream>
using std::cout;
using std::endl;

class MutexLock
{
	public:
		MutexLock(pthread_mutex_t mutex);
		~MutexLock();

		void lock();
		void unlock();
	private:
		pthread_mutex_t _mutex;
};

MutexLock::MutexLock(pthread_mutex_t mutex)
:_mutex(mutex)
{
	cout << "MutexLock()" << endl;
	pthread_mutex_init(&mutex,NULL);
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


int sum=0;
void* thread_func(void* p)
{
	int i;
	MutexLock *p1=(MutexLock*)p;
	for(i=0;i < N; i++)
	{
		p1->lock();
		sum+=1;
		p1->unlock();
	}
	return NULL;
}

int main()
{
	pthread_t pthid;
	MutexLock *p;
	pthread_create(&pthid,NULL,thread_func,(void *)p);
	int i;
	for(i=0;i<N;i++)
	{
		p->unlock();
		sum++;
		p->unlock();
	}
	pthread_join(pthid,NULL);
	cout << "sum = " << sum << endl;

	return 0;	
}





