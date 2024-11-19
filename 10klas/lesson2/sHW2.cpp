#include <iostream>
using namespace std;

class Vector {
    int capacity;
    int size;
    int* array;

public:

    Vector() {
        this->capacity = 0;
        this->size = 0;
        this->array = nullptr;
    }

    int getCapacity() {
        return this->capacity;
    }

    int getSize() {
        return this->size;
    }

    int* getArray() {
        return this->array;
    }

    void setCapacity(int capacity) {
        this->capacity = capacity;
    }

    void setSize(int size) {
        this->size = size;
    }

    void setArray(int* array) {
        this->array = array;
    }

    void createVector(int size) {
        this->size = size;
        if(this->capacity <= size) {
            this->resize(size * 2);
        }
        this->array = new int[capacity];

        for(int i = 0; i < this->size; i++) {
            this->array[i] = i * 5;
        }
    }

    void printVector() {
        for (int i = 0; i < this->size; i++) {
            cout << this->array[i] << " ";
        }
        cout << endl;
    }

    void add(int value) {
        if (this->size >= this->capacity) {
            this->resize(this->capacity * 2);
        }
        this->array[this->size] = value;
        this->size++;
    }

    void removeFirst() {
        for (int i = 0; i < this->size - 1; i++) {
            this->array[i] = this->array[i + 1];
        }
        this->size--;
        if (this->size < this->capacity / 2) {
            this->resize(this->capacity / 2);
        }
    }

    void removeLast() {
        this->size--;
        if (this->size < this->capacity / 2) {
            this->resize(this->capacity / 2);
        }
    }

    void removeElement(int index) {
        for (int i = index; i < this->size - 1; i++) {
            this->array[i] = this->array[i + 1];
        }
        this->size--;
        if (this->size < this->capacity / 2) {
            this->resize(this->capacity / 2);
        }
    }


private:

    void resize(int newCapacity) {
        int* newArray = new int[newCapacity];
        for (int i = 0; i < this->size; i++) {
            newArray[i] = this->array[i];
        }
        delete[] this->array;
        this->array = newArray;
        this->capacity = newCapacity;
    }

    void deleteVector() {
        delete[] this->array;
    }

    ~Vector() {
        deleteVector();
    }


};

int main () {

    int n = 10;

    Vector *v = new Vector();
    v->setCapacity(n);
    v->setSize(n);
    v->setArray(new int[n]);

    v->createVector(n);

    cout << "Capacity: " << v->getCapacity() << endl;
    cout << "Size: " << v->getSize() << endl;
    cout << "Array: " << v->getArray() << endl;

    v->printVector();

    v->add(100);
    v->printVector();

    v->removeFirst();
    v->printVector();

    v->removeLast();
    v->printVector();

    v->removeElement(3);
    v->printVector();

    return 0;
}