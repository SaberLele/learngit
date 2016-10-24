 ///
 /// @file    Complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-24 16:28:09
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Complex
{
public:
	explicit
	Complex(double dreal, double dimag)
	: _dreal(dreal)
	, _dimag(dimag)
	{
	
	}
	
	void display() const
	{
		if(_dreal == 0)
		{
			if(_dimag == 0)
				cout << "0" << endl;
			else
				cout << _dimag << "i" << endl;
		}
		else
		{	
			if(_dimag > 0)
				cout << _dreal << " + " << _dimag << "i" << endl;
			else if(_dimag == 0)
				cout << _dreal << endl;
			else 
				cout << _dreal << " - " << _dimag * (-1) << "i" << endl;
		}
	}

	Complex & operator ++()
	{
		++_dreal;
		++_dimag;
		return *this;
	}

	Complex  operator ++(int)
	{
		Complex tmp(*this);
		++_dreal;
		++_dimag;
		return tmp;
	}

	Complex & operator+=(const Complex & rhs)
	{
		_dreal += rhs._dreal;
		_dimag += rhs._dimag;
		return *this;
	}

	double getReal() const
	{
		return _dreal;
	}
	double getImage() const
	{
		return _dimag;
	}
private:
	double _dreal;
	double _dimag;
};

#if 0
//内置类型的云算符不能进行重载
//只能针对于自定义类类型或者枚举类型
int operator + (int a, int b)
{
	retuan a - b;
}
#endif

//已自由函数形式进行重载
Complex operator+(const Complex & lhs,const Complex & rhs)
{
//	return Complex(lhs.getReal()+rhs.getReal(),
//			lhs.getImage()+rhs.getImage());
	Complex tmp(lhs);
	tmp+=rhs;
	return tmp;
}

int main(void)
{
	Complex c1(3, 4);
	Complex c2(-3, -4);
	Complex c3(0, -4);

	c1.display();
	c2.display();
	c3.display();

	c3 = c1 + c2;
	c3.display();

//	cout << sizeof(int) << endl;
//	cout << sizeof c1 << endl;//sizeof不是函数，是关键字

	Complex c4(1,1);
	c1.display();
	cout << "前置++ 的值:";
	(++c4).display();
	c4.display();

	cout << "后置++ 的值:";
	(c4++).display();
	c4.display();


	return 0;
}

