 ///
 /// @file    copycontroll.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-07 04:40:11
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		Base(const char * pstr)
		:_pstr(new char[strlen(pstr)+1])
		{
			cout << "Base(const char *)" << endl;
			strcpy(_pstr,pstr);
		}

		Base(const Base & rhs)
		:_pstr(new char[strlen(rhs._pstr)+1])
		{
			cout << "Base(const Base&)" << endl;
			strcpy(_pstr,rhs._pstr);
		}

		Base & operator = (const Base & rhs)
		{
			cout << "Base & operator=(const Base&)" << endl;
			if(this!=&rhs)
			{
				delete []_pstr;
				_pstr=new char[strlen(rhs._pstr)+1];
				strcpy(_pstr,rhs._pstr);
			}
			return *this;
		}

		void display()
		{
			cout << _pstr;
		}
		~Base()
		{
			cout << "~Base()" << endl;
			delete []_pstr;
		}
	private:
		char * _pstr;
};

class Derived : public Base
{
	public:
		Derived(const char * pstr,const char * pstr2)
		:Base(pstr)
		,_pstr2(new char[strlen(pstr2)+1])
		{
			cout << "Derived(const char *,const char *)" << endl;
			strcpy(_pstr2,pstr2);
		}

		Derived(const Derived & rhs)
		:Base(rhs)
		,_pstr2(new char[strlen(rhs._pstr2)+1])
		{
			cout << "Derived(const Derived &)" << endl;
			strcpy(_pstr2,rhs._pstr2);
		}

		Derived & operator=(const Derived & rhs)
		{
			cout << "Derived & operator=(const Derived &rhs)" << endl;
			if(this != &rhs)
			{
				Base::operator=(rhs);
				delete []_pstr2;
				_pstr2=new char[strlen(rhs._pstr2)+1];
				strcpy(_pstr2,rhs._pstr2);
			}
			return *this;
		}
	
		void display()
		{
			Base::display();
			cout << _pstr2 << endl;
		}
	private:
		char * _pstr2;
};

int main()
{
	Derived d1("hello"," ,world");
	d1.display();
	Derived d2(d1);
	d2.display();
	cout << endl;

	Derived d3("shenzhen", ", qinghu");
	d3.display();
	d1=d3;
	d1.display();

	return 0;
}
