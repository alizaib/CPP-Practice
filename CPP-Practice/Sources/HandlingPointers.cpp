#include "../Headers/HandlingPointers.h"
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
	const char a = 'A';
	const char b = 'B';
	char c = 'C';
	char d = 'D';

	char const* cPtr1; //cPtr1 is a pointer to a charter constant, so it can be assigned address of only a const char
	cPtr1 = &a;
	//*cPtr1 = 'z'; //is not allowed because cPtr1 is a pointer to a constant char and const char cannot be changed.

	char* const cPtr2 = &c; // cPtr2 is a constant pointer, so it will need an address to point to at declaration and the address it is pointing to 
	// cannot be changed, the contents however can be changed
	*cPtr2 = 'z';
	// cPtr2 = &d;  // Not allowed

	const char* const cPtr3 = &d; // cPtr3 is a const pointer to a const char, although initially is assigned address of non-const char
	// but it will treat it as const and will not allow to change the contants or the address that it is pointing to
// so following both lines are not allowed
//*cPtr3 = 'z';
//cPtr3 = &a;

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