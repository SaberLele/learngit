 ///
 /// @file    caculator.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-13 18:15:20
 ///
 
#include <iostream>
#include <memory>
#include <string>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::string;

class Operator;
class Node
{
	friend class Operator;
	private:
		virtual double calcu()=0;
};

class Factory;
class Operator
{
	friend class Factory;
	public:
		Operator(const double&);
		double calcu()
		{
			return _ptr->calcu();
		}
	private:
		Operator(shared_ptr<Node> ptr)
		:_ptr(ptr)
		{}
		shared_ptr<Node> _ptr;
};

class Factory
{
	public:
		Operator single(double&);
		Operator add(const Operator& ,const Operator &);
		Operator sub(const Operator& ,const Operator &);
		Operator multiply(const Operator & ,const Operator &);
		Operator divide(const Operator&,const Operator&);
};

class NumberNode
:public Node
{
	friend class Factory;
	public:
		NumberNode(double rhs)
		:_rhs(rhs)
		{}
		double calcu()
		{
			return _rhs;
		}
	private:
		double _rhs;
};

inline Operator::Operator(const double & rhs)
:_ptr(new NumberNode(rhs))
{}

class BinaryNode
:public Node
{
	protected:
		BinaryNode(const Operator & lhs, const Operator & rhs, const string opSym)
		:_lhs(lhs)
		,_rhs(rhs)
		,_opSym(opSym)
		{}
		Operator _lhs,_rhs;
		string _opSym;
};

class Add
:public BinaryNode
{
	friend class Factory;
	private:
		Add(const Operator &left, const Operator &right)
		:BinaryNode(left,right,"+")
		{}
		double calcu()
		{
			return _lhs.calcu()+_rhs.calcu();
		}
};

class Sub
:public BinaryNode
{
	friend class Factory;
	private:
		Sub(const Operator &left, const Operator &right)
		:BinaryNode(left,right,"-")
		{}
		double calcu()
		{
			return _lhs.calcu() - _rhs.calcu();
		}
};

class Multiply
:public BinaryNode
{
	friend class Factory;
	private:
		Multiply(const Operator &left, const Operator &right)
		:BinaryNode(left,right,"*")
		{}
		double calcu()
		{
			return _lhs.calcu() * _rhs.calcu();
		}
};

class Divide
:public BinaryNode
{
	friend class Factory;
	private:
		Divide(const Operator &left, const Operator &right)
		:BinaryNode(left,right,"/")
		{}
		double calcu()
		{
			return _lhs.calcu() / _rhs.calcu();
		}
};

Operator Factory::single(double & rhs)
{
	return shared_ptr<Node>(new NumberNode(rhs));
}

Operator Factory::sub(const Operator & lhs, const Operator & rhs)
{
	return shared_ptr<Node>(new Sub(lhs,rhs));
}

Operator Factory::multiply(const Operator & lhs,const Operator & rhs)
{
	return shared_ptr<Node>(new Multiply(lhs,rhs));
}

Operator Factory::divide(const Operator & lhs,const Operator & rhs)
{
	return shared_ptr<Node>(new Divide(lhs,rhs));
}


int main()
{
	Operator op=Operator(1);
	cout << op.calcu();
}



