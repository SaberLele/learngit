 ///
 /// @file    match.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-18 19:25:17
 ///
 //实现字符串通配符（*、？）

//#include <stdio.h>
//#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;
//using std::cout;
//using std::endl;

bool same(char a,char b)
{
	if(isalpha(a) && isalpha(b))
	{
		char c=a;
		char d=b;
		if(isupper(a))
			c=(char)tolower(a);
		if(isupper(b))
			d=(char)tolower(b);
		if(c==d)
			return true;
		else
			return false;
	}
	else if(a==b)
		return true;
	return false;
}

bool match_char(char *input,char *pput)
{
	char *p=input;  //通配字符串
	char *q=pput;   //匹配字符串

	while(*p!='\0')
	{
		if((same(*p,*q)) || (*p=='?'))
		{
			p++;
			q++;
		}
		else
		{
			if(*p=='*')
			{
				q++;
				char *p1=p+1;
				if(*p1=='\0' || (!same(*p1,*q)))
					q++;
				else
					p=p+2;
			}else
				return false;
		}
	}
	return true;
}

int main()
{

	char input[50]="T?t*.*";
	char pput[50]="txt12.xls";
//	fgets(input,sizeof(input),0);
//	fgets(pput,sizeof(pput),0);
	if(match_char(input,pput))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}
