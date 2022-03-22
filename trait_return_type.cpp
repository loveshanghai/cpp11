#include <iostream>
using namespace std;

template<typename T1, typename T2>
auto Sum(const T1& t1, const T2& t2) -> decltype(t1 + t2)
{
	return t1 + t2;
}

template<typename T1, typename T2>
auto Mul(const T1& t1, const T2& t2) -> decltype(t1 * t2)
{
	return t1 * t2;
}

//int(*)()(*)() (void)//vs��ʾ��pf����
int (*(*pf())())() {
	return nullptr;
}

//auto (*)()->int(*)()//һ�����غ���ָ��ĺ���������Ϊa������
//auto pf1()->auto(*)()->int(*)()//һ������a����ָ��ĺ���
auto pf1()->auto(*)()->int(*)() {
	return nullptr;
}

//���¶��ߵȼ�
//auto (*fp)()->int;
//int(*fp)();

//���¶��ߵȼ�
//auto (&fr)()->int;
//int(&fr)();

double foo(int a) 
{
	return (double)a + 0.1;
}

int foo(double b)
{
	return (int)b;
}

template<class T>
auto Forward(T t) -> decltype(foo(t)) 
{
	return foo(t);
}


int trait_return_type()
{
	auto a = 3;
	auto b = 4L;
	auto pi = 3.14;
	auto c = Mul(Sum(a,b),pi);
	cout << c << endl;

	cout << is_same<decltype(pf), decltype(pf1)>::value << endl;

	cout << Forward(2) << endl;
	cout << Forward(0.5) << endl;

	return 0;
}