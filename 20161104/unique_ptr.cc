 ///
 /// @file    unique_ptr.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-04 06:27:09
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

unique_ptr<int> getvalue()
{
	unique_ptr<int> p(new int(88));
	return p;
}

int main()
{
	double *pd=new double(6.66);
	unique_ptr<double> ap(pd);

	cout << "*pd=" << *pd << endl;
	cout << "*ap=" << *ap << endl;
	cout << "pd= " << pd << endl;
	cout << "ap= " << ap.get() << endl;
	cout << endl;
	
	unique_ptr<int> p1=getvalue();
	cout << "*p1=" << *p1 << endl;

	vector<unique_ptr<int> > vec;
	vec.push_back(std::move(p1));

}
