 ///
 /// @file    queue.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-01 06:39:13
 ///
 
#include <iostream>
#include <queue>
using std::cout;
using std::endl;
using std::queue;

int main()
{
	int i=0;
	queue<int> v;
	for(i=0;i<10;++i)
	{
		v.push(i);
		cout << v.back() << " 已入队列" << endl;
	}
	cout << "现在queue的容量: " << v.size() << endl << endl;
	for(i=0;i<10;++i)
	{
		cout << v.front() << " 准备出队列" << endl;
		v.pop();
	}
	cout << "现在queue的容量: " << v.size() << endl << endl;

	return 0;
}
