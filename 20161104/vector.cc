 ///
 /// @file    vector.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-04 07:02:05
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

template <typename T>
class Vector
{
	public:
		Vector();
		~Vector();

		void push_back(const T & value);
		void pop_back();

		size_t size()
		{
			return _first_free-_elems;
		}
		size_t capacity()
		{
			return _end-_elems;
		}

	private:
		void reallocate();

	private:
		static std::allocator<T> _alloc;
		T * _elems;
		T * _first_free;
		T * _end;
};

template <typename T>
std::allocator<T> Vector<T>::_alloc;

template <typename T>
Vector<T>::Vector()
:_elems(NULL)
,_first_free(NULL)
,_end(NULL)
{
	cout << "Vector()" << endl;
}

template <typename T>
Vector<T>::~Vector()
{
	if(_elems!=_first_free)
	{
		_alloc.destroy(--_first_free);
	}
	_alloc.deallocate(_elems,capacity());
}

template <typename T>
void Vector<T>::push_back(const T & value)
{
	if(size()==capacity())
	{
		reallocate();
	}
	_alloc.construct(_first_free,value);
	++_first_free;
}

template <typename T>
void Vector<T>::pop_back()
{
	if(size())
	{
		_alloc.destory(--_first_free);
	}
}

template <typename T>
void Vector<T>::reallocate()
{
	size_t sz=size();
	size_t newCap = 2 * (sz > 1 ? sz : 1);

	T* ptmp=_alloc.allocate(newCap);

	if(_elems)
	{
		std::uninitialized_copy(_elems,_first_free,ptmp);

		while(_first_free!=_elems)
		{
			_alloc.destroy(--_first_free);
		}
		_alloc.deallocate(_elems,sz);
	}
	_elems=ptmp;
	_first_free=_elems+sz;
	_end=_elems+newCap;
}

int main()
{
	Vector<int> vecInt;
	vecInt.push_back(1);
	cout << "size = " << vecInt.size() << endl;
	cout << "cap  = " << vecInt.capacity() << endl;

	vecInt.push_back(2);
	cout << "size = " << vecInt.size() << endl;
	cout << "cap  = " << vecInt.capacity() << endl;
								
	vecInt.push_back(3);
	cout << "size = " << vecInt.size() << endl;
	cout << "cap  = " << vecInt.capacity() << endl;
	return 0;
}
