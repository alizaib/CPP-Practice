#include "OperatorsOverload.h"
using namespace std;

void* operator new(size_t n) {	

	cout << "Overloaded new " << endl;
	void* ptr = malloc(n);
	return ptr;
}

void operator delete(void* p) {
	cout << "Overloaded delete " << endl;
	free(p);
}

void OperatorOverloadsDemo() {
	int* p = new int;
	*p = 33;
	cout << "The value is: " << *p << endl;
	delete p;
}