#include <iostream>
#include <cmath>

using namespace std;

int sigma(int inputnum) {
    if (inputnum == 0)
        return 0;
    else
        return inputnum * pow(2, inputnum) + sigma(inputnum - 1);
}


int main() {
    cout << "Enter Any Positive Number : ";
    int num;
    cin >> num;
    int result = sigma(num);
    cout << result;
    return 0;
}
//
// Created by Á¤¼º¿± on 2022/03/17.
//