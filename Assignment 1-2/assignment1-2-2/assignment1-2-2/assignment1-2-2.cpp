#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "Enter any Number :";
    int num;
    cin >> num;
    for (int i = 1; i <= 20; i++) {

        cout << setw(10) << std::left << i;
        if (i % num == 0)
            cout << "\n";
    }

    return 0;

}
//
// Created by Á¤¼º¿± on 2022/03/17.
//