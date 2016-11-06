 ///
 /// @file    vector.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-02 01:42:55
 ///

#include <memory>
#include <iostream>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;

template <typename T>
class Vector
{
	public:
		Vector();
		~Vector();

		void push_back(const T &);

		int size();
		int capacity();

		void reallocate();
	private:
		static std::allocator<T> _allo;
		T* _elems;
		T* _end;
		T* _first_free;
};

template <typename T>
std::allocator<T> Vector<T>::_allo;

template <typename T>
Vector<T>::Vector()
:_elems(NULL)
,_end(NULL)
,_first_free(NULL)
{
}

template <typename T>
Vector<T>::~Vector()
{
	while(_first_free!=_elems)
	{
		_allo.destroy(--_first_free);
	}
	_allo.deallocate(_elems,capacity());
}

template <typename T>
void Vector<T>::push_back(const T & rhs)
{
	if(_end==_first_free)
	{
		reallocate();
	}
	_allo.construct(_first_free,rhs);
	++_first_free;
}

template <typename T>
int Vector<T>::size()
{
	return _first_free-_elems;
}

template <typename T>
int Vector<T>::capacity()
{
	return _end-_elems;
}

template <typename T>
void Vector<T>::reallocate()
{
	if(!_elems)
	{
		_elems=_allo.allocate(1);
		_first_free=_elems;
		_end=_elems+1;
	}
	else
	{
		int new_capacity=2*size();
		T * new_elems=_allo.allocate(new_capacity);
		T * new_first_free=std::uninitialized_copy(_elems,_first_free,new_elems);

		while(_first_free!=_elems)
		{
			_allo.destroy(--_first_free);
		}
		_allo.deallocate(_elems,capacity());

		_elems=new_elems;
		_first_free=new_first_free;
		_end=_elems+new_capacity;

	}	
}

int main()
{
	Vector<int> vecInt;

	cout<<"size : "<<vecInt.size()<<endl;
	cout<<"capacity : "<<vecInt.capacity()<<endl;

	vecInt.push_back(100);
	vecInt.push_back(101);
	vecInt.push_back(102);
	cout<<"size : "<<vecInt.size()<<endl;
	cout<<"capacity : "<<vecInt.capacity()<<endl;
	vecInt.push_back(103);
	vecInt.push_back(105);
	cout<<"size : "<<vecInt.size()<<endl;
	cout<<"capacity : "<<vecInt.capacity()<<endl;
	return 0;
}
