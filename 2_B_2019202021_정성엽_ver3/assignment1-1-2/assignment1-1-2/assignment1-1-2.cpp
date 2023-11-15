#include <iostream>

using namespace std;

unsigned long long int Plus_two_num(unsigned long long int a, unsigned long long int b) {
   
    return a+b;
}

int main() {
    unsigned long int num1=0, num2=0;
    cout << "Enter Two Numbers :";
    cin >> num1 >> num2;
    cout << Plus_two_num(num1, num2);

    return 0;
}

//
// Created by Á¤¼º¿± on 2022/03/09.
//