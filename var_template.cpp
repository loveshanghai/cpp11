#include <iostream>
#include <cstdio>
#include <tuple>
using namespace std;

template<long... nums> struct Multiply;
template<long first, long... last>
struct Multiply<first, last...> 
{
	static const long val = first * Multiply<last...>::val;
};

template<>
struct Multiply<> 
{
	static const long val = 1;
};

template<typename A, typename B> struct S {};
//两个模板参数包
template<
template<typename... > class T, typename... TArgs,
template<typename... > class U, typename... UArgs> 
struct S<T<TArgs...>, U<UArgs...>> {};

int var_template()
{
	cout << Multiply<2, 3, 4, 5>::val << endl;
	cout << Multiply<22, 44, 66, 88, 9>::val << endl;

	S<int, float> p;
	S<std::tuple<int, char>, std::tuple<float>> s;
	return 0;
}