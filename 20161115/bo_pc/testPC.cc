 ///
 /// @file    testPC.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-15 05:50:41
 ///

#include "Thread.h"
#include "Buffer.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

struct Prodecer
{
	void prodece(zx::Buffer & buffer)
	{
		::srand(time(NULL));
		while(1)
		{
			int number = ::rand() % 100;
			buffer.push(number);
			cout << "ThreadID: " << pthread_self() << ":Produce a number: " << number << endl;
			sleep(2);
		}
	}
};

struct Consumer
{
	void consumer(zx::Buffer & buffer)
	{
		while(1)
		{
			int number=buffer.pop();
			cout << "ThreadId:" << pthread_self() << ":Consume a nubmer: " << number << endl;
			sleep(1);
		}
	}
};

int main()
{
	zx::Buffer buffer(10);

	Prodecer prodecer;
	Consumer consumer;

	zx::Thread pProduct(bind(&Prodecer::prodece,&prodecer,std::ref(buffer)));
	zx::Thread pConsume(bind(&Consumer::consumer,&consumer,std::ref(buffer)));

	pProduct.start();
	pConsume.start();
	pProduct.join();
	pConsume.join();

	return 0;

}
