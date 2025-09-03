#include <iostream>
#include "test.h"

int main()
{
    int n = 10;
    printf("Hello World!!");

    printf("\nvalue of n is %d", n);

    TestCall();
}

/*
    Remember gcc is c-compiler. To compile a c++ program, use g++
    
    1. To compile with gcc
    gcc -c helloworld.cpp    // will produce helloworld.o
    gcc helloworld.o -o helloworld // will produce the exe
    or if you wanna do it one step
    gcc helloworld.cpp -o helloworld //will produce the exe
    g++ -I headers/ helloworld.cpp  source/test.cpp  -o helloworld

    2. to run the exe type
    ./helloworld

    3. gcc -S helloworld.cpp   //with capital S will produce the assembly language version of your code

    4. gcc -E helloworld.cpp > helloworld_combined.c // will produce a combined C language program
*/
