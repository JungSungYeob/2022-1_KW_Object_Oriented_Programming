#include <iostream>
#include <cmath>

using namespace std;

class Polygon {
private:
    int Area;
    int Perimeter;
public:
    Polygon(int a, int b, int c)
    {
        if (c == 0)
        {
            Perimeter = 2 * (a + b);
            Area = a * b;
        }
        else
        {
            Perimeter = a + b + c;
            int s = (a + b + c) / 2;
            int S = s * (s - a) * (s - b) * (s - c);
            Area = sqrt(S);
        }
    }
    void print_Area();
    void print_Perimeter();
};

void Polygon::print_Area() {

    cout << "Area is " << Area << endl;
}

void Polygon::print_Perimeter() {

    cout << "Perimeter is " << Perimeter << endl;
}


class Triangle : public Polygon {
private:
    int A;
    int B;
    int C;
public:
    Triangle(int a, int b, int c) : Polygon(a, b, c) {
        this->A = a;
        this->B = b;
        this->C = c;
    }
};

class Square : public Polygon {
private:
    int A;
    int B;
public:
    Square(int a, int b) : Polygon(a, b, 0) {
        this->A = a;
        this->B = b;
    }
};

int main() {
    class Square A(5, 4);
    class Triangle B(13, 14, 15);

    cout << "-------Square-------" << endl;
    A.print_Area();
    A.print_Perimeter();
    cout << "--------------------" << endl;
    cout << "------Triangle------" << endl;
    B.print_Area();
    B.print_Perimeter();
    cout << "--------------------" << endl;

}

//
// Created by 정성엽 on 2022/05/17.
//
