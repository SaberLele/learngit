 ///
 /// @file    multiDerivedVirtual.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-08 05:05:44
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
	public:
		virtual void a()
		{	cout << "A::a()" << endl;	}
		virtual void b()
		{	cout << "A::b()" << endl;	}
		virtual void c()
		{	cout << "A::c()" << endl;	}
};

class B
{
	public:
		virtual void a()
		{	cout << "B::a()" << endl;	}
		virtual void b()
		{	cout << "B::b()" << endl;	}
		void c()
		{	cout << "B::c()" << endl;	}
		void d()
		{	cout << "B::D()" << endl;	}	
};

class C
:public A
,public B
{
	public:
		virtual void a()
		{	cout << "C::a()" << endl;	}
		void c()
		{	cout << "C::c()" << endl;	}
		void d()
		{	cout << "C::d()" << endl;	}
};

int main()
{
	cout << "sizeof(A) = " << sizeof(A) << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;
	cout << "sizeof(C) = " << sizeof(C) << endl;

	C c;
	A * pa=&c;
	pa->a();
	pa->b();
	pa->c();
	cout << endl;

	B * pb=&c;
	pb->a();
	pb->b();
	pb->c();
	pb->d();
	cout << endl;

	C * pc=&c;
	pc->a();
	pc->c();
	pc->d();

	return 0;
}
