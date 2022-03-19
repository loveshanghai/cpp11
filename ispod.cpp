#include <iostream>
#include <type_traits>

using namespace std;

union U {};
union U1 { U1() {} };
enum E {};
typedef double* DA;
typedef void(*PF)(int, double);

int ispod()
{
	cout << is_pod<U>::value << endl;//1
	cout << is_pod<U1>::value << endl;//0
	cout << is_pod<E>::value << endl;//1
	cout << is_pod<int>::value << endl;//1
	cout << is_pod<DA>::value << endl;//1
	cout << is_pod<PF>::value << endl;//1

	return 0;
}



