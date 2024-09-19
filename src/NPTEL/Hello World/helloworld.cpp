#include <iostream>

int main()
{
    printf("Hello World!!");
}

/*
    To compile with gcc
    gcc -c helloworld.cpp    // will produce helloworld.o
    gcc helloworld.o -o helloworld // will produce the exe
    or if you wanna do it one step
    gcc helloworld.cpp -o helloworld //will produce the exe

    to run the exe type
    ./helloworld

    gcc -S helloworld.cpp   //with capital S will produce the assembly language version of your code
*/
