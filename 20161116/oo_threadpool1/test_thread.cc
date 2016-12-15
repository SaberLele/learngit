 ///
 /// @file    test_thread.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-16 05:12:09
 ///

#include "Threadpool.h"
#include "Task.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

struct DerivedTask
{
	void execute()
	{
		::srand(::time(NULL));
		int number = ::rand()%100;
		cout << "Prodecu a number: " << number << endl;
	}
};

int main()
{
	zx::Threadpool threadpool(4,10);
//	DerivedTask dt;
	shared_ptr<zx::Task> sp(new zx::Task(std::bind(&DerivedTask::execute,DerivedTask())));
	threadpool.start();
	int cnt=10;
	while(cnt>0)
	{
		threadpool.addTask(sp.get());
		sleep(1);
		cout << "-----cnt= " << cnt << endl;
		--cnt;
	}
//	threadpool.stop();

	return 0;
}
