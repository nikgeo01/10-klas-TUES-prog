#include <iostream>

using namespace std;

class Test {
    
public:
    Test() {
        
    }

    Test (int value) {
        this->value = value;
    }
    
    //copy constructor
    Test(const Test& test) {
        this->value = test.value;
    }

    Test& operator=(const Test& test) {
        this->value = test.value;
        return *this;
    }

};