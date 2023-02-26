#include <iostream>
#include "Misc.h"
#include "FileHandling.h"

using namespace std;

class Entity {
public:
	int X, Y;
	void Move() {
		X += 1;
		Y += 1;
	}
};

class Player : public Entity {
public:
	const char* Name;
	void PrintName() {
		cout << Name << endl;
	}
};

int main() {

	//FileHandlingEntryPoint();	
	//MiscEntryPoint();

	Player p;
	p.Move();
	p.X = 4;
	cout << p.X;

	system("pause");
}