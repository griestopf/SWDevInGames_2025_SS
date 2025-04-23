#include <iostream>

#include "my_class.h"



#include <memory>

template <typename T>
class SmartPointer {
private:
    T* ptr;
    int* ref_count;

public:
    SmartPointer(T* p = nullptr) : ptr(p), ref_count(new int(1)) {}

    SmartPointer(const SmartPointer& other) : ptr(other.ptr), ref_count(other.ref_count) {
        (*ref_count)++;
    }

    SmartPointer& operator=(const SmartPointer& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            (*ref_count)++;
        }
        return *this;
    }

    ~SmartPointer() {
        release();
    }

    T* operator->() const {
        return ptr;
    }

    T& operator*() const {
        return *ptr;
    }

private:
    void release() {
        if (--(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }
};




int main() {

    /*
    {
        MyClass my_object(43);
        my_object.some_value = 42;
        my_object.some_method();
    } // Destructor will be called here


    MyClass *p_my_object = new MyClass(44);
    p_my_object->some_method();
    delete p_my_object; // Destructor will be called here
    */

    {
        MyClass *p_my_object = new MyClass(44);
        {
            MyClass *p_my_object2 = p_my_object;
            p_my_object2->some_value = 42;
            p_my_object->some_method();
        }
    }



    {
        SmartPointer<MyClass> sp_my_object(new MyClass(45));
        {
            SmartPointer<MyClass> sp_my_object2 = sp_my_object;
            sp_my_object2->some_value = 46;
            sp_my_object->some_method();
        }
        sp_my_object->some_value = 47;
        sp_my_object->some_method();
    }




    std::cout << "Hello, World!" << std::endl;
    return 0;
}
