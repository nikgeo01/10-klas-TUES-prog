#include <iostream>
#include <stdlib.h>
using namespace std;
//new types: string, bool

void foo()
{
    printf("hello!\n");
    cout<< "Hello" << endl;
}

int main()
{
    foo();
    int *a = (int*) malloc (sizeof(int));
    int *b = new int;

    return 0;
}