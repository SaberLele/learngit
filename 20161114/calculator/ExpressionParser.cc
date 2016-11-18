 ///
 /// @file    ExpressionParser.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-14 05:20:44
 ///

#include "ExpersionParser.h"
#include "Node.h"
#include "Scanner.h"
#include <assert.h>
#include <iostream>

using std::cout;
using std::endl;

void ExpressionParser::parse()
{
	_root = expr();
}

double ExpressionParser::calculate()const
{
	assert(_root != nullptr);
	if(_status == STATUS_OK)
	{
		return _root->calc();
	}
	else
	{
		return 0;
	}
}

//Node * ExpressionParser::expr()
shared_ptr<Node> ExpressionParser::expr()
{
//	Node* node=term();
	shared_ptr<Node> node = term();
	EToken etoken=_scanner.token();
	if(etoken == TOKEN_PLUS || etoken == TOKEN_MINUS)
	{
		//MultipleNode * multiNode=new SumNode(node);
		shared_ptr<MultipleNode> multiNode(new SumNode(node));
		do
		{
			_scanner.scan();
		//	Node* nextNode=term();
			shared_ptr<Node> nextNode = term();
			multiNode->appendChild(nextNode,(etoken==TOKEN_PLUS));
			etoken=_scanner.token();
		}while(etoken == TOKEN_PLUS || etoken == TOKEN_MINUS);
		node = multiNode;
	}
	return node;
}

//Node * ExpressionParser::term()
shared_ptr<Node> ExpressionParser::term()
{
	//Node* node = factor();
	shared_ptr<Node> node = factor();
	EToken etoken = _scanner.token();
	if(TOKEN_MULTIPLY == etoken || TOKEN_DIVIDE == etoken)
	{
		//MultipleNode* multiNode = new ProductNode(node);
		shared_ptr<MultipleNode> multiNode(new ProductNode(node));
		do
		{
			_scanner.scan();
			//Node * nextNode = factor();
			shared_ptr<Node> nextNode = factor();
			multiNode->appendChild(nextNode,(etoken==TOKEN_MULTIPLY));
			etoken = _scanner.token();
		}while(etoken == TOKEN_MULTIPLY||etoken == TOKEN_DIVIDE);
		node=multiNode;
	}
	return node;
}

//Node * ExpressionParser::factor()
shared_ptr<Node> ExpressionParser::factor()
{
//	Node * node = nullptr;
	shared_ptr<Node> node = nullptr;
	EToken etoken = _scanner.token();
	if(TOKEN_LPARENTHESIS == etoken)
	{
		_scanner.scan();
		node = expr();
		if(_scanner.token() == TOKEN_RPARENTHESIS)
		{
			_scanner.scan();
		}
		else
		{
			_status = STATUS_ERROR;
			cout << "missing parenthesis" << endl;
			node = nullptr;
		}
	}
	else if(TOKEN_NUMBER == etoken)
	{
		node.reset(new NumberNode(_scanner.number()));
		_scanner.scan();
	}
	else if(TOKEN_MINUS == etoken)
	{
		_scanner.scan();
		node.reset(new UminesNode(factor()));
	}
	else
	{
		_status = STATUS_ERROR;
		cout << "it is not a valid expression!" << endl;
		node = nullptr;
	}
	return node;
}

