 ///
 /// @file    io.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-17 07:23:10
 ///
 
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
//	int num;
//	cin >> num;
//	cout << "num=" << num << endl;

	string s1;
//	cin >> s1;
//	cout << "s1=" << s1 << endl;
	
	while(getline(cin, s1))
	{
		cout << "s1=" << s1 << endl;
	}
	return 0;
}
