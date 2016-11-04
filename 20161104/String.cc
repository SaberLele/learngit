 ///
 /// @file    String.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-04 03:59:49
 ///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class String
{
	public:
		String()
		:_pstr(new char[1])
		{
			cout << "String()" << endl;
		}
		String(const char * pstr)
		:_pstr(new char[strlen(pstr)+1])
		{
			strcpy(_pstr,pstr);
			cout << "String(const char *)" << endl;
		}
		~String()
		{
			delete []_pstr;
			cout << "~String()" << endl;
		}
		String(const String & rhs)
		:_pstr(new char[strlen(rhs._pstr)+1])
		{
			strcpy(_pstr,rhs._pstr);
			cout << "String(const String &)" << endl;
		}

		String(String && rhs)
		:_pstr(rhs._pstr)
		{
			rhs._pstr = nullptr;
			cout << "String(String && rhs)" << endl;
		}

		String & operator = (const String & rhs)
		{
			cout << "String & operator=(const String &)" << endl;
			if(this!=&rhs)
			{
				delete []_pstr;
				_pstr=new char[strlen(rhs._pstr)+1];
				strcpy(_pstr,rhs._pstr);
			}
			return *this;
		}
		String & operator = (String && rhs)
		{
			cout << "String & operator=(String && rhs)" << endl;
			delete []_pstr;
			_pstr=rhs._pstr;
			rhs._pstr=nullptr;
			return *this;
		}

		friend ostream & operator << (ostream & os,const String & rhs);

	private:
		char * _pstr;
};

ostream & operator << (ostream & os,const String & rhs)
{
	os << rhs._pstr;
	return os;
}

int main()
{
	String s1="hello";
	cout << "s1=" << s1 << endl;
	String s2=s1;
	cout << "s2=" << s2 << endl;

	String s3=String("shenzhen");
	cout << "s3=" << s3 << endl;

	s3="wangdao";
	cout << "s3=" << s3 << endl;

	return 0;
}
