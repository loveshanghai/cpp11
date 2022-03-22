#include <iostream>
#include <atomic>
#include <thread>

using namespace std;
atomic_llong total{ 0 };// atomic data type
std::atomic_flag lock = ATOMIC_FLAG_INIT;
void f(int n) {
	while (lock.test_and_set(std::memory_order_acquire))
	{
		cout << "Waiting from thread " << n << endl;
	}
	cout << "Thread " << n << " starts working" << endl;
}
void g(int n) {
	cout << "Thread " << n << " is going to start." << endl;
	lock.clear();
	cout << "Thread " << n << " starts working" << endl;
}
void func(int) 
{
	for (long long i = 0; i < 100000000LL; ++i) 
	{
		total += i;
	}
}

int atomic_op()
{
	thread t1(func, 0);
	thread t2(func, 0);
	t1.join();
	t2.join();
	cout << total << endl;

	//
	lock.test_and_set();
	thread t3(f, 1);
	thread t4(g, 2);
	t3.join();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	t4.join();

	return 0;
}
