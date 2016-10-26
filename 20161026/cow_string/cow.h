 ///
 /// @file    cow.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-26 01:41:55
 ///

#ifndef __COW_H__
#define __COW_H__

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

class String
{
	public:
		String();
		String(const String &);
		String(const char *);
		~String();

		String & operator = (const String &);
		String & operator = (const char*);

		String &operator+=(const String&);
		String &operator+=(const char*);


		char & operator [](int);
		const char &operator[](int) const;

		friend bool operator==(const String &,const String&);
		friend bool operator!=(const String &,const String&);

		friend bool operator<(const String&,const String&);	
		friend bool operator>(const String&,const String&);	
		friend bool operator<=(const String&,const String&);	
		friend bool operator>=(const String&,const String&);	

		int length() const;
		int getRefCnt() const;
		char * c_str() const;
	private:
		friend ostream & operator << (ostream &,const String &);
		friend istream & operator >> (istream &,String &);
		void initRefCnt();
		void increaseRefCnt();
		void decreaseRefCnt();
	private:
		char* _pstr;
};
#endif
