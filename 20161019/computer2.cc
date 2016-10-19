 ///
 /// @file    computer.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-19 05:47:39
 ///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
	public:
		Computer(const char * brand,float price)
		:_brand(new char[strlen(brand)+1])
		,_price(price)
		{
			_total+=_price;
			strcpy(_brand,brand);
		}
		~Computer()
		{
			delete [] _brand;
			_total-=_price;
		}
		static void printTotal()
		{
			cout << "Total = " << _total <<endl;
		}
		static void print(Computer & com)
		{
			cout << "品牌：" << com._brand << endl;
			cout << "价格：" << com._price << endl;
		}
	private:
		char * _brand;
		float _price;
		static float _total;
};

float Computer::_total=0;


int main()
{
	Computer com("IBM",4000);
	Computer::print(com);
	com.printTotal();

	Computer com1("Lenovo",5000);
	Computer::print(com1);
	com1.printTotal();

	return 0;
}
