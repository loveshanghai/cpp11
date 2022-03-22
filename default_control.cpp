#include <type_traits>
#include <iostream>
using namespace std;

class TwoCstor {
public:
	//�ṩ�˴������汾�Ĺ��캯����������ṩ����
	//�����汾����TwoCstor������POD����
	//TwoCstor() {};
	//�ṩ�˴������汾�Ĺ��캯��,��ָʾ�������ṩĬ�ϰ汾
	//��TwoCstor��Ȼ��POD����
	TwoCstor() = default;
	TwoCstor(int i) : data(i) {}
private:
	int data;
};

class NoCopyCstor {
public:
	NoCopyCstor() = default;
private:
	//���������캯������Ϊprivate��Ա����
	//�ṩʵ�ֿ�����Ч��ֹ�û����ÿ������캯��
	NoCopyCstor(const NoCopyCstor&);
};

class NoCopyCstor2 {
public:
	NoCopyCstor2() = default;
	//ʹ��"=delete"ͬ��������Ч��ֹ�û����ÿ������캯��
	NoCopyCstor2(const NoCopyCstor2&) = delete;
};
class ConvType
{
public:
	ConvType(int i) {};
	ConvType(char c) = delete;//ɾ��char�汾
	//explicit ConvType(char c) = delete;//ɾ��char�汾
};
void Func(ConvType ct) {}
void GFunc(int) {};
void GFunc(char) = delete;//��ʾɾ��char�汾


int default_control()
{
	cout << is_pod<TwoCstor>::value << endl;

	NoCopyCstor a;
	//NoCopyCstor b(a);//�����޷�ͨ��

	Func(3);
	//Func('a');//�޷�����,������һЩ��ʽת��,���ɾ������explicit�汾������ͨ��
	ConvType ci(3);
	//ConvType cc('a');//�޷�����

	GFunc(3);
	//GFunc('a');//�޷�ͨ������
	return 0;
}