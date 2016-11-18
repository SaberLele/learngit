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

class Prodecer
:public  zx::Thread
{
	public:
		Prodecer(zx::Buffer & buffer)
		:_buffer(buffer)
		{}

	private:
		void run()
		{
			::srand(time(NULL));
			while(1)
			{
				int number = ::rand() % 100;
				_buffer.push(number);
				cout << "ThreadID: " << pthread_self() << ":Produce a number: " << number << endl;
				sleep(2);
			}
		}
	private:
		zx::Buffer &_buffer;

};

class Consumer
:public zx::Thread
{
	public:
		Consumer(zx::Buffer & buffer)
		:_buffer(buffer)
		{}

	private:
		void run()
		{
			while(1)
			{
				int number=_buffer.pop();

				cout << "ThreadId:" << pthread_self() << ":Consume a nubmer: " << number << endl;
				sleep(1);
			}
		}

	private:
		zx::Buffer & _buffer;
};

int main()
{
	zx::Buffer buffer(10);

	zx::Thread * pProduct = new Prodecer(buffer);
	zx::Thread * pConsume = new Consumer(buffer);

	pProduct->start();
	pConsume->start();
	pProduct->join();
	pConsume->join();

	return 0;

}
