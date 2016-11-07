 ///
 /// @file    find_test.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-07 07:05:52
 ///

#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::find;

int main()
{
	vector<int> vec{1,2,3,4,5,6};
	int val=3;
	auto result=find(vec.begin(),vec.end(),val);
	cout << "The value" << val << (result==vec.end()?"is not present":"is present") << endl;
}
