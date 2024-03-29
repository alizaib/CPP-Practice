#include <iostream>
#include "Distance.h"
#include "Date.h"
#include "Fraction.h"
#include "String.h"
#include "Matrix.h"
#include "Person.h"
#include "Test.h"
#include <iomanip>
#include "Inheritence.cpp"
#include "Polymorphism.h"

using namespace std;

void DistanceDemo();
void DateDemo();
void FractionDemo();
void StringDemo();
void FractionDemoConversionByConstructor();
void DemoNewDeleteOperator();
void IOManipDemo();
void StaticDemo();
void CopyConstructorsDemo();
void PersonDemo();
void MatrixDemo();
void TestDemo();
void InheritenceDemo();
void PolymorphismDemo();
void FunctionTemplateDemo();

// Global overload of new and Delete operator
//void* operator new (size_t size) { return calloc(1, size); }
//void operator delete(void* ptr) { free(ptr); }

template<class T>
T sqaure(T x) {
	return x*x;
}

void main()
{
	//DistanceDemo();
	//DateDemo();
	//FractionDemo();
	StringDemo();
	//FractionDemoConversionByConstructor();
	//DemoNewDeleteOperator();
	//IOManipDemo();
	//StaticDemo();
	//CopyConstructorsDemo();
	//PersonDemo();

	//float a = 10.9;
	//cout <<sqaure<int>(a);
	//MatrixDemo();

	//TestDemo();
	//InheritenceDemo();	
	//PolymorphismDemo();
	//FunctionTemplateDemo();

	system("pause");
}



void DistanceDemo() {
	//	Distance d1; // Constructor with Two parameters and then Default Constructor with Zero parameter
	//	Distance d1(5); // Constructor with Two parameters and then Default Constructor with One Parameters
	//	Distance d1(5.3, 2.0); //Only Constructor with two parameters

	Distance d1, d2, dSum, dDiff;
	cin >> d1;
	cin >> d2;
	
	dSum = d1 + d2;
	dDiff = d1 - d2;

	cout << "\nSum of the distances: ";
	//dSum.Display();
	cout << dSum;

	cout << "\nDifference of the distances: ";
	dDiff.Display();

	d1 += d2;
	cout << "\nadding second distance to first: ";
	d1.Display();

	d2 = d2 + 1;
	cout << "\nincreasing d2 by 1 (d2 + 1): ";
	d2.Display();

	d2 = 1 + d2;
	cout << "\nincreasing d2 by 1 (1 + d2): ";
	d2.Display();

	++d2;
	cout << "\nincrease d2 by ++d2";
	d2.Display();

	d2 = d2++;
	cout << "\nincrease d2 by d2++";
	d2.Display();

}

void DateDemo() {
	Date d1(26, 12, 2002), d2(28, 2, 2000), d3;
	cout << d1;
	++d1;
	cout << "\nAfter adding 1 day, the date is ";
	cout << d1;
	cout << endl;
	cout << d2;
	d2 = d2 + 5;
	cout << "\nAfter adding 5 days to the above date";
	cout << d2;
	d2 += 5;
	cout << "\nAfter adding 5 days to the above date using += operator";
	cout << d2;
	cout << "\nd1 > d2 : " << (d1 > d2);
	cout << "\nd1 < d2 : " << (d1 < d2);

}

void FractionDemo() {
	Fraction a, b(1, 4), c(1, 6); //b(23, 11), c(2, 3);

	cout << "\nb = "; b.Display();
	
	cout << "\nc = "; c.Display();

	//operator overloads
	a = b + c;
	cout <<"\nb + c = "; a.Display();

	a = b - c;
	cout <<"\nb - c = "; a.Display();

	a = b * c;
	cout <<"\nb * c = "; a.Display();

	a = b / c;
	cout << "\nb / c = "; a.Display();
}

void StringDemo()
{
	// stream operator overload
	/*String c1;
	cout << "Enter name: ";
	cin >> c1;
	cout << c1;
	cout << "\ncharacter at index 2 is: " << c1[2];*/

	//int operator overload
	/*int number;
	cout << "\nEnter a long number to store as string: "; cin >> number;
	String c2(number);	
	cout << c2;*/

	// if explicit keywork is not used the following line will call
	// String(int) constructor
	//String c3 = 'A';
	//cout << c3;

	// As the constructor String(int) is marked with explicit keyword
	// we have to explicitly convert int to string
	/*String c4 = (String)65; 
	cout << c4;*/

	// Type conversion operator
	/*String c4("520");
	int num = c4;
	cout << c4 << endl;

	String c5("Zaib");
	char* name = c5;
	cout << c5 << endl;*/

	//As this is definition and initalization on the same line, so it will call the constructor const char*
	//String c4 = "520";

	//The object is created and then operator = will be called
	/*String c4;
	c4 = "520";*/

}

void FractionDemoConversionByConstructor()
{
	Fraction f1 = 5, f2 = 3, result;
	result = f1 + f2;
	result.Display();
}

void DemoNewDeleteOperator()
{
	// Allocate a zero-filled array
	int *ip = new int[10];
	// Display the array
	for (int i = 0; i < 10; i++)
		cout << " " << ip[i];
	// Release the memory
	delete[] ip;
}

ostream& tab(ostream& os) {
	return os << '\t';
}

void IOManipDemo()
{
	int i = 10;
	cout << oct << i << endl; //setbase(8) can also be used
	cout << hex << i << endl; //setbase(16)
	cout << dec << setw(10) << setfill('*') << i << endl; //setbase(0) Zero means base 10
	cout.flush();

	//following is not working as expected.
	/*int j;
	cin.width(3);
	cin >> j;
	cout << j << endl;*/

	std::streamsize ss = cout.precision();	
	cout << setprecision(5) << 3.1415926 << endl;

	cout.setf(ios::showbase);
	cout.setf(ios::oct, ios::basefield);
	cout << i << endl;

	cout.setf(ios::hex, ios::basefield);
	cout << i << endl;

	float number = 100000;
	cout.precision(ss);
	cout.setf(ios::uppercase);
	cout.setf(ios::scientific, ios::floatfield);
	cout << number << endl;

	cout.setf(ios::fixed, ios::floatfield);
	cout << number << endl;

	
	cout << dec << i << tab << i << endl;
	cout << i << tab << i;
}

class Truck {
	int Wheels, Seats;
};

void Foo()
{
	static Truck t;
	static int i = 0;
	i++;
	cout << "Inside Foo: value of i = " << i << endl;
}

void StaticDemo()
{
	for (int i = 0; i < 10; i++)
		Foo();
}

void CopyConstructorsDemo()
{
	Matrix m1(2, 3);
	Matrix m2 = m1;
	
	cout << m1 << endl << m2;

	// Following two lines will call Assignment operator
	/*Matrix m3(3, 3);
	m3 = m2;*/
}

void PersonDemo() {
	Person p("Ali", 24, 3, 1984);
	cout << p << endl;

	cout << "Total count of person objects " << Person::count;
}

void MatrixDemo() {
	/*int rows, cols;
	cout << "Enter rows, cols separated by space: "; cin >> rows >> cols;
	Matrix m1(rows, cols);
	m1.input(cin);
	m1.output(cout);
	cout << "Ater transposing....";
	m1.Transpose();
	m1.output(cout);*/

	/*Matrix m1(2, 3), m2(3, 2);
	m1.input(cin);
	m2.input(cin);

	Matrix m3 = m1 * m2;
	cout << "\nMultiplying the above two matrices....";
	m3.output(cout);*/

	int rows, cols;
	cout << "Enter rows, cols separted by space: "; cin >> rows >> cols;
	Matrix m(rows, cols);
	cin >> m;

	double d;
	cout << "Enter value to multiply the above matrix with: "; cin >> d;
	//Matrix result = m *d; //using member operator
	Matrix result = d * m;  //using friend operator
	cout << result;
	//result.output(cout);
}

void TestDemo() {
	Test arr[2] = { Test(0), Test(1) };

	Test t(arr[0]);
}

void InheritenceDemo() {
	Child c;
}

// Don't treat Shape shapes[], polymorphically, will through error on the next iteration
// Do it like this 
/*
*  Shape shapes[]   //shapes is a pointer to object of type Shape, a constant poitner,
*  so get next value dereference it after adding i
*  *(shapes + i*sizeof(Shape)).Draw();
*  OR 
*  (shapes + i*sizeof(Shape))->Draw();
*/
void DrawShapes(Shape* shapes[], int size) {
	for (int i = 0; i < size; i++) {
		shapes[i] -> Draw();
	}
}

void PolymorphismDemo(){
	Shape* shapes[4]; //create 3 pointer of type shape

	shapes[0] = new Circle(); //new Shape() will now give error as Shape has a pure virtual method and hence is an abstract class
	shapes[1] = new Circle();
	shapes[2] = new Line();
	shapes[3] = new Rectangle();

	DrawShapes(shapes, 4);	
}

template<typename T>
bool IsEqual(T x, T y) {
	return x == y;
}

template<>
bool IsEqual<const char*>(const char* x, const char* y) {
	return (strcmp(x, y) == 0);
}

template<class T, class U>
T MyCast(U u) {
	return (T)u;
}

void FunctionTemplateDemo() {
	/*cout << IsEqual(4, 4) << endl;
	cout << IsEqual(5.0, 5.0) << endl;
	cout << IsEqual("Ali", "Ali") << endl;
	cout << IsEqual("Ali", "Zaib") << endl;*/

	double d = 24.356;
	int j = MyCast<int>(d);
	cout << j;

	// This will give compiler error as there is == overload for string
	// will resolve however if == operator is provided for String class
	/*String s1 = "abc", s2 = "xyz";
	cout << IsEqual(s1, s2);*/

}