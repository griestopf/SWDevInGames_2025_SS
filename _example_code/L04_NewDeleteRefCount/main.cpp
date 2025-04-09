#include <iostream>

#include "myextclass.h"


// Implementation of a reference counting smart pointer
template <typename T>
class SmartPointer {
private:
    T* ptr; // Raw pointer
    int* refCount; // Reference count
public:
    SmartPointer(T* p = nullptr) : ptr(p), refCount(new int(1)) { } // Constructor
    SmartPointer(const SmartPointer& sp) : ptr(sp.ptr), refCount(sp.refCount) { (*refCount)++; } // Copy constructor
    ~SmartPointer() { // Destructor
        if (--(*refCount) == 0) {
            delete ptr; // Delete the object if no references left
            delete refCount; // Delete the reference count
        }
    }
    T& operator*() { return *ptr; } // Dereference operator
    T* operator->() { return ptr; } // Member access operator

    SmartPointer& operator=(const SmartPointer& sp) { // Assignment operator
        if (this != &sp) {
            if (+--(*refCount) == 0) {
                delete ptr; // Delete the object if no references left
                delete refCount; // Delete the reference count
            }
            ptr = sp.ptr; // Copy the pointer
            refCount = sp.refCount; // Copy the reference count
            (*refCount)++; // Increment the reference count
        }
        return *this;
    }

    SmartPointer& operator=(T* p = nullptr) { // Assignment operator
        if (ptr != p) {
            if (--(*refCount) == 0) {
                delete ptr; // Delete the object if no references left
                delete refCount; // Delete the reference count
            }
            ptr = p; // Copy the pointer
            refCount = new int(1); // Create a new reference count
        }
        return *this;
    }
    

};



class MyClass { 
    public:
        MyClass() { std::cout << "Constructor called!" << std::endl; }
        ~MyClass() { std::cout << "Destructor called!" << std::endl; }
    
        int myData; // Member variable
        void myFunction() { std::cout << "Function called!" << std::endl; } // Member function
    
};
    
    


int main() {

    if (true) {
        MyClass obj; // Object created, constructor called
        obj.myData = 10; // Accessing member variable
    } // Object goes out of scope, destructor called


    MyClass* objPtr = new MyClass(); // Object created, constructor called
    objPtr->myData = 20; // Accessing member variable
    objPtr->myFunction(); // Calling member function    
    delete objPtr; // Object deleted, destructor called


    // Using a smart pointer (unique_ptr) to manage the object
    std::unique_ptr<MyClass> smartPtr(new MyClass()); // Object created, constructor called
    // No need to delete, destructor called automatically when smartPtr goes out of scope

    std::shared_ptr<MyClass> sharedPtr(new MyClass()); // Object created, constructor called
    sharedPtr->myData = 30; // Accessing member variable
    std::shared_ptr<MyClass> anotherSharedPtr = sharedPtr; // Shared ownership
    anotherSharedPtr->myData = 40; // Accessing member variable through another shared pointer
    
    smartPtr->myData = 42; // Accessing member variable
    smartPtr->myFunction(); // Calling member function
    


    std::cout << "Hello, World!" << std::endl;
    return 0;
}