#include <iostream>

using namespace std;

char upper_function(bool input1, bool input2) {
    if (input1 == true && input2 == true)
        return 'A';
    else if (input1 == true && input2 == false)
        return 'B';
    else if (input1 == false && input2 == true)
        return 'C';
    else
        return 'D';
}

int main() {
    cout << "Array 1 :";
    char array1[11];
    cin >> array1;
    cout << "Array 2 :";
    char array2[11];
    cin >> array2;
    char tmp;
    for (int i = 0; i < 11; i++) {
        bool upper1 = false;
        bool upper2 = false;
        if (array1[i] <= 90)
            upper1 = true;
        if (array2[i] <= 90)
            upper2 = true;
        switch (upper_function(upper1, upper2)) {
        case 'A':
            if (array1[i] < array2[i]) {
                tmp = array1[i];
                array1[i] = array2[i];
                array2[i] = tmp;
            }
            break;
        case 'B':

            if (array1[i] < array2[i] - 32) {
                tmp = array1[i];
                array1[i] = array2[i];
                array2[i] = tmp;
            }
            break;
        case 'C':
            if (array1[i] - 32 < array2[i]) {
                tmp = array1[i];
                array1[i] = array2[i];
                array2[i] = tmp;
            }
            break;
        case 'D':
            if (array1[i] < array2[i]) {
                tmp = array1[i];
                array1[i] = array2[i];
                array2[i] = tmp;
            }
            break;
        }
    }
    cout << "Exchanged Array 1 :" << array1 << endl;
    cout << "Exchanged Array 2 :" << array2 << endl;

    return 0;
}
//
// Created by Á¤¼º¿± on 2022/03/23.
//