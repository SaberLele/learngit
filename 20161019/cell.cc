 ///
 /// @file    cell.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-19 17:33:54
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Cell
{
public:
	Cell()
	: f(b)
	, g(d)
	{
	}

private:         //内存字节对齐
	int a;       // 4
	char b;		 // 1
	float c;	 // 4
	double d;	 // 8
	short e[5];	 // 10
	char & f;	 // 一个指针的大小
	double & g; 
	static int h;// 4 , static数据成员不会占据对象的存储空间
};

int Cell::h = 0;

int main(void)
{
	cout << "sizeof(Cell) = " << sizeof(Cell) << endl;

	return 0;
}
