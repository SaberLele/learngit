 ///
 /// @file    test.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-14 06:30:18
 ///

#include "Scanner.h"
#include "ExpersionParser.h"
#include <unistd.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	string expr;
	do
	{
		cout << "> ";
		getline(cin,expr);

		Scanner sc(expr);
		ExpressionParser ep(sc);
		ep.parse();
		cout << ep.calculate() << endl;
	}while(1);

	return 0;
}
