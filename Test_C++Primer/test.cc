 ///
 /// @file    test.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-29 06:22:46
 ///

#include <stdlib.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main()
{
	std::string str ("<docid>1</docid>"); 
	std::size_t pos1 = str.find("<docid>");
	std::size_t pos2 = str.find("</docid>");
	string s ="100";
	int i = atoi(s);

	cout << i << endl;

	cout << pos1 << endl;
	cout << pos2 << endl;
	cout << str[pos2-pos1-1] << endl;
}
