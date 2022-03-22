#include <iostream>

using namespace std;
struct HowManyBytes {
	char a;
	int b;
};

struct ColorVector {
	double r;
	double g;
	double b;
	double a;
};

//struct alignas(32) ColorVector2 {
struct alignas(alignof(double)*4) ColorVector2 {
	double r;
	double g;
	double b;
	double a;
};

class InComplete;
struct Completed {};

int align_support()
{
	cout << "sizeof(char): " << sizeof(char) << endl;
	cout << "sizeof(int): " << sizeof(int) << endl;
	cout << "sizeof(HowManyBytes): " << sizeof(HowManyBytes) << endl;
	cout << "offset of char a: " << offsetof(HowManyBytes, a) << endl;
	cout << "offset of char b: " << offsetof(HowManyBytes, b) << endl;

	cout << "alignof(ColorVector): " << alignof(ColorVector) << endl;
	cout << "alignof(ColorVector2): " << alignof(ColorVector2) << endl;

	//
	int a;
	alignas(alignof(long long)) long long b;
	auto& c = b;
	alignas(double) unsigned char d[sizeof(double)];
	cout << "alignof(int): " << alignof(int) << endl;
	cout << "alignof(Completed): " << alignof(Completed) << endl;
	//cout << "alignof(InComplete): " << alignof(InComplete) << endl;
	//cout << "alignof(a): " << alignof(a) << endl;
	//cout << "alignof(b): " << alignof(b) << endl;
	//cout << "alignof(c): " << alignof(c) << endl;
	//cout << "alignof(d): " << alignof(d) << endl;

	return 0;
}