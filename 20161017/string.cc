 ///
 /// @file    string.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-17 06:58:12
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main()
{
	string s1="Hello world ";
	string s2="Linux and C++";
	string s3=s1+s2;
	cout << s3 << endl;

	string s4=s3.substr(6,11);    //获得字符串从6位开始长度为11的字符串；
	cout << s4 << endl;

	string s5=s3.substr(s3.find("world"),5);   //获得字符串从world开始之后5位的字符串；
	cout << s5 <<endl;

	cout << s3[0] << endl;
	for(unsigned int i=0;i!=s1.size();i++)
	{
		cout << s3[i] <<endl;
	}
	cout << endl;

	//迭代器
	string::iterator it=s1.begin();
	for(;it!=s1.end();it++)
	{
		cout << *it << endl;
	}
}

