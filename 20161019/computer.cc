 ///
 /// @file    computer.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-19 05:47:39
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
	public:
		Computer(float price)
		:_price(price)
		{
			_total+=_price;
		}
		~Computer()
		{
			_total-=_price;
		}
		void print()
		{
			cout << "Total = " << _total <<endl;
		}
	private:
		float _price;
		static float _total;
};

float Computer::_total=0;


int main()
{
	Computer com(4000);
	com.print();
	Computer com1(5000);
	com1.print();

	return 0;
}
