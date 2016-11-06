 ///
 /// @file    insert_iterator.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-01 07:13:26
 ///
 
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::list;

template <typename Container>
void display(const Container & c)
{
	typename Container::const_iterator it=c.begin();
	while(it!=c.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	vector<int> vecInt{0,1,2};
	list<int> listDest;

	copy(vecInt.begin(),vecInt.end(),
		  std::back_insert_iterator<list<int> > (listDest));
	display(listDest);

	copy(vecInt.begin(),vecInt.end(),
		  std::front_insert_iterator<list<int> > (listDest));
	display(listDest);	

	copy(vecInt.begin(),vecInt.end(),
		  std::insert_iterator<list<int> > (listDest,++listDest.begin()));
	display(listDest);	

	return 0;
}
