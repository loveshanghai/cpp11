#include <type_traits>
#include <iostream>
using namespace std;

int lambda_expr()
{
	[] {};//最简单的lambda函数
	int a = 3;
	int b = 4;
	[=] {return a + b; };//省略了参数列表与返回类型，返回类型由编译器推断为int
	auto fun1 = [&](int c) {b = a + c; };
	auto fun2 = [=, &b](int c)->int {return b += a + c; };
	//auto totalChild5 = [=] { return girls + boys; };
	//
	int girls = 3;
	int boys = 4;
	auto totalChild = [](int x, int y) {return x + y; };
	auto totalChild2 = [girls, &boys] {return girls + boys; };
	auto totalChild3 = [=]() { return girls + boys; };
	auto totalChild4 = [=] { return girls + boys; };
	return totalChild(girls, boys);
}