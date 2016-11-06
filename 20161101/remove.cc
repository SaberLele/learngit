 ///
 /// @file    remove.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-01 06:23:02
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
	vector<int> vecInt{1,2,3,4,5,6,7,8,9,10};
	vecInt[3]=vecInt[5]=vecInt[9]=99;
	ostream_iterator<int> osi(cout," ");
	copy(vecInt.begin(),vecInt.end(),osi);

	cout << endl;
	
	vecInt.erase(remove(vecInt.begin(),vecInt.end(),99),vecInt.end());
	copy(vecInt.begin(),vecInt.end(),osi);
	
	cout << endl;

	return 0;

}

