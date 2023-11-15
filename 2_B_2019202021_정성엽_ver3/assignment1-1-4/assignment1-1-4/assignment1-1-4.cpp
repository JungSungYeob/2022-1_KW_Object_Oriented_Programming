#include <iostream>

using namespace std;
//전역변수 선언
int num1;
int num2;
//제곱 함수
void num_squared(int a) {
    num1=a*a;
}
//세제곱 함수
void num_cubic(int& b) {
    num2=b*b*b;
}

int main() {
    cout << "Number :";
    int num;
    cin >> num;
    num_squared(num);
    num_cubic(num);
    cout << "Number^2 : " << num1 << "\nNumber^3 : " << num2;
    return 0;
}

//
// Created by 정성엽 on 2022/03/09.
//

