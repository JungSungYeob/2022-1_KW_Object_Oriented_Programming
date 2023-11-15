#include <iostream>

using namespace std;

class A {
private:
    int num = 1;
public:

    A(int a) {
        num = a;
        cout << "Class A is Created with " << num << endl;
    }
    ~A() { cout << "Class A is Destroyed with " << num << endl; }
};

int main() {
    cout << "Enter Any Number :";
    int tmp_num;
    cin >> tmp_num;

    A create(tmp_num);

    return 0;
}

//
// Created by Á¤¼º¿± on 2022/04/27.
//