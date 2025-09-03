#include <iostream>

using namespace std;

int init_m1(int m1) { cout << "init_m1 called with value: " << m1 << endl; return m1; }
int init_m2(int m2) { cout << "init_m2 called with value: "<< m2 << endl; return m2; }

class X {
    private:
        int _m1, _m2;
    public:
        X(int m1, int m2) : _m2(init_m2(m2)), _m1(init_m1(m1)) { cout << "X Constructor called" << endl; }
        ~X() { cout<< "X Destructor called"; }

};

int main() {
    X x(2,6);

    return 0;
}