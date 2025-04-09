#include <iostream>
#include <string>
#include "MyClass.h"

class A {
public:
    int n;
    int m;
    std::string str;
};

int main() {
    int a = 5;
    int b = 10;
    int* pA = &a;
    pA = &b;
    int& rA = a;
    rA = b;

    MyClass mc(3.14f, 42, "Hello World");
    MyClass *pMC = new MyClass(2.71f, 24, "Goodbye World");

    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;



    A objA;
    objA.n = 10;
    objA.m = 20;
    objA.str = "Hello";
    objA.str += " World";

    for (char c : objA.str) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    printf("eof\n");
    return 0;
}