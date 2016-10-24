 ///
 /// @file    string_operator.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-24 05:44:48
 ///

#include <string.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

class String
{
	public:
		String()
		{
			_pstr=NULL;
			cout << "String()" << endl;
		}

		String(const char* pstr)
		:_pstr(new char[strlen(pstr)+1])
		{
			strcpy(_pstr,pstr);
			cout << "String(const char*)" << endl;
		}

		String(const String& rhs)
		:_pstr(new char[strlen(rhs._pstr)+1])
		{
			strcpy(_pstr,rhs._pstr);
			cout << "String(const String&)" << endl;
		}

		~String()
		{
			cout << "~String()" << endl;
			delete [] _pstr;
		}

		String & operator=(const String &);
		String & operator=(const char*);
		String & operator+=(const String &);
		String & operator+=(const char*);
		
		char &operator[](std::size_t index);
		const char &operator[](std::size_t index) const;

		std::size_t size() const;
		const char* c_str() const;

		friend bool operator==(const String &, const String &);
		friend bool operator!=(const String &, const String &);

		friend bool operator<(const String &, const String &);
		friend bool operator>(const String &, const String &);
		friend bool operator<=(const String &, const String &);
		friend bool operator>=(const String &, const String &);
	
		friend std::ostream &operator<<(std::ostream &os, const String &s);
		friend std::istream &operator>>(std::istream &is, String &s);

	private:
		char *_pstr;
};

String & String::operator=(const String & rhs)
{
	if(this==& rhs)
	{
		return *this;
	}
	else
	{
		delete [] _pstr;
		_pstr=new char[strlen(rhs._pstr)+1];
		strcpy(_pstr,rhs._pstr);
		return *this;
	}
}

String & String::operator=(const char* pstr)
{
	if(this->_pstr==pstr)
	{
		return *this;
	}
	else
	{
		delete [] _pstr;
		_pstr=new char[strlen(pstr)+1];
		strcpy(_pstr,pstr);
		return *this;
	}
}

String & String::operator+=(const String & rhs)
{
	char *s=new char[strlen(_pstr)+strlen(rhs._pstr)+1];
	bzero(s,sizeof(s));
	strcpy(s,_pstr);
	strcat(s,rhs._pstr);
	delete [] _pstr;
	_pstr=s;
	return *this;
}


String & String::operator+=(const char* pstr)
{
	char *s=new char[strlen(_pstr)+strlen(pstr)+1];
	bzero(s,sizeof(s));
	strcpy(s,_pstr);
	strcat(s,pstr);
	delete [] _pstr;
	_pstr=s;
	return *this;
}

char & String::operator[](std::size_t index)
{
	return _pstr[index];
}

const char & String::operator[](std::size_t index) const
{
	return _pstr[index];
}

std::size_t String::size()const
{
	return strlen(_pstr);
}
const char* String::c_str() const
{
	return _pstr;
}

bool operator==(const String & lhs,const String & rhs)
{
	return (strcmp(lhs._pstr,rhs._pstr)==0);	
}

bool operator!=(const String & lhs,const String & rhs)
{
	return (strcmp(lhs._pstr,rhs._pstr)!=0);
}

bool operator<(const String & lhs,const String & rhs)
{
	return (strcmp(lhs._pstr,rhs._pstr)<0);
}

bool operator>(const String & lhs,const String & rhs)
{
	return (strcmp(lhs._pstr,rhs._pstr)>0);
}

bool operator<=(const String & lhs,const String & rhs)
{
	return (strcmp(lhs._pstr,rhs._pstr)<=0);
}

bool operator>=(const String & lhs,const String & rhs)
{
	return (strcmp(lhs._pstr,rhs._pstr)>=0);
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
	os<<s._pstr;
	return os;
}

std::istream &operator>>(std::istream &is, String &s)
{
	string str;
	delete [] s._pstr;
	s._pstr=new char[str.size()+1];
	is >> str;
	strcpy(s._pstr,str.c_str());
	return is;
}


String operator+(const String &lhs, const String &rhs)
{
	String s(lhs);
	return (s+=rhs);
}

String operator+(const String &lhs, const char *pstr)
{
	String s(lhs);
	return (s+=pstr);
}

String operator+(const char *pstr, const String &rhs)
{
	String s=pstr;
	return (s+=rhs);
}

int main()
{
	String s1="123";
	String s2;
	s2=s1;
	String s3="12345";
	String s4="1234";
	String s5;
	String s6;

	s5=s3+s4;
	char p=s2[0];
	cout << "s2[0]=" <<  p << endl;
	
	cout << "s5=s3+s4=" << s5 <<endl;
	if(s1==s2)
	{
		cout << "s1=s2" << endl;
	}
	if(s1<s2)
	{
		cout << "s1<s2" << endl;
	}
	if(s1>s2)
	{
		cout << "s1>s2" << endl;
	}
	cout << "input something" << endl;
	cin >> s6;
	cout << "s6=" << s6 <<endl;
}
