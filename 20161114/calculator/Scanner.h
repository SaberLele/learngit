 ///
 /// @file    Scanner.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-14 04:35:45
 ///

#ifndef __SCANNER_H__
#define __SCANNER_H__

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

enum EToken
{
	TOKEN_END,
	TOKEN_ERROR,
	TOKEN_NUMBER,
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_MULTIPLY,
	TOKEN_DIVIDE,
	TOKEN_LPARENTHESIS,
	TOKEN_RPARENTHESIS,
	TOKEN_IDENTIFIER,
	TOKEN_ASSIGN
};

class Scanner
{
	public:
		Scanner(const string & expr)
		:_expr(expr)
		,_curPos(0)
		,_token(TOKEN_ERROR)
		{
			cout << "Scanner(const string &)" << endl;
			scan();
		}
	
		void scan();
		double number() const;
		EToken token() const;
	private:
		void skipBlank();

	private:
		const string _expr;
		unsigned int _curPos;
		EToken _token;
		double _number;
};

#endif
