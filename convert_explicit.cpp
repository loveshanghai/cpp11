#include <iostream>

class ConvertTo {};
class Convertable {
public:
	explicit operator ConvertTo() const { return ConvertTo(); }
};

void Func(ConvertTo ct){}
int convert_explicit()
{
	Convertable c;
	ConvertTo ct(c);
	//ConvertTo ct2 = c;
	ConvertTo ct3 = static_cast<ConvertTo>(c);
	//Func(c);
	return 0;
}