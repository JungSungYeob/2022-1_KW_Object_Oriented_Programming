#include <iostream>

using namespace std;


class TwoPoint {
private:
    int A, B, C, D;
public:
    TwoPoint(int a1, int b1, int c1, int d1) {
        A = a1, B = b1, C = c1, D = d1;
    }

    virtual void print() {
        cout << "Point 1 : " << A << "," << B << endl;
        cout << "Point 2 : " << C << "," << D << endl;
    }

};

class Equation : public TwoPoint {
private:
    float inc;
    float y_int;
public:
    Equation(float a2, float b2, float c2, float d2) : TwoPoint(a2, b2, c2, d2) {
        inc = (d2 - b2) / (c2 - a2);
        y_int = b2 - (inc * a2);
    }

    void print() {
        cout << "Equation : y = " << inc << "x + " << y_int << endl;
    }


};

int main() {
    class TwoPoint* A = new TwoPoint(2, 4, 7, 8);
    class TwoPoint* B = new Equation(2, 4, 7, 8);
    A->print();
    B->print();
    delete A;
    delete B;
}

//
// Created by Á¤¼º¿± on 2022/05/24.
//
