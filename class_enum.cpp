#include <iostream>

using namespace std;

enum class Type { General, Light, Medium, Heavy };
enum class Category { General = 1, Pistol, MachineGun, Cannon };
enum class C :char { C1 = 1, C2 = 2 };
enum class D :unsigned int { D1 = 1, D2 = 2, Dbig = 0xfffffff0U };

int class_enum()
{
	Type t = Type::Light;
	//t = General;

	//if (t == Category::General)
	//{
	//	cout << "Genral Weapon" << endl;
	//}
	if (t > Type::General)
	{
		cout << "Not General Weapon" << endl;
	}
	//if (t > 0)
	//{
	//	cout << "Not General Weapon" << endl;
	//}
	if ((int)t > 0)
	{
		cout << "Not General Weapon" << endl;
	}
	cout << is_pod<Type>::value << endl;
	cout << is_pod<Category>::value << endl;
	cout << is_pod<C>::value << endl;
	cout << is_pod<D>::value << endl;
	cout << sizeof(C::C1) << endl;
	cout << (unsigned int)D::Dbig << endl;
	cout << sizeof(D::D1) << endl;
	cout << sizeof(D::Dbig) << endl;
	return 0;
}