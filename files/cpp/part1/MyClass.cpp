#include <iostream>

/// @brief Class to demonstrate tracking number of object instances
/// Assumes that ...
/* 
to be honest, I don't know what assumptions are made, possibly...
    - that all instances are created using MyClass()
    - that all instances are owned by this program/thread
    - that all instances are successfully deconstructed
*/
class MyClass {
    static int numobjs;

    public: MyClass() {
        numobjs++;
    }

    public: ~MyClass() {
        numobjs--;
    }

    /// @return number of MyClass objects currently in existance
    public: static int nobjs() {
        return numobjs;
    }
};
int MyClass::numobjs = 0;



/* The following is a test of the MyClass functionality */

void printn() {
    std::cout 
        << "\nNumber of objects: " << MyClass::nobjs();
}

main() {
    printn(); // expect 0
    {
        MyClass a, b, c;
        printn(); // expect 3
        {
            MyClass d, e, f;
            printn(); // expect 6
        }
        printn(); // expect 3
    }
    printn(); // expect 0
};

/* End of test */
