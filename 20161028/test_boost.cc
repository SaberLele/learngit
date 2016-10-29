 ///
 /// @file    test_boost.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-28 00:53:28
 ///

#include <boost/regex.hpp>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int test()
{
	boost::regex re("Chapter [1-9][0-9]*");
	string s1="Chapter 1000";

	bool bflag=boost::regex_match(s1, re);
	cout << "bflag= " << bflag << endl;

	return 0;
}

void test1()
{
	boost::regex re("<.*?>");
	string s1 = "<H1>Chapter 1- Introduction to Regular Expressions</H1>";
	cout << boost::regex_replace(s1, re, string("")) << endl;
}
int main(void)
{
	test1();
	return 0;
}

