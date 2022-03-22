#include <iostream>
using namespace std;

int unicode_example()
{
	char utf8[] = u8"\u4F60\u597D\u554A";
	char16_t utf16[] = u"hello";
	char32_t utf32[] = U"hello equals \u4F60\u597D\u554A";
	cout << utf8 << endl;
	cout << utf16 << endl;
	cout << utf32 << endl;
	//char32_t u2[] = u"hello";
	//char u3[] = U"hello";
	//char16_t u4 = u8"hello";
	return 0;
}