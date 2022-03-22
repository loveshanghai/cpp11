#include <cstdlib>
#include <iostream>

using namespace std;

struct A { ~A() { cout << "Destruct A. " << endl; } };
void quickCloseDevice() { cout << "Device is quickly closed." << endl; }

void openDevice() {
	cout << "device is opened." << endl;
}

void resetDeviceStat() {
	cout << "device stat is reset." << endl;
}

void closeDevice() {
	cout << "device is closed." << endl;
}

int exit_do()
{
	//atexit(closeDevice);
	//atexit(resetDeviceStat);
	//openDevice();
	//exit(0);

	A a;
	at_quick_exit(quickCloseDevice);
	quick_exit(0);
}
