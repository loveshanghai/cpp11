#include <iostream>
using namespace std;

class A
{
public:
	A() { //throw 0; 
	}
	~A() noexcept(true) { throw 1; }
};

class C
{
public:
	void FunA() {
		try
		{
			A a;
		}
		catch (int e)
		{
			cout << "Catch exception:" << e << endl;
		}
		catch (...)
		{
			cout << "Catch exception..." << endl;
		}
	}
};

int no_except()
{
	//
	cout << __cplusplus << endl;
	C c;
	c.FunA();
	return 0;
}