#include <iostream>
#include <vector>
#include <string>

using namespace std;

int& fnRetByVal(int& x) { 
    cout<<"x = "<< x <<" &x= "<< &x <<endl;
    return x;
}

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};    
    cout << endl;
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    int a = 10;
    cout<<"a = "<< a <<" &a= "<< &a <<endl;

    const int& b = fnRetByVal(a);
    cout<<"b = "<< b <<" &b= "<< &b <<endl;   
}
