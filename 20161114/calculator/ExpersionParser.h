 ///
 /// @file    ExpersionParser.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-14 05:11:25
 ///

#ifndef __EXPRESSION_PARSER_H__
#define __EXPRESSION_PARSER_H__
#include "Node.h"
#include "Scanner.h"
#include <iostream>
using std::cout;
using std::endl;

enum Status
{
	STATUS_OK,
	STATUS_ERROR,
	STATUS_QUIT
};

class Node;
class Scanner;

class ExpressionParser
{
	public:
		ExpressionParser(Scanner & scanner)
		:_scanner(scanner)
		,_root(nullptr)
		,_status(STATUS_OK)
		{}
#if 0
		~ExpressionParser()
		{
			delete _root;
		}
#endif
		void parse();
		double calculate() const;

//		Node * expr();
//		Node * term();
//		Node * factor();
		shared_ptr<Node> expr();
		shared_ptr<Node> term();
		shared_ptr<Node> factor();
	private:
		Scanner & _scanner;
	//	Node * _root;
		shared_ptr<Node> _root;
		Status _status;
};

#endif
