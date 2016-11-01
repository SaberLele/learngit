 ///
 /// @file    sequenceContainer1.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-31 04:16:52
 ///
 
#include <iostream>
#include <vector>
#include <list>
#include <deque>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::deque;

int main()
{
	vector<int> vecInt;
	cout << "vecInt元素个数：" << vecInt.size() << endl;

	double arr[5]={1,2,3,4,5};
	deque<double> dequeDb(arr,arr+5);
	for(size_t idx=0;idx!=dequeDb.size();++idx)
	{
		cout << dequeDb[idx] << " ";
	}
	cout << endl;

	list<float> listFlt(3,5);
	list<float>::iterator lit=listFlt.begin();
	for(;lit!=listFlt.end();++lit)
	{
		cout << *lit << endl;
	}
	return 0;
}
