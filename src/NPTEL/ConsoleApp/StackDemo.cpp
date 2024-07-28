#include "StackDemo.h"
using namespace std;


void StackDemo() {
	char str[10] = "ABCD";
	stack<char> s;

	for (int i = 0; i < strlen(str); i++)
		s.push(str[i]);

	cout << "Reversed string!" << endl;

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}