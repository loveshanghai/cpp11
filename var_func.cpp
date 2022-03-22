#include <iostream>
#include <stdexcept>
#include <cassert>

using namespace std;
void Printf(const char* s)
{
	while (*s)
	{
		if (*s == '%' && *++s != '%')
		{
			throw runtime_error("invalid format string arguments");
		}
		cout << *s++;
	}
}

template<typename T, typename... Args>
void Printf(const char* s, T value, Args... args)
{
	while (*s)
	{
		if (*s == '%' && *++s != '%')
		{
			cout << value;
			return Printf(++s, args...);
		}
		cout << *s++;
	}
	throw runtime_error("extra arguments provided to Printf");
}
template<typename ... T> void DummyWrapper(T... t) {}
template<typename T> T pr(T t)
{
	cout << t;
	return t;
}

template<typename... A>
void VTPrint(A... a)
{
	DummyWrapper(pr(a)...);//包扩展解包为pr(1),pr(", ")...,pr(", abc\n")
};

template<class...A> void Print(A...arg)
{
	assert(false);//非6参数偏特化版本都会默认assert(false)
}

//特化6参数的版本
void Print(int a1, int a2, int a3, int a4, int a5, int a6)
{
	cout << a1 << ", "
		<< a2 << ", "
		<< a3 << ", "
		<< a4 << ", "
		<< a5 << ", "
		<< a6 << ", "
		<< endl;
}

template<class...A> int Vaargs(A...args)
{
	int size = sizeof...(A);
	switch (size)
	{
	case 0:
		Print(99, 99, 99, 99, 99, 99);
		break;
	case 1:
		Print(99, 99, args..., 99, 99, 99);
		break;
	case 2:
		Print(99, 99, args..., 99, 99);
		break;
	case 3:
		Print(args..., 99, 99, 99);
		break;
	case 4:
		Print(99, args..., 99);
		break;
	case 5:
		Print(99, args...);
		break;
	case 6:
		Print(args...);
		break;
	default:
		Print(0, 0, 0, 0, 0, 0);
		break;
	}
	return size;
};

struct A 
{
	A() {}
	A(const A& a) { cout << "Copy Constructed " << __func__ << endl; }
	A(A&& a) noexcept { cout << "Move Constructed " << __func__ << endl; }
};

struct B 
{
	B() {}
	B(const A& a) { cout << "Copy Constructed " << __func__ << endl; }
	B(A&& a) { cout << "Move Constructed " << __func__ << endl; }
};

//变长模板的定义
template<typename... T> struct MultiTypes;
template<typename T1, typename... T>
struct MultiTypes<T1, T...> : public MultiTypes<T...> 
{
	T1 t1;
	MultiTypes<T1, T...>(T1 a, T... b) : t1(a), MultiTypes<T...>(b...) 
	{
		cout << "MultiType<T1, T...>(T1 a, T... b)" << endl;
	}
};

template <> 
struct MultiTypes<> 
{
	MultiTypes<>() 
	{
		cout << "MultiTypes<>()" << endl;
	}
};

//完美转发的变长模板
template<template<typename...> class VariadicType, typename... Args>
VariadicType<Args...> Build(Args&&... args)
{
	return VariadicType<Args...>(std::forward<Args>(args)...);
}

int var_func()
{
	Printf("hello %s\n", string("world"));
	VTPrint(1, ", ", 1.2, ", abc\n");

	//
	Vaargs();
	Vaargs(1);
	Vaargs(1,2);
	Vaargs(1,2,3);
	Vaargs(1,2,3,4);
	Vaargs(1,2,3,4,5);
	Vaargs(1,2,3,4,5,6);
	Vaargs(1,2,3,4,5,6,7);

	A a;
	B b;
	Build<MultiTypes>(a, b);
	return 0;
}