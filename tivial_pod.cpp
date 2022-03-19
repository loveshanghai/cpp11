#include <iostream>
#include <type_traits>

using namespace std;

struct Trivial1 {};
struct Trivial2 {
public:
	int a;
private:
	int b;
};
struct Trivial3 {
	Trivial1 a;
};
struct Trivial4 {
	Trivial2 a[23];
};
struct Trivial5 {
	int x;
	static int y;
};
struct NonTrivial1 {
	NonTrivial1():z(42) {}
	int z;
};
struct NonTrivial2 {
	NonTrivial2();
	int w;
};
NonTrivial2::NonTrivial2() = default;
struct NonTrivial3 {
	Trivial5 c;
	virtual void f();
};

int trivial_pod()
{
	cout << is_trivial<Trivial1>::value << endl;
	cout << is_trivial<Trivial2>::value << endl;
	cout << is_trivial<Trivial3>::value << endl;
	cout << is_trivial<Trivial4>::value << endl;
	cout << is_trivial<Trivial5>::value << endl;

	cout << is_trivial<NonTrivial1>::value << endl;
	cout << is_trivial<NonTrivial2>::value << endl;
	cout << is_trivial<NonTrivial3>::value << endl;
	return 0;
}
