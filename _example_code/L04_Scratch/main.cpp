#include <iostream>

#include "my_class.h"


int main() {

    MyClass my_object(43);
    my_object.some_value = 42;
    my_object.some_method();

    MyClass *p_my_object = new MyClass(44);
    p_my_object->some_method();
    delete p_my_object; // Destructor will be called here


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
