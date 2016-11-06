 ///
 /// @file    weak_ptr2.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-06 05:24:07
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::weak_ptr;
using std::shared_ptr;

class X
{
	public:
		X()
		{
			cout << "X()" << endl;
		}
		~X()
		{
			cout << "~X()" << endl;
		}
		void func()
		{
			cout << "X::func()" << endl;
		}
};

int main()
{
//	shared_ptr<X> p;
	//shared_ptr<X> p2(new X);
	//cout << "p2's use_count = " << p2.use_count() << endl;
#if 1 

	weak_ptr<X> p;
	shared_ptr<X> p2(new X);
	cout << "p2's use_count = " << p2.use_count() << endl;
	p=p2;
	cout << "p2's use_count = " << p2.use_count() << endl;
	shared_ptr<X> p3=p.lock();
	cout << "p2's use_count = " << p2.use_count() << endl;
	if(p3)
	{
		p3->func();
	}
	else
	{
		cout << "managed object is destroyed!" << endl;
	}
#endif
#if 0
	weak_ptr<X> p;
#if 0
	{
		shared_ptr<X> p2(new X);
		cout << "p2's use_count = " << p2.use_count() << endl;

		p=p2;
		cout << "p2's use_count = " << p2.use_count() << endl;

		shared_ptr<X> p3=p.lock();
		cout << "p2's use_count = " << p2.use_count() << endl;
		
		if(p3)
		{
			p3->func();
		}
		else
		{
			cout << "managed object is destroyed!" << endl;
		}
	}
#endif
	shared_ptr<X> p4=p.lock();
	if(p4)
	{
		p4->func();
	}
	else
	{
		cout << "managed object is destroyed!" << endl;
	}
#endif
	
}
