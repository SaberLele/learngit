 ///
 /// @file    String.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-18 07:27:11
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	String();
	String(const char *pstr);
	String(const String & rhs);
	String & operator=(const String &rhs)
	{
		if(this!=&rhs)
		{
			delete [] _pstr;
			_pstr=new char[strlen(rhs._pstr)+1];
			strcpy(_pstr,rhs._pstr);
		}
		return *this;
	}
	~String();

	void print();
private:
	char* _pstr;
};

String::String()
:_pstr(new char[strlen("hello")+1])
{
	cout << "String()" << endl;
	strcpy(_pstr,"hello");
}

String::String(const char* pstr)
:_pstr(new char[strlen(pstr)+1])
{
	cout << "String(const char*)" << endl;
	strcpy(_pstr,pstr);
}

String::String(const String & rhs)
:_pstr(new char[strlen(rhs._pstr)+1])
{
	strcpy(_pstr,rhs._pstr);	
}

String::~String()
{
	cout << "~String()" << endl;
	delete [] _pstr;
}

void String::print()
{
	cout << _pstr <<endl;
}

int main()
{
	String str1;
	str1.print();

	String str2="Hello,world";
	String str3="wangdao";

	str2.print();
	str3.print();

	str2=str3;
	str2.print();

	String str4=str3;
	str4.print();
	return 0;
}
