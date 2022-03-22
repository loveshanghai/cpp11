#include <type_traits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> nums;
vector<int> largeNums;
const int ubound = 10;

void Stat(vector<int>& v)
{
	int errors;
	int score;
	auto print = [&] {
		cout << "Errors: " << errors << endl << "Score: " << score << endl;
	};
	//使用accumulate算法需要两次循环
	errors = accumulate(v.begin(), v.end(), 0);
	score = accumulate(v.begin(), v.end(), 100, minus<int>());
	print();
	errors = 0;
	score = 100;
	//使用lambda则只需要一次循环
	for_each(v.begin(), v.end(), [&](int i) {
		errors += i;
		score -= i;
		});
	print();
}

void stat_between()
{
	vector<int> v(10);
	generate(v.begin(), v.end(), [] {
		return rand() % 10;
		});
	Stat(v);
}

inline void LargeNumsFunc(int i)
{
	if (i > ubound) largeNums.push_back(i);
}

void Above()
{
	//传统的for循环
	for (auto itr = nums.begin(); itr != nums.end(); ++itr)
	{
		if (*itr >= ubound) largeNums.push_back(*itr);
	}
	//使用函数指针
	for_each(nums.begin(), nums.end(), LargeNumsFunc);
	//使用lambda函数
	for_each(nums.begin(), nums.end(), [=](int i) {
	if (i > ubound) largeNums.push_back(i);
	});
}
vector<int> arrays{ 1, 2, 2, 3 };
void erase_op()
{
	//如果对vector删除操作似乎用这种方式不太合适
	for_each(arrays.begin(), arrays.end(), [=](int i) {
		if (i == 2); //arrays.erase();
		});
}
//仿函数
class _functor {
public:
	int operator()(int x, int y) { return x + y; }
};

//[tax_rate](float price)->float {return price * (1 - tax_rate / 100)};
//仿函数可以看作是lambda的一种实现方式，二者可以比照理解
class AirportPrice {
public:
	AirportPrice(float rate) :_dutyfreerate(rate) {}
	float operator()(float price) const/*Note:对lambda常量性的理解很重要*/
	{
		return price * (1 - _dutyfreerate / 100);
	}
private:
	float _dutyfreerate;
};
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
	_functor ftor;
	auto totalChild0 = ftor(girls, boys);
	auto totalChild = [](int x, int y) {return x + y; };
	auto totalChild2 = [girls, &boys] {return girls + boys; };
	auto totalChild3 = [=]() { return girls + boys; };
	auto totalChild4 = [=] { return girls + boys; };
	auto totalChild6 = [=] { return girls + boys; }();
	//
	typedef int(*allChild)(int x, int y);
	typedef int(*oneChild)(int x);
	allChild p;
	p = totalChild;//lambda可以转换成函数指针
	oneChild q;
	//q = totalChild;//compile fail
	decltype(totalChild) allPeople = totalChild;
	//decltype(totalChild) totalPeople = p;//compile fail但是函数指针不能转换成lambda
	//
	int j = 12;
	auto by_val_lambda = [=] {return j + 1; };
	auto by_ref_lambda = [&] {return j + 1; };
	cout << "by_val_lambda: " << by_val_lambda() << endl;//13
	cout << "by_ref_lambda: " << by_ref_lambda() << endl;//13
	j++;
	cout << "by_val_lambda: " << by_val_lambda() << endl;//13
	cout << "by_ref_lambda: " << by_ref_lambda() << endl;//14

	//
	int val;
	//auto const_val_lambda = [=]() { val = 3; };//编译失败在const的lambda中修改常量
	auto mutable_val_lambda = [=]() mutable { val = 3; };//非const的lambda可以修改常量数据
	auto const_ref_lambda = [&] { val = 3; };//依然是const的lambda不过没有改动引用本身
	auto const_param_lambda = [&](int v) { v = 3; };//依然是const的lambda通过参数传递val
	const_param_lambda(val);

	Above();
	stat_between();
	return 0;
}