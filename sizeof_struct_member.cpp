#include <iostream>

using namespace std;

struct pepole
{
	int hand;
	static pepole* all;
};

int size_struct_member()
{
	pepole p;

	cout << sizeof(p.hand) << endl;
	cout << sizeof(p.all) << endl;

	cout << sizeof(pepole::hand) << endl;
	cout << sizeof(pepole::all) << endl;

	cout << sizeof(((pepole*)0)->hand) << endl;
	cout << sizeof(((pepole*)0)->all) << endl;
	return 0;
}