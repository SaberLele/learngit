 ///
 /// @file    istream_iterator.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-01 04:40:30
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> vecInt;
	std::istream_iterator<int> isi(std::cin);
	copy(isi,std::istream_iterator<int>(),std::back_inserter(vecInt));

	for(auto & elemt:vecInt)
	{
		cout << elemt << " ";
	}
	cout << endl;
	return 0;
}
