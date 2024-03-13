#include <iostream>
using namespace std;

struct vector_t {
    int capacity;
    int size;
    int* array;
};

typedef struct vector_t vector;

void initializeVector(vector* v) {
    for (int i = 0; i < v->size; i++) {
        v->array[i] = i * 5;
    }
}

void printVector(vector* v) {
    for (int i = 0; i < v->size; i++) {
        cout << v->array[i];
    }
    cout << endl;
}

void createVector(vector* v, int capacity, int size) {
    v->size = size;
    v->capacity = capacity;
    v->array = new int[capacity];
}

vector resize(vector* v, int newCapacity) {
    vector newVector;
    newVector.capacity = newCapacity;
    newVector.size = v->size;
    newVector.array = new int[newCapacity];
    
    for (int i = 0; i < v->size; i++) {
        newVector.array[i] = v->array[i];
    }

    delete[] v->array;
    
    return newVector;
}

void add(vector* v, int value) {
    if (v->size == v->capacity) {
        *v = resize(v, v->capacity * 2);
    }

    v->array[v->size] = value;
    v->size++;
}

void deleteVector(vector* v) {
    delete[] v->array;
}

void removeFirst(vector* v) {
    for (int i = 0; i < v->size - 1; i++) {
        v->array[i] = v->array[i + 1];
    }
    v->size--;
    if (v->size < v->capacity / 2) {
        *v = resize(v, v->capacity / 2);
    }
}

void removeLast(vector* v) {
    v->size--;
    if (v->size < v->capacity / 2) {
        *v = resize(v, v->capacity / 2);
    }
}

void removeElement(vector* v, int index) {
    for (int i = index; i < v->size - 1; i++) {
        v->array[i] = v->array[i + 1];
    }
    v->size--;
    if (v->size < v->capacity / 2) {
        *v = resize(v, v->capacity / 2);
    }
}

int main () {
    vector v;
    const int SIZE = 2;
    const int CAPACITY = 5;
    
    createVector(&v, CAPACITY, SIZE);
    initializeVector(&v);
    printVector(&v);

    add(&v, 1);
    add(&v, 2);
    add(&v, 3);
    add(&v, 4);

    printVector(&v);

    removeFirst(&v);
    printVector(&v);

    removeLast(&v);
    printVector(&v);

    removeElement(&v, 1);
    printVector(&v);

    return 0;
}
