 ///
 /// @file    set.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-31 05:21:49
 ///
 
#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::ostream;
using std::set;
using std::multiset;

//void display(set<int> &setInt)
void display(multiset<int, std::greater<int> > & setInt)
{
	multiset<int>::iterator it=setInt.begin();
	for(;it!=setInt.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

class Point
{
	public:
		Point(int ix,int iy)
		:_ix(ix)
		,_iy(iy)
		{}

		friend ostream & operator<<(ostream & os,const Point & rhs);
		friend bool operator<(const Point & lhs,const Point & rhs);
	private:
		int _ix;
		int _iy;
};

ostream & operator<<(ostream & os,const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

//重载小于符号
bool operator<(const Point & lhs, const Point & rhs)
{
	if(lhs._ix < rhs._iy)
		return true;
	else
		return false;
}

void display(multiset<Point> & setInt)
{
	multiset<Point>::iterator it = setInt.begin();
	for(; it != setInt.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	int arr[9]={2, 1, 3, 5, 4, 6, 3, 5, 6};
//	set<int> setInt(arr,arr+9);
	multiset<int,std::greater<int> > setInt(arr,arr+9);
	cout << "setInt's size = " << setInt.size() << endl;
	display(setInt);

	Point arrpoint[4]=
	{
		Point(1,2),
		Point(5,6),
		Point(3,4),
		Point(7,8)
	};
	multiset<Point> setPoint(arrpoint,arrpoint+4);
	display(setPoint);

	return 0;
}
