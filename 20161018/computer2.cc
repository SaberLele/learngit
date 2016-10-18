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
		void setBrand(const char* brand);
		void setPrice(float price);
		void print();
	private:
		char _brand[20];
		float  _price;
};

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
	Computer com;
	com.setBrand("Lenovo");
	com.setPrice(5500);
	com.print();

	return 0;
}
