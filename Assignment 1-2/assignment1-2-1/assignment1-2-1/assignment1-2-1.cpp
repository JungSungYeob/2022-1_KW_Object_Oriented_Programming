#include <iostream>

using namespace std;

int main() {
    cout << "Enter Two Number :";
    int num1, num2;
    cin >> num1 >> num2;
    if (num1 > num2) {
        cout << num1 << " > " << num2 << endl;
    }
    else if (num1 < num2) {
        cout << num1 << " < " << num2 << endl;
    }
    else {
        cout << num1 << " = " << num2 << endl;
    }
    return 0;
}
//
// Created by ������ on 2022/03/17.
//