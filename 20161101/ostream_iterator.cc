 ///
 /// @file    ostream_iterator.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-01 04:35:31
 ///
 
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> vecInt={1,2,3,4,5,6};
	std::ostream_iterator<int> osi(cout," ");
	copy(vecInt.begin(),vecInt.end(),osi);

	cout<<endl;
	return 0;
}
