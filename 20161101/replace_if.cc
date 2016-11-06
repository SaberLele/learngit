 ///
 /// @file    replace_if.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-01 05:15:50
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

int main()
{
	vector<int> vecInt{1,2,3,4,5,6};
	std::less<int> lt;

	//lt是二元断言（要传两个参数左操作数和右操作数）；
	//bind2nd先绑定第二个参数，将右操作数赋值为3；
	replace_if(vecInt.begin(),vecInt.end(),bind2nd(lt,3),7);

	ostream_iterator<int> osi(cout,"\n");
	copy(vecInt.begin(),vecInt.end(),osi);	
}
