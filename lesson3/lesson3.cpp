#include<iostream>
using namespace std;

class Bachelor {
    int roses;
    bool bald;
    bool rich;

public:

    Bachelor() {
        cout<<"In default constructor..."<<endl;
    }

    Bachelor(int roses, bool bald, bool rich) {
        this->roses = roses;
        this->bald = bald;
        this->rich = rich;
    }

    //operator=

    Bachelor& operator=(const Bachelor& bachelor) {
        if (this == &bachelor) {
            return *this;
        }

        this->roses = bachelor.roses;
        this->bald = bachelor.bald;
        this->rich = bachelor.rich;
        return *this;
    }

    int getRoses() {
        return this->roses;
    }

    void setRoses(int roses) {
        this->roses = roses;
    }

    bool isBald() {
        return this->bald;
    }

    void setBald(bool bald) {
        this->bald = bald;
    }

    bool isRich() {
        return this->rich;
    }

    void setRich(bool rich) {
        this->rich = rich;
    }

    ~Bachelor() {
        cout<<"In destructor..."<<endl;
    }

};

int main() {
    Bachelor b;
    Bachelor *b1 = new Bachelor(26, 1, 0);
    Bachelor *b2 = new Bachelor(1, 0, 1);

    //shallow copy
    //b2 = b1;

    //deep copy
    *b2 = *b1;

    cout<<b2->isBald()<<endl;
    cout<<b1->isBald()<<endl;

    cout << b2 << endl;
    cout << b1 << endl;
}