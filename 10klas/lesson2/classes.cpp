#include <iostream>
using namespace std;

class Car {
// access modifier
private:
    string model;
    string make;
    double topSpeed;

public:
    string getModel() {
        return this->model;
    }

    void setModel(string model) {
        this->model = model;
    }
};

int main() {
    Car c1; //cin >> c1.model;
    Car* c = new Car();

    cin >> c->model;
    cin >> c->make;
    cin >> c->topSpeed;

    return 0;
}