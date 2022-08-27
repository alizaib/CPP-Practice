#include "../Headers/Misc.h"
#include <corecrt_memory.h>
#include <iostream>
#include <typeinfo>

using namespace std;

void PlayWithPointers() {
	CharArray();
	//MultiDimentionalArray();
	//ConstantPointers();
	//PointersWithStrings();
	//SubtractPointers();
	
}
void CharArray() {
	const char* myNames[3] = { "Ali", "Amir", "Jehangir"};
	cout << *(myNames+1) << endl;
}

void MultiDimentionalArray() {
	int arr[5][10];
	FillArray(arr, 5);
	DisplayArray(arr, 5);

	cout << arr << endl;
	cout << *arr << endl;


	cout << **arr << endl; // item at 0,0

	cout << *(arr + 3) << endl; // arr+3 -> 3rd row, *3rd row (address of 3rd row)

	cout <<  *(*(arr + 3)) << endl; // arr+3 -> 3rd row, *3rd row (address of 3rd row), *(address of third row)=content of first item in 3rd row
	cout << *(*(arr + 3)+1) << endl; // arr+3 -> 3rd row, *3rd row (address of 3rd row), *(address of third row)=content of first item in 3rd row
	
}

void FillArray(int arr[][10] , int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = (j + 1) + i * size;
		}
	}
}

void DisplayArray(int arr[][10], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 10; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void ConstantPointers() {
	const char a = 'A';
	const char b = 'B';
	char c = 'C';
	char d = 'D';
	
	char const *cPtr1; //cPtr1 is a pointer to a charter constant, so it can be assigned address of only a const char
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