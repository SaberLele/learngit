 ///
 /// @file    reverse_iterator.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-01 07:07:32
 ///

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

int main()
{
	vector<int> vecInt{1,2,3,4,5,6};
	ostream_iterator<int> osi(cout,"\n");

	vector<int>::reverse_iterator rit=vecInt.rbegin();
	copy(rit,vecInt.rend(),osi);

	return 0;
}
