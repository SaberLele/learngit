 ///
 /// @file    10_1.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-17 18:35:54
 ///
 
#include <iostream>
#include <vector>
#include <utility>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::pair;
using std::string;

int main()
{
	pair<string,int> auth;
	vector<pair<string, int> > pvec;

	while(cin >> auth.first >> auth.second)
	{
		pvec.push_back(auth);
		if(auth.first == "q")
		{
			break;
		}
	}

	for(auto & elem : pvec)
	{
		cout << elem.first << " " << elem.second << " ";
	}

	cout << endl;
}
