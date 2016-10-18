 ///
 /// @file    computer2.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-18 04:25:23
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
	public:
		Computer(const char* brand,float price);
		Computer(const Computer & rhs);
		~Computer();

		void setBrand(const char* brand);
		void setPrice(float price);
		void print();
	private:
		char* _brand;
		float  _price;
};

Computer::Computer(const char* brand,float price)
:_brand(new char[strlen(brand)+1])
,_price(price)
{
	cout << "Computer(const char*,float)" << endl;
	strcpy(_brand,brand);
}

Computer::Computer(const Computer & rhs)
:_brand(new char[strlen(rhs._brand)+1])
,_price(rhs._price)
{
	cout << "Computer(const Computer &)" << endl;
	strcpy(_brand,rhs._brand);   //深拷贝
}

Computer::~Computer()
{
	cout << "~Computer()" << endl;
	delete [] _brand;
}

void Computer::setBrand(const char* brand)
{
	strcpy(_brand,brand);
}
void Computer::setPrice(float price)
{
	_price=price;
}
void Computer::print()
{
	cout << "品牌：" << _brand << endl;
	cout << "价格：" << _price << endl;
}

int main()
{
	Computer com("Lenovo",5000);
	com.print();

	Computer pc(com);
	pc.print();
	return 0;
}
