 ///
 /// @file    NullPointCall.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-19 17:52:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class NullPointCall
{
public:
	static void test1();
	void test2();
	void test3(int ix);
	void test4();
private:
	int _ix;
	static int _iy;
};

int NullPointCall::_iy = 0;

void NullPointCall::test1()
{
	cout << "_iy = " << _iy << endl;
}

void NullPointCall::test2()
{
	cout << "very cool!" << endl;
}

void NullPointCall::test3(int ix)
{
	cout << "ix = " << ix << endl;
}

void NullPointCall::test4()
{//this
	cout << "_ix = " << _ix << endl;
}


int main(void)
{
	NullPointCall * p = NULL;
	p->test1();
	p->test2();
	p->test3(1);
	p->test4();

	return 0;
}
