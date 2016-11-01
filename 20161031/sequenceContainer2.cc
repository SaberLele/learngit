 ///
 /// @file    sequenceContainer2.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-31 04:30:30
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

void display(vector<int>& vec)
{
	vector<int>::iterator it;
	for(it=vec.begin();it!=vec.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vecInt(5,0);
	vector<int>::iterator it =vecInt.end();
	it=vecInt.insert(it,1);
	display(vecInt);
	cout << "*it=" << *it << endl;

	vecInt.insert(it,2,3);
	display(vecInt);

	it=vecInt.begin();
	int arr[3]={7,8,9};
	vecInt.insert(it,arr,arr+3);
	display(vecInt);

//	vecInt.clear();
	cout << "vecInt's size= " << vecInt.size() << endl;
	cout << "vecInt's capacity= " << vecInt.capacity() << endl;

	vecInt.shrink_to_fit();
//	vector<int>(vecInt).swap(vecInt);
	cout << "vecInt's size= " << vecInt.size() << endl;
	cout << "vecInt's capacity= " << vecInt.capacity() << endl;

	return 0;
}
