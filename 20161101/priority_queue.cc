 ///
 /// @file    priority_queue.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-01 06:43:36
 ///
 
#include <iostream>
#include <queue>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;

class Point
{
	public:
		Point(int ix,int iy)
		:_ix(ix)
		,_iy(iy)
		{}

		friend std::ostream & operator<<(std::ostream & os,const Point & rhs);
		friend bool operator > (const Point & lhs, const Point & rhs);
	private:
		int _ix;
		int _iy;
};
std::ostream & operator<<(std::ostream & os,const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

bool operator > (const Point & lhs, const Point & rhs)
{
	if(lhs._ix>rhs._ix)
		return true;
	else
		return false;
}

int test()
{
	int arr[10]={0,1,3,2,5,6,9,8,7,4};
	priority_queue<int,vector<int>,std::greater<int> > pqueInt;
	for(int idx=0;idx!=10;++idx)
	{
		pqueInt.push(arr[idx]);
		cout << pqueInt.top() << "是目前队列中优先级别最高的" << endl;
	}
	cout << "pqueInt的元素有" << pqueInt.size() << "个" << endl;

	while(!pqueInt.empty())
	{
		cout << pqueInt.top() << " ";
		pqueInt.pop();
	}
	cout << endl;
	return 0;
}

int main()
{
	Point arr[5] = {
		Point(6,8),
		Point(9,8),
		Point(7,8),
		Point(5,8),
		Point(10,8)
	};
	priority_queue<Point,vector<Point>,std::greater<Point> > pque;
	
	for(int idx = 0; idx != 5; ++idx)
	{
		pque.push(arr[idx]);
		cout << pque.top() << "是目前队列中优先级别最高的" << endl;
	}
	cout << "pqueInt的元素有" << pque.size() << "个" << endl;

	while(!pque.empty())
	{
		cout << pque.top() << " ";
		pque.pop();
	}
	cout << endl;
	return 0;
}
