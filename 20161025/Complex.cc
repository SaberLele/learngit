 ///
 /// @file    Complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-24 16:28:09
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::cin;

class Complex
{

	friend ostream & operator << (ostream & os,const Complex &rhs);
	friend istream & operator >> (istream & is,Complex &rhs);
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

ostream & operator << (ostream & os,const Complex &rhs)
{
	if(rhs._dreal==0)
	{
		if(rhs._dimag==0)
			os << "0" << endl;
		else
			os << rhs._dimag << "i" << endl;
	}
	else
	{
		if(rhs._dimag>0)
			os << rhs._dreal << "+" << rhs._dimag << "i" << endl;
		else if(rhs._dimag==0)
			os << rhs._dreal << endl;
		else
			os << rhs._dreal << "-" << rhs._dimag << "i" << endl;
	}
	return os;
}

istream & operator >> (istream & is,Complex &rhs)
{
	is >> rhs._dreal;
	while(is.get()!=' ');
	is >> rhs._dimag;
	return is;
}
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

	Complex c5(9,10);
	cout << c1 << endl;
	cin >> c5;
	cout << c5 << endl;
	return 0;
}

