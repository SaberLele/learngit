 ///
 /// @file    iteratorIllegal.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-01 06:08:30
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ostream_iterator;

int main()
{
	vector<string> vecStr;
	vecStr.push_back("this is A");
	auto it=vecStr.begin();    //只会执行一遍
	bool flag=true;
	for(;it!=vecStr.end();++it)
	{
		cout << "vecStr's size = " << vecStr.size() << endl;
		cout << *it << endl;
		if(flag)
		{
			vecStr.push_back("this is B");
			ostream_iterator<string> osi(cout, " ");
			copy(vecStr.begin(),vecStr.end(),osi);
			cout << endl;
			cout << "vecStr.push " << endl;
			flag = false;
		}
	}
	return 0;
}
