#include <memory>
#include <iostream>

using namespace std;

void Check(weak_ptr<int>& wp)
{
	shared_ptr<int> sp = wp.lock();
	if (sp != nullptr)
	{
		cout << "still " << *sp << endl;
	}
	else
	{
		cout << "Pointer is invalid." << endl;
	}
}


int smart_pointer()
{
	unique_ptr<int> up1(new int(11));
	//unique_ptr<int> up2 = up1;
	cout << *up1 << endl;
	unique_ptr<int> up3 = move(up1);
	cout << *up3 << endl;
	//cout << *up1 << endl;
	up3.reset();
	up1.reset();
	//cout << *up3 << endl;

	shared_ptr<int> sp1(new int(22));
	shared_ptr<int> sp2 = sp1;
	weak_ptr<int> wp = sp1;
	cout << *sp1 << endl;
	cout << *sp2 << endl;
	Check(wp);
	sp1.reset();
	cout << *sp2 << endl;
	Check(wp);
	sp2.reset();
	Check(wp);
	return 0;
}