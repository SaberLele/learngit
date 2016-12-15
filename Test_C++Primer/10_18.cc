 ///
 /// @file    10_18.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-22 07:02:17
 ///
 
#include <iostream>
#include <string>
#include <map>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;
using std::vector;
using std::pair;

int main()
{
	map<string, vector<string> > children;
	string surname,childName;

	do
	{
		cout << "Enter surname(Ctrl+z to end):" << endl;
		cin >> surname;
		if(!cin)
			break;

		vector<string> chd;
		pair<map<string, vector<string> >::iterator, bool> ret=
			children.insert(make_pair(surname, chd));

		if(!ret.second)
		{
			cout << "repeated surname" << endl;
			continue;
		}

		cout << "Enter children's name(Ctrl+z to end):" << endl;
		while(cin >> childName)
		{
			ret.first->second.push_back(childName);
		}
		cin.clear();
	}while(cin);


}
