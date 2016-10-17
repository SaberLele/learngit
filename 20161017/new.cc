 ///
 /// @file    new.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-17 05:53:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int* pa=new int(3);
	cout << "*pa= " << *pa << endl;
	delete(pa);

	//开辟数组空间
	int* pb=new int[10]();
	for(int i=0;i<10;i++)
	{
		cout << pb[i] << endl;
	}

	delete(pb);
}
