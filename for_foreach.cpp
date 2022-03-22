#include <iostream>
#include <algorithm>
using namespace std;

void action1(int& e) { e *= 2; }
void action2(int& e) { cout << e << '\t'; }
int for_foreach()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p;
	for (p = arr; p < arr + sizeof(arr) / sizeof(arr[0]); ++p)
	{
		*p *= 2;
	}
	for_each(arr, arr + sizeof(arr) / sizeof(arr[0]), action1);
	for (p = arr; p < arr + sizeof(arr) / sizeof(arr[0]); ++p)
	{
		cout << *p << '\t';
	}
	for_each(arr, arr + sizeof(arr) / sizeof(arr[0]), action2);
	for (int& e : arr)
	{
		e *= 2;
	}

	for (int& e : arr)
	{
		cout << e << '\t';
	}

	for (auto e : arr)
	{
		e *= 2;
	}

	for (auto e : arr)
	{
		cout << e << '\t';
	}
	return 0;
}