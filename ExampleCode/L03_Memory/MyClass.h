#ifndef MYCLASS_H
#define MYCLASS_H

#include <string>

class MyClass {
private:
    float myFloat;
    int myInt;
    std::string myString;

public:
    // Constructor
    MyClass(float f, int i, const std::string& s);

    // Getters
    float getFloat() const;
    int getInt() const;
    std::string getString() const;

    // Setters
    void setFloat(float f);
    void setInt(int i);
    void setString(const std::string& s);
};

#endif // MYCLASS_H