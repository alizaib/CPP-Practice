#include "../Headers/HandlingArrays.h"
#include <iostream>

using namespace std;

void HandlingArraysEntryPoint() {
	//CharArray();
	//MultiDimentionalArray();
}

void CharArray() {
	const char* myNames[3] = { "Ali", "Amir", "Jehangir" };
	cout << *(myNames + 1) << endl;
}

void MultiDimentionalArray() {
	int arr[5][10];
	FillArray(arr, 5);
	DisplayArray(arr, 5);

	cout << arr << endl;
	cout << *arr << endl;


	cout << **arr << endl; // item at 0,0

	cout << *(arr + 3) << endl; // arr+3 -> 3rd row, *3rd row (address of 3rd row)

	cout << *(*(arr + 3)) << endl; // arr+3 -> 3rd row, *3rd row (address of 3rd row), *(address of third row)=content of first item in 3rd row
	cout << *(*(arr + 3) + 1) << endl; // arr+3 -> 3rd row, *3rd row (address of 3rd row), *(address of third row)=content of first item in 3rd row

}

void FillArray(int arr[][10], int size) {
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