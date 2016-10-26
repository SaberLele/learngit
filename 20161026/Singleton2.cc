 ///
 /// @file    Singleton.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-26 05:18:29
 ///

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
	public:
		static Singleton *getInstance()
		{
			pthread_once(&_once,init);
			return _pInstance;
		}
		static void init()
		{
			_pInstance=new Singleton;
			atexit(destory);
		}

		static void destory()
		{
			if(_pInstance)
			{
				delete _pInstance;
			}
		}

	private:
		Singleton()
		{
			cout << "Singleton()" << endl;
		}
		~Singleton()
		{
			cout << "~Singleton()" << endl;
		}

	private:
		static Singleton * _pInstance;
		static pthread_once_t _once;
};

Singleton * Singleton::_pInstance=getInstance();
pthread_once_t Singleton::_once=PTHREAD_ONCE_INIT;

int main()
{
	Singleton * p1=Singleton::getInstance();
	Singleton * p2=Singleton::getInstance();

	printf("p1==%p\n",p1);
	printf("p2==%p\n",p2);

	return 0;
}
