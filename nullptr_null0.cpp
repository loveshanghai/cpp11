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

	//nullptr������ʽת��Ϊchar*
	char* cp = nullptr;
	//����ת��Ϊint�����κ�����Ҳ����ת��Ϊnullptr_t,
	//���´��벻��ͨ������
	//int n1 = nullptr;
	//int n2 = reinterpret_cast<int>(nullptr);
	//nullptr��nullptr_t���ͱ����������Ƚϣ���ʹ��== <= >=���ϱȽ�ʱ����true
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
	//����ת��Ϊint��bool���ͣ����´��벻��ͨ������
	//if(0==nullptr);
	//if(nullptr);
	//�����Խ����������㣬���´��벻��ͨ������
	//nullptr+=1;
	//���´����������������
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
	//printf("%x\n",&nullptr);//����C++11�ı�׼�趨�������޷�ͨ������
	printf("%d\n", my_null == nullptr);//vs2019��ʾΪ0 �л�����ʾΪ1 �˴���Ϊһ���ɻ�
	const nullptr_t&& default_nullptr = nullptr;//default_nullptr��nullptr��һ����ֵ����
	printf("%p\n", &default_nullptr);
	return 0;
}