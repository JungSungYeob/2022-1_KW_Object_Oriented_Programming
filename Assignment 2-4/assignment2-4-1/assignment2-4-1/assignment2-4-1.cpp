#include <iostream>

using namespace std;

class Overloading {
public:
    void add(int a, int b);

    void add(float a, float b);

    void add(unsigned int a, unsigned int b);
};

void Overloading::add(int A, int B) {
    cout << "Int type add : " << A + B << endl;
}

void Overloading::add(float A, float B) {
    cout << "Float type add : " << A + B << endl;
}

void Overloading::add(unsigned int A, unsigned int B) {
    cout << "Unsigned int type add : " << A + B << endl;
}

int main() {
    class Overloading A;
    int int_a = 5, int_b = -10;
    float float_a = 5.1, float_b = 5.3;
    unsigned int unsigned_int_a = 5, unsigned_int_b = 5;

    A.add(int_a, int_b);
    A.add(float_a, float_b);
    A.add(unsigned_int_a, unsigned_int_b);
    return 0;

}


//
// Created by Á¤¼º¿± on 2022/05/10.
//
