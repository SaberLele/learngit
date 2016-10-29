 ///
 /// @file    testTinyXml.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-27 15:20:59
 ///
 
#include "tinyxml2.h"
#include <iostream>
using std::cout;
using std::endl;

using namespace tinyxml2;


int main(void)
{
	XMLDocument doc;
	doc.LoadFile("dream.xml");

	XMLElement * root = doc.FirstChildElement("PLAY");

	XMLElement * title = root->FirstChildElement("TITLE");

	const char * titleContent = title->GetText();
	cout << titleContent << endl;

	XMLElement * fm = root->FirstChildElement("FM");

	XMLElement * p = fm->FirstChildElement("P");
	const char * pCont = p->GetText();
	cout << pCont << endl;

	while((p = p->NextSiblingElement()))
	{
		pCont = p->GetText();
		cout << pCont << endl;
	}

	return 0;
}
