 ///
 /// @file    cow.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-26 01:55:22
 ///

#include "cow.h"
#include <iostream>
using std::cout;
using std::endl;

String::String()
:_pstr(new char[2])
{
	cout << "String()" << endl;
	initRefCnt();
}

String::String(const String  &rhs)   //复制构造函数
:_pstr(rhs._pstr)
{
	cout << "String(const String&)" << endl;
	increaseRefCnt();
}

String::String(const char * pstr)    //有参构造函数
:_pstr(new char[strlen(pstr)+2])
{
	cout << "String(const char*)" << endl;
	strcpy(_pstr,pstr);
	initRefCnt();
}

String::~String()
{
	decreaseRefCnt();
	if(getRefCnt()==0)
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}
}

String & String::operator=(const String & rhs)
{
	if(this!=&rhs)
	{
		decreaseRefCnt();
		if(0==getRefCnt())
		{
			delete [] _pstr;
		}
		_pstr=rhs._pstr;
		increaseRefCnt();
	}
	return *this;
}

String & String:: operator=(const char* pstr)
{
	*this=String(pstr);
	return *this;
}

String & String::operator+=(const String &rhs)
{
	char *tmp=new char[strlen(_pstr)+strlen(rhs._pstr)+1];
	strcpy(tmp,_pstr);
	strcat(tmp,rhs._pstr);
	increaseRefCnt();
	if(getRefCnt()==0)
	{
		delete [] _pstr;
	}
	_pstr=tmp;
	initRefCnt();
	return *this;
}

String & String::operator+=(const char *rhs)
{
	*this+=String(rhs);
	return *this;
}

char & String::operator [] (int index)
{
	static char nullchar='\0';
	if(index>=0 && index < length())
	{
		if(getRefCnt()>1)
		{
			decreaseRefCnt();
			char *tmp=new char[length()+2];
			strcpy(tmp,_pstr);
			_pstr=tmp;
			initRefCnt();
		}
		return _pstr[index];
	}
	else
	{
		cout << "下标越界" << endl;
		return nullchar;
	}
}

bool operator==(const String &lhs,const String &rhs)
{
	return (strcmp(lhs._pstr,rhs._pstr)==0);
}

bool operator!=(const String &lhs,const String &rhs)
{
	return (strcmp(lhs._pstr,rhs._pstr)!=0);
}


bool operator<(const String &lhs,const String &rhs)
{
	return (strcmp(lhs._pstr,rhs._pstr)<0);
}

bool operator>(const String &lhs,const String &rhs)
{
	return (strcmp(lhs._pstr,rhs._pstr)>0);
}


bool operator<=(const String &lhs,const String &rhs)
{
	return (strcmp(lhs._pstr,rhs._pstr)<=0);
}

bool operator>=(const String &lhs,const String &rhs)
{
	return (strcmp(lhs._pstr,rhs._pstr)>=0);
}

int String::length() const
{
	return strlen(_pstr);
}

int String::getRefCnt() const
{
	return _pstr[length()+1];
}

char * String::c_str() const
{
	return _pstr;
}

ostream & operator << (ostream & os,const String & rhs)
{
	os << rhs._pstr;
	return os;
}

istream & operator >> (istream & is, String & rhs)
{
	char buf[65535];
	bzero(buf,sizeof(buf));
	is.getline(buf,sizeof(buf));
	delete [] rhs._pstr;
	rhs._pstr=new char[strlen(buf)+1];
	strcpy(rhs._pstr,buf);
	return is;
}

void String::initRefCnt()
{
	_pstr[length()+1]=1;
}

void String::increaseRefCnt()
{
	++_pstr[length()+1];
}

void String::decreaseRefCnt()
{
	--_pstr[length()+1];
}
