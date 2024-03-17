#include<iostream>

using namespace std;

// Use only char*, no direct usage of the C++ string is allowed!

class String {
    char* value;
public:
    // Default constructor
    String () {
        cout << "In default..." << endl;
        this->value  = "Hello world";
    }

    // Custom constructor
    String (char *value) {
        this->value = value;
    }

    // Copy constructor
    String (const String& string) {
        this->value = string.value;
    }

    // Overload operator=
    String& operator=(const String& string) {
        if (this != &string) {
            this->value = string.value;
        }

        return *this;
    }

    // Getter and setter
    char* getValue() {
        return this->value;
    }

    void setValue(char* value) {
        this->value = value;
    }

    //Destructor
    ~String() {
        delete this->value;
    }
    // Length method
    // String* str = new String("ABC");
    // cout << str->length() << endl; -> Output should be 3
    int length() {
        int length = 0;
        for (int i = 0; this->value[i] != '\0'; i++) {
            length++;
        }
        return length;
    }

    // Concat method 
    // String* str = new String("ABC"); 
    // str->concat("abc");
    // cout << str->getValue() << endl; -> Output should be ABCabc
    // If an empty char array is given as argument, then show an error message (or throw an exception)
    void concat(char* value) {

        if (value == "") {
            throw "Empty string";
        }
        int len = this->length();
        int valueLen = 0;
        for (int i = 0; value[i] != '\0'; i++) {
            valueLen++;
        }
        char *result = new char[len + valueLen + 1];

        for (int i = 0; i < len; i++) {
            result[i] = this->value[i];
        }

        for (int i = 0; i < valueLen; i++) {
            result[len + i] = value[i];
        }

        result[len + valueLen] = '\0';
        this->value = result;
    }

    // Replace method
    // String* str = new String("ABC"); 
    // Case 1: 
    // str->replace(1, "DEFGH");
    // cout << str->getValue() << endl; -> Output should be ADEFGHC
    // Case 2:
    // str->replace(0, "DEFGH");
    // cout << str->getValue() << endl; -> Output should be DEFGHBC
    // Case 3:
    // str->replace(2, "DEFGH");
    // cout << str->getValue() << endl; -> Output should be ABDEFGH
    // !!! If the index is out of bounds (< 0 or > length), then show an error message (or throw an exception)
    void replace(int index, char* value) {
        int len = this->length();
        if (index < 0 || index > len) {
            throw "Index out of bounds";
        }

        int valueLen = 0;
        for (int i = 0; value[i] != '\0'; i++) {
            valueLen++;
        }

        char *result = new char[len + valueLen + 1];

        for (int i = 0; i < index; i++) {
            result[i] = this->value[i];
        }

        for (int i = 0; i < valueLen; i++) {
            result[index + i] = value[i];
        }

        for (int i = index + valueLen; i < len + valueLen; i++) {
            result[i] = this->value[i - valueLen];
        }

        result[len + valueLen] = '\0';
        this->value = result;
    }
};

// Write driver code to show every functionality of the class:
// all the constructors, destructor, all methods (except getters and setters)
int main() {

    //showing default constructor
    String* str = new String();
    cout << str->getValue() << endl;

    //showing custom constructor
    String* str2 = new String("ABC");
    cout << str2->getValue() << endl;

    //showing copy constructor
    String* str3 = new String(*str2);
    cout << str3->getValue() << endl;

    //showing operator=
    *str3 = *str;
    cout << str3->getValue() << endl;

    //showing length
    cout << str->length() << endl;

    //showing concat
    try {
        str->concat("abc");
        cout << str->getValue() << endl;
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    //showing replace
    try {
        str->replace(1, "DEFGH");
        cout << str->getValue() << endl;
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}