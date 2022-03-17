#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <string>
//#include <initializer_list>

using namespace std;

enum Gender{ boy, girl };
class People 
{
public:
	People(std::initializer_list<pair<string, Gender>> l)
	{
		for (auto i = l.begin(); i != l.end(); ++i)
		{
			data.push_back(*i);
		}
	}
private:
	vector<pair<string, Gender>> data;	
};

void Func(std::initializer_list<int> iv){}
vector<int> FuncV() { return { 1,3 }; }
deque<int> FuncQ() { return { 2,4 }; }
const vector<int>& FuncVRef() { return { 5,6 }; }

class MyData
{
public:
	MyData& operator [](std::initializer_list<int> l)
	{
		for (auto i = l.begin(); i != l.end(); ++i)
		{
			idx.push_back(*i);
		}
		return *this;
	}

	MyData& operator = (int v)
	{
		if (idx.empty() != true)
		{
			for (auto i = idx.begin(); i != idx.end(); ++i)
			{
				d.resize((*i > d.size()) ? *i : d.size());
				d[*i - 1] = v;
			}
			idx.clear();
		}
		return *this;
	}

	void Print()
	{
		for (auto i = d.begin(); i != d.end(); ++i)
		{
			cout << *i << "";
		}
		cout << endl;
	}
private:
	vector<int> idx;
	vector<int> d;
};
int initializer_list()
{
	//
	const int n1 = 1024;
	const int n2 = 10;
	char n3 = n1;
	char* n4 = new char(1024);
	//char n5 = { n1 };
	char n6 = { n2 };
	//unsigned char n7{ -1 };
	float n8{ 7 };
	//int n9{ 2.0f };
	//float* n10 = new float{ 1e48 };
	float n11 = 1.2l;

	//
	MyData data;
	data[{2, 3, 5}] = 7;
	data[{1, 4, 5, 8}] = 4;
	data.Print();

	//
	Func({ 1, 2 });
	Func({});
	People ship2012 = {{"Garfoed", boy}, {"HelloKitty", girl}};

	//
	int a[] = { 1, 3, 5 };
	int b[]{ 2, 4, 6 };
	vector<int> c{ 1, 3, 5 };
	map<int, float> d = { {1, 1.0f}, {2,2.0f},{5,3.2f} };

	//
	int a1 = 3 + 4;
	int a2 = { 3 + 4 };
	int a3(3 + 4);
	int a4{ 3 + 4 };

	int* i = new int(1);
	double* d0 = new double{ 1.2f };

	return 0;
}