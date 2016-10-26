 ///
 /// @file    Singleton.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-26 05:18:29
 ///

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
	public:
		static Singleton *getInstance()
		{
			if(NULL==_pInstance)
			{
				_pInstance=new Singleton;
				atexit(destory);
			}
			return _pInstance;
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
};

Singleton * Singleton::_pInstance=getInstance();

int main()
{
	Singleton * p1=Singleton::getInstance();
	Singleton * p2=Singleton::getInstance();

	printf("p1==%p\n",p1);
	printf("p2==%p\n",p2);

	return 0;
}
