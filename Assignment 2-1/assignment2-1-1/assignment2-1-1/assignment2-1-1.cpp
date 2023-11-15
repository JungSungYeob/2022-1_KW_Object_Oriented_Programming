#include <iostream>

using namespace std;

int main() {
    srand(time(NULL));
    int num[10];
    for (int i = 0; i < 10; i++) {
        num[i] = rand() % 10;
        cout << "Memory Address is " << &num[i] << "\nValue is " << num[i] << endl;
    }
    int* Max;
    int* Min;
    Max = &num[0];
    Min = &num[0];
    for (int i = 1; i < 10; i++) {
        if (num[i] > *Max)
            Max = &num[i];
        if (num[i] < *Min)
            Min = &num[i];
    }
    cout << "Max Data is " << *Max << "(" << Max << ")" << endl;
    cout << "Min Data is " << *Min << "(" << Min << ")" << endl;


    return 0;
}


//
// Created by Á¤¼º¿± on 2022/04/07.
//

