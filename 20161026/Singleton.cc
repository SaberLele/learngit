 ///
 /// @file    Singleton.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-26 05:18:29
 ///

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
	private:
		class AutoRelease
		{
			public:
				AutoRelease()
				{
				}
				~AutoRelease()
				{
					if(_pInstance)
						delete _pInstance;
				}
		};

	public:
		static Singleton *getInstance()
		{
			if(NULL==_pInstance)
				_pInstance=new Singleton;
			return _pInstance;
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
		static AutoRelease _autoRelease;
};

Singleton * Singleton::_pInstance=getInstance();
Singleton::AutoRelease Singleton::_autoRelease;

int main()
{
	Singleton * p1=Singleton::getInstance();
	Singleton * p2=Singleton::getInstance();

	printf("p1==%p\n",p1);
	printf("p2==%p\n",p2);

	return 0;
}
