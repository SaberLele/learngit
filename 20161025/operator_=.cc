 ///
 /// @file    operator_=.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-25 00:35:05
 ///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
	public:
		Computer()
		{
			_brand=NULL;
			_price=0;
			cout << "Computer()" <<endl;
		}

		Computer(const char* brand,float price)
		:_brand(new char[strlen(brand)+1])
		,_price(price)
		{
			strcpy(_brand,brand);
			cout << "Computer(char*,float)" <<endl;
		}
		
		~Computer()
		{
			cout << "~Computer" << endl;
			delete [] _brand;
		}

		Computer(const Computer & rhs)
		:_brand(new char[strlen(rhs._brand)+1])
		,_price(rhs._price)
		{
			strcpy(_brand,rhs._brand);
			cout << "Computer(const Computer&)" << endl;
		}

		Computer & operator =(const Computer &rhs)
		{
			if(this==&rhs)
			{
				return *this;
			}
			delete [] _brand;
			_brand=new char[strlen(rhs._brand)+1];
			strcpy(_brand,rhs._brand);
			_price=rhs._price;
			cout << "赋值运算符重载函数被调用" << endl;
			return *this;
		}
		void print()
		{
			cout << _brand << "-->" << _price <<endl;
		}

	private:
		char* _brand;
		float _price;
};

int main ()
{
	Computer com("Lenovo",5000);
	com.print();
	Computer com2;
	com2=com;
	com2.print();
	Computer com3 = com;
	com3.print();
	return 0;
}
