 ///
 /// @file    Singleton.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-20 03:51:16
 ///

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
	public:
		static Singleton * getInstance()
		{
			cout << "getInstance()" << endl;
			if(NULL==_pInstance)
			{
				_pInstance=new Singleton;
			}
			return _pInstance;
		}
		static void destory()
		{
			cout << "destory()" << endl;
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
		static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = getInstance();

int main()
{
	Singleton *p1=Singleton::getInstance();
//	Singleton *p2=Singleton::getInstance();
	
	printf("p1=%p\n",p1);
//	printf("p2=%p\n",p2);

	Singleton::destory();
	return 0;
}
