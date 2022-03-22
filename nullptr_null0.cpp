#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

void fun0(char* c)
{
	printf("invoke f(char*)\n");
}
void fun0(int i)
{
	printf("invoke f(int)\n");
}

template<typename T> void g(T* t) { /*cout << typeid(T) << endl;*/ }
template<typename T> void h(T t) { /*cout << typeid(T) << endl;*/ }

int nullptr_null0()
{
	fun0(0);//invoke f(int)
	fun0(NULL);//invoke f(int)
	fun0((char*)0);//invoke f(char*)
	fun0(nullptr);//invoke f(char*)

	//nullptr可以隐式转换为char*
	char* cp = nullptr;
	//不可转换为int，而任何类型也不能转换为nullptr_t,
	//以下代码不能通过编译
	//int n1 = nullptr;
	//int n2 = reinterpret_cast<int>(nullptr);
	//nullptr与nullptr_t类型变量可以作比较，当使用== <= >=符合比较时返回true
	nullptr_t nptr=nullptr;
	if (nptr == 0) {}
	if (nullptr == 0) {}
	if (nptr == nullptr)
	{
		cout << "nullptr_t nptr == nullptr" << endl;
	}
	else
	{
		cout << "nullptr_t nptr != nullptr" << endl;
	}
	//if (nptr < nullptr)
	//{
	//	cout << "nullptr_t nptr<nullptr" << endl;
	//}
	//else
	//{
	//	cout << "nullptr_t nptr>=nullptr" << endl;
	//}
	//不能转换为int或bool类型，以下代码不能通过编译
	//if(0==nullptr);
	//if(nullptr);
	//不可以进行算数运算，以下代码不能通过编译
	//nullptr+=1;
	//以下代码均可以正常进行
	cout << "sizeof(nullptr)=" << sizeof(nullptr) << endl;
	cout << "sizeof(nullptr_t)=" << sizeof(nullptr_t) << endl;
	cout << "sizeof(void*)=" << sizeof(void*) << endl;
	//cout << "typeid(nullptr)=" << typeid(nullptr) << endl;
	//throw(nullptr);

	//g(nullptr);
	g((float*)nullptr);
	h(0);
	h(nullptr);
	h((float*)nullptr);

	//
	nullptr_t my_null;
	printf("%p\n", &my_null);
	//printf("%x\n",&nullptr);//根据C++11的标准设定，本句无法通过编译
	printf("%d\n", my_null == nullptr);//vs2019显示为0 有环境显示为1 此处是为一个疑惑
	const nullptr_t&& default_nullptr = nullptr;//default_nullptr是nullptr的一个右值引用
	printf("%p\n", &default_nullptr);
	return 0;
}