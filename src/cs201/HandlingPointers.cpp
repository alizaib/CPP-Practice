#include "HandlingPointers.h"
#include <iostream>
#include <vector>

using namespace std;

void HandlingPointersEntryPoint() {
	//ConstantPointers();
	//PointersWithStrings();
	//SubtractPointers();
	//functionPointers();
}

void ConstantPointers() {
	const int a = 9;
	int b = 2;
	//clockwise spiral rule -> read from left to right
	//int* ptr; // ptr is a pointer to int
	//const int* const ptr = &a; //ptr is const pointer to int const (const int)
	//const int* ptr; //ptr is a pointer to int const
	//int const* ptr; //ptr is a pointer to const int
	//int* const ptr = &b; //ptr is a const pointer to an int

	//https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const
}

void SubtractPointers() {
	int y[10], * y1, * y2;
	y1 = &y[0];
	y2 = &y[3];

	cout << y2 - y1;
}

void PointersWithStrings() {
	char name[20];
	name[0] = 'A';
	name[1] = 'l';
	name[2] = 'i';
	name[3] = '\0';

	cout << name;
}

void HelloWorld() {
	cout << "HelloWorld" << endl;
}

void PrintMessage(const char* mesg) {
	cout << mesg << endl;
}

void HelloWithTypeDef(const char* mesg) {
	cout << mesg << endl;
}

void PrintValue(int value) {
	cout << "Value is: " << value << endl;
}

void ForEach(vector<int> values, void(*f)(int)) {
	for (int value : values)
		f(value);
}

void functionPointers() {

	// can use 
	// auto f = HelloWorld;
	void(*f)() = HelloWorld;

	f();
	f();

	void(*printMessage)(const char*) = PrintMessage;

	printMessage("Message is Hello Again");

	typedef void(*HelloWorldFunction)(const char*);

	HelloWorldFunction f2 = HelloWithTypeDef;

	f2("Hello with typedef now");

	vector<int> values = { 1, 3, 5, 7, 9 };
	ForEach(values, PrintValue);
	ForEach(values, [](int v) { cout << "In Lambda Value is :" << v << endl; });
}