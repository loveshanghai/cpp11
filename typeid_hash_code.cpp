#include <iostream>
#include <type_traits>

using namespace std;

class White {};
class Black {};

int typeid_hash_code()
{
	White a;
	Black b;

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;

	White c;

	bool a_b_sametype = (typeid(a).hash_code() == typeid(b).hash_code());
	bool a_c_sametype = (typeid(a).hash_code() == typeid(c).hash_code());

	int i;
	decltype(i) j = 0;
	cout << typeid(j).name() << endl;
	float a1;
	double b1;
	decltype(a1 + b1) c1;
	cout << typeid(c1).name() << endl;

	using size_t = decltype(sizeof(0));
	using ptrdiff_t = decltype((int*)0 - (int*)0);
	using nullptr_t = decltype(nullptr);

	return 0;
}