#include <iostream>

class MyClass {
    static int nobjs;

    MyClass() {
        nobjs++;
    }

    ~MyClass() {
        nobjs--;
    }

    public: static int nobjs() {
        return nobjs;
    }
};

int MyClass::nobjs = 0;

main() {
    MyClass a, b, c;
    cout 
        << "Number of objects: "
        << MyClass::nobjs()
}
