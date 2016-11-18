 ///
 /// @file    Node.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-14 03:25:14
 ///

#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <vector>
#include <memory>
using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;

class Node
{
	public:
		virtual double calc() const=0;
//		virtual ~Node(){}
};

class NumberNode
:public Node
{
	public:
		NumberNode(double number)
		:_number(number)
		{
			cout << "NumberNode(double)" << endl;
		}
		~NumberNode()
		{
			cout << "~NumberNode()" << endl;
		}
		double calc() const;
	private:
		const double _number;
};

class UnaryNode
:public Node
{
	public:
	//	UnaryNode(Node* child)
		UnaryNode(shared_ptr<Node> child)
		:_child(child)
		{}
#if 0
		~UnaryNode()
		{
			delete _child;
		}
#endif
	protected:
//		Node * _child;
		shared_ptr<Node> _child;
};

class UminesNode
:public UnaryNode
{
	public:
//		UminesNode(Node* child)
		UminesNode(shared_ptr<Node> child)
		:UnaryNode(child)
		{
			cout << "UminesNode(Node*)" << endl;
		}
		~UminesNode()
		{
			cout << "~UminesNode()" << endl;
		}
		double calc() const;
};

class MultipleNode
:public Node
{
	public:
//		MultipleNode(Node * node)
		MultipleNode(shared_ptr<Node> node)
		{
			appendChild(node,true);
		}
	//	void appendChild(Node * node,bool positive)
		void appendChild(shared_ptr<Node> node, bool positive)
		{
			_childs.push_back(node);
			_positives.push_back(positive);
		}
#if 0
		~MultipleNode()
		{
			for(auto it=_childs.begin();
				it!=_childs.end();
				++it)
			{
				delete *it;
			}
		}
#endif
	protected:
	//	vector<Node *> _childs;
		vector<shared_ptr<Node> > _childs;
		vector<bool> _positives;
};

class SumNode
:public MultipleNode
{
	public:
//		SumNode(Node* node)
	SumNode(shared_ptr<Node> node)
		:MultipleNode(node)
		{}
		double calc() const;
};

class ProductNode
:public MultipleNode
{
	public:
//		ProductNode(Node* node)
		ProductNode(shared_ptr<Node> node)
		:MultipleNode(node)
		{}
		double calc() const;
};

#endif
