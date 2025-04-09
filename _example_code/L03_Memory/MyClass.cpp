#include "MyClass.h"
#include <iostream>

MyClass::MyClass(float f, int i, const std::string& s) 
    : myFloat(f), myInt(i), myString(s) {}

// Getters
float MyClass::getFloat() const {
    return myFloat;
}

int MyClass::getInt() const {
    return myInt;
}

std::string MyClass::getString() const {
    return myString;
}

// Setters
void MyClass::setFloat(float f) {
    myFloat = f;
}

void MyClass::setInt(int i) {
    myInt = i;
}

void MyClass::setString(const std::string& s) {
    myString = s;
}

