 ///
 /// @file    Student.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-20 04:11:35
 ///

#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Student
{
	public:
		Student(int id,const char* name)
		:_id(id)
		,_name(new char[strlen(name)+1])
		{
			cout << "Student(int,const char*)" <<endl;
			strcpy(_name,name);
		}

		void display()
		{
			cout << "学号：" << _id << endl;
			cout << "姓名：" << _name << endl;
		}

		static void* operator new(size_t size)
		{
			cout << "void* operator new(size_t)" << endl;
			void *p=malloc(size);
			return p;
		}

		static void operator delete(void *p)
		{
			cout << "void operator delete(void*)" << endl;
			free(p);
		}
		void destory()
		{
			cout << "destory()" << endl;
			delete this;
		}
	private:
		~Student()
		{
			cout << "~Student()" << endl;
			delete [] _name;
		}
		int _id;
		char* _name;
};

int main()
{
	//只能生成堆对象
	Student *stu=new Student(111,"Mike");
	stu->display();

	//delete stu;     //delete调用不到析构函数
	stu->destory();

	return 0;
}
