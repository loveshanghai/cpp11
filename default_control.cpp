#include <type_traits>
#include <iostream>
using namespace std;

class TwoCstor {
public:
	//提供了带参数版本的构造函数，则必须提供不带
	//参数版本，且TwoCstor不再是POD类型
	//TwoCstor() {};
	//提供了带参数版本的构造函数,再指示编译器提供默认版本
	//则TwoCstor依然是POD类型
	TwoCstor() = default;
	TwoCstor(int i) : data(i) {}
private:
	int data;
};

class NoCopyCstor {
public:
	NoCopyCstor() = default;
private:
	//将拷贝构造函数声明为private成员并不
	//提供实现可以有效阻止用户错用拷贝构造函数
	NoCopyCstor(const NoCopyCstor&);
};

class NoCopyCstor2 {
public:
	NoCopyCstor2() = default;
	//使用"=delete"同样可以有效阻止用户错用拷贝构造函数
	NoCopyCstor2(const NoCopyCstor2&) = delete;
};
class ConvType
{
public:
	ConvType(int i) {};
	ConvType(char c) = delete;//删除char版本
	//explicit ConvType(char c) = delete;//删除char版本
};
void Func(ConvType ct) {}
void GFunc(int) {};
void GFunc(char) = delete;//显示删除char版本


int default_control()
{
	cout << is_pod<TwoCstor>::value << endl;

	NoCopyCstor a;
	//NoCopyCstor b(a);//编译无法通过

	Func(3);
	//Func('a');//无法编译,避免了一些隐式转换,如果删除的是explicit版本即可以通过
	ConvType ci(3);
	//ConvType cc('a');//无法编译

	GFunc(3);
	//GFunc('a');//无法通过编译
	return 0;
}