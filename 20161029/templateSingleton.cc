 ///
 /// @file    templateSingleton.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-29 00:43:25
 ///

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <typename T>
class Singleton
{
	public:
	static T* getInstance()
	{
		pthread_once(&_once,Singleton<T>::init);
		return _pInstance;
	}

	static void init()
	{
		_pInstance=new T;
		atexit(Singleton<T>::destroy);
	}

	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
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
		static T * _pInstance;
		static pthread_once_t _once;
};

template <typename T>
T * Singleton<T>::_pInstance=NULL;
template <typename T> 
pthread_once_t Singleton<T>::_once=PTHREAD_ONCE_INIT;

int main()
{
	string* p1=Singleton<string>::getInstance();
	string* p2=Singleton<string>::getInstance();
	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);

	char* p3=Singleton<char>::getInstance();
	char* p4=Singleton<char>::getInstance();
	printf("p3 = %p\n", p3);
	printf("p4 = %p\n", p4);
	
	int* p5=Singleton<int>::getInstance();
	int* p6=Singleton<int>::getInstance();
	printf("p5 = %p\n", p5);
	printf("p6 = %p\n", p6);
	return 0;
}
