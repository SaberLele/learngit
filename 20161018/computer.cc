 ///
 /// @file    computer.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-18 04:10:47
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	void print()
	{
		cout << "品牌" << _brand << endl;
		cout << "价格" << _price << endl;
	}
	void setBrand(const char* brand)
	{
		strcpy(_brand,brand);
	}
	void setPrice(float price)
	{
		_price=price;
	}

private:   //封装
	char  _brand[20];
	float _price;
};

int main()
{
	Computer com;
	com.setBrand("Lenovo");
	com.setPrice(5000);
	com.print();
}
	
