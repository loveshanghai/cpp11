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
	//ʹ��accumulate�㷨��Ҫ����ѭ��
	errors = accumulate(v.begin(), v.end(), 0);
	score = accumulate(v.begin(), v.end(), 100, minus<int>());
	print();
	errors = 0;
	score = 100;
	//ʹ��lambda��ֻ��Ҫһ��ѭ��
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
	//��ͳ��forѭ��
	for (auto itr = nums.begin(); itr != nums.end(); ++itr)
	{
		if (*itr >= ubound) largeNums.push_back(*itr);
	}
	//ʹ�ú���ָ��
	for_each(nums.begin(), nums.end(), LargeNumsFunc);
	//ʹ��lambda����
	for_each(nums.begin(), nums.end(), [=](int i) {
	if (i > ubound) largeNums.push_back(i);
	});
}
vector<int> arrays{ 1, 2, 2, 3 };
void erase_op()
{
	//�����vectorɾ�������ƺ������ַ�ʽ��̫����
	for_each(arrays.begin(), arrays.end(), [=](int i) {
		if (i == 2); //arrays.erase();
		});
}
//�º���
class _functor {
public:
	int operator()(int x, int y) { return x + y; }
};

//[tax_rate](float price)->float {return price * (1 - tax_rate / 100)};
//�º������Կ�����lambda��һ��ʵ�ַ�ʽ�����߿��Ա������
class AirportPrice {
public:
	AirportPrice(float rate) :_dutyfreerate(rate) {}
	float operator()(float price) const/*Note:��lambda�����Ե�������Ҫ*/
	{
		return price * (1 - _dutyfreerate / 100);
	}
private:
	float _dutyfreerate;
};
int lambda_expr()
{
	[] {};//��򵥵�lambda����
	int a = 3;
	int b = 4;
	[=] {return a + b; };//ʡ���˲����б��뷵�����ͣ����������ɱ������ƶ�Ϊint
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
	p = totalChild;//lambda����ת���ɺ���ָ��
	oneChild q;
	//q = totalChild;//compile fail
	decltype(totalChild) allPeople = totalChild;
	//decltype(totalChild) totalPeople = p;//compile fail���Ǻ���ָ�벻��ת����lambda
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
	//auto const_val_lambda = [=]() { val = 3; };//����ʧ����const��lambda���޸ĳ���
	auto mutable_val_lambda = [=]() mutable { val = 3; };//��const��lambda�����޸ĳ�������
	auto const_ref_lambda = [&] { val = 3; };//��Ȼ��const��lambda����û�иĶ����ñ���
	auto const_param_lambda = [&](int v) { v = 3; };//��Ȼ��const��lambdaͨ����������val
	const_param_lambda(val);

	Above();
	stat_between();
	return 0;
}