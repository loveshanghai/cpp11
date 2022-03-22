#include <iostream>
#include <atomic>
#include <thread>
#include <cassert>

using namespace std;

atomic<int> a{ 0 };
atomic<int> b{ 0 };

atomic<string*> ptr;
atomic<int> data0;

void Producer()
{
	string* p = new string("Hello");
	data0.store(42, memory_order_relaxed);
	ptr.store(p, memory_order_release);
}

void Consumer()
{
	string* p2;
	while (!(p2 = ptr.load(memory_order_consume)));
	assert(*p2 == "Hello");
	assert(data0.load(memory_order_relaxed) == 42);
}

void ValueSet(int) 
{
	int t = 1;
	//a = t;
	//b = 2;
	a.store(t, memory_order_relaxed);
	//b.store(2, memory_order_relaxed);
	b.store(2, memory_order_release);//本原子操作前所有的写操作必须完成
}

void Observer(int) 
{
	//cout << "(" << a << ", " << b << ")" << endl;//
	//while (b.load(memory_order_relaxed) != 2);//spin wait
	while (b.load(memory_order_acquire) != 2);//本原子操作必须完成才能执行之后所有的读原子操作
	cout << a.load(memory_order_relaxed) << endl;
}

int memory_model()
{
	thread t1(ValueSet, 0);
	thread t2(Observer, 0);
	t1.join();
	t2.join();
	cout << "Got (" << a << ", " << b << ")" <<endl;

	//
	thread t5(Producer);
	thread t6(Consumer);
	t5.join();
	t6.join();

	return 0;
}