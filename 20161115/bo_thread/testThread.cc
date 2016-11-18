 ///
 /// @file    testThread.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-15 04:05:23
 ///

#include "Thread.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using std::cout;
using std::endl;

struct Foo
{
	void run()
	{
		::srand(::time(NULL));
		while(1)
		{
			int number=::rand() % 100;
			cout << "number= " << number << endl;
			::sleep(1);
		}
	}
};

int main()
{
	zx::Thread *pthread=new zx::Thread(std::bind(&Foo::run,Foo()));
	pthread->start();
	pthread->join();

	return 0;
}
