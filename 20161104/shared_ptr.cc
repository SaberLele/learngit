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
using std::shared_ptr;
using std::vector;


int main()
{
	double *pd=new double(6.66);
	shared_ptr<double> ap(pd);

	cout << "*pd=" << *pd << endl;
	cout << "*ap=" << *ap << endl;
	cout << "pd= " << pd << endl;
	cout << "ap= " << ap.get() << endl;
	cout << endl;
	
	
	shared_ptr<int> p1(new int(5));
	cout << "up's use_count = " << p1.use_count() << endl;

	vector<shared_ptr<int> > vec;
	vec.push_back(p1);
	cout << "up's use_count = " << p1.use_count() << endl;

	shared_ptr<int> p2(p1);
	cout << "up's use_count = " << p1.use_count() << endl;


}
