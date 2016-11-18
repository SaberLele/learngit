 ///
 /// @file    factory1.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-13 05:00:54
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Product
{
	public:
		Product()
		{
			cout << "Product()" << endl;
		}
		virtual ~Product()
		{
			cout << "virtual ~Product()" << endl;
		}
};

class ConcreteProduct
:public Product
{
	public:
		ConcreteProduct()
		{
			cout << "ConcreteProduct()" << endl; 
		}
		virtual ~ConcreteProduct()
		{
			cout << "virtual ~ConcreteProduct()" << endl;
		}
};

class Creator
{
	public:
		Creator()
		{
			cout << "Creator()" << endl;
		}
		virtual ~Creator()
		{
			cout << "virtual ~Creator()" << endl;
		}
		void AnOperation()
		{
			Product *p=FactoryMethod();
			cout << "an operation of Product" << endl;
		}
	protected:
		virtual Product *FactoryMethod()=0;
};

class ConcreteCreator
:public Creator
{
	public:
		ConcreteCreator()
		{
			cout << "construction of ConcreateCreator" << endl;
		}
		virtual ~ConcreteCreator()
		{
			cout << "destruction of ConcreateCreator" << endl;
		}
	protected:
		Product *FactoryMethod()
		{
			return new ConcreteProduct;
		}
};

int main()
{
	Creator *p=new ConcreteCreator();
	p->AnOperation();

	delete p;

	return 0;
}
