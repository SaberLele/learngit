 ///
 /// @file    shared_ptr_error.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-06 05:51:57
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

class Point
//shared_from_this()是enable_shared_from_this<T>的成员函数，返回shared_ptr<T>
//enable_shared_from_this::weak_ptr并不在构造函数中设置，
//而是在shared_ptr<T>的构造函数中设置,
//所以,shared_from_this()必须在shared_ptr<T>的构造函数被调用之后才能使用;
:public std::enable_shared_from_this<Point>
{
	public:
		Point(int ix,int iy)
		:_ix(ix)
		,_iy(iy)
		{
			cout << "Point(int,int)" << endl;
		}
		~Point()
		{
			cout << "~Point" << endl;
		}
#if 0
		Point * add(const Point * rhs)
		{
			_ix += rhs->_ix;
			_iy += rhs->_iy;

			return this;
		}
#endif
		shared_ptr<Point> add(const Point * rhs)
		{
			_ix += rhs->_ix;
			_iy += rhs->_iy;

			return shared_from_this();
		}
	private:
		int _ix;
		int _iy;
};

int test1()
{
#if 0
	//当p1,p2离开作用域时，由于p1,p2的引用计数都为0，会导致两次释放同一块内存
	Point * pt=new Point(1,2);
	shared_ptr<Point> p1(pt);
	shared_ptr<Point> p2(pt);
#endif

	shared_ptr<Point> p1(new Point(1,2));
	shared_ptr<Point> p2(p1);

	cout << "p1's use_count = " << p1.use_count() << endl;
	cout << "p2's use_count = " << p2.use_count() << endl;

	return 0;
}

int test2()
{
	shared_ptr<Point> p1(new Point(1, 2));
	shared_ptr<Point> p2(new Point(3, 4));

	//避免使用裸指针
	//p2.reset(p1.get());
	p2.reset();
	p2=p1;
}

int test3()
{
	shared_ptr<Point> p1(new Point(1, 2));
	shared_ptr<Point> p2(new Point(3, 4));

	shared_ptr<Point> p3(p2->add(p1.get()));
}
int main()
{
	//test1();
	//test2();
	test3();

	return 0;
}
