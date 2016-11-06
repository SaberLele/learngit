 ///
 /// @file    for_each.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-01 04:55:19
 ///

#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void print(int & num)
{
	cout << num << endl;
}

struct Printer
{
	void operator()(int& num)
	{
		cout << num << endl;
	}
};

int main()
{
	vector<int> vecInt={1,2,3,4,5,6};
	for_each(vecInt.begin(),vecInt.end(),Printer());

	return 0;
}
