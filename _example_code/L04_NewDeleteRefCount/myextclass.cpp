#include "myextclass.h"
#include <iostream> 


// Class with a constructor and destructor
MyExtClass::MyExtClass() { std::cout << "Constructor called!" << std::endl; }
MyExtClass::~MyExtClass() { std::cout << "Destructor called!" << std::endl; }
    
void MyExtClass::myFunction() { std::cout << "Function called!" << std::endl; } // Member function
