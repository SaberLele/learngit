 ///
 /// @file    virtualDestructor.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-08 04:56:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		Base()
		:_pstr(new char[64])
		{
			cout << "Base()" << endl;
		}
		virtual
		~Base()
		{
			cout << "~Base()" << endl;
			delete []_pstr;
		}
	private:
		char * _pstr;
};

class Child:public Base
{
	public:
		Child()
		:Base()
		,_pCdata(new char[64])
		{
			cout << "Child()" << endl;
		}
		~Child()
		{
			cout << "~Child()" << endl;
			delete []_pCdata;
		}
	private:
		char *_pCdata;
};

int main()
{
	cout << "sizeof(Child) = " << sizeof(Child) << endl;

	Base * pbase=new Child;
	delete pbase;
}
