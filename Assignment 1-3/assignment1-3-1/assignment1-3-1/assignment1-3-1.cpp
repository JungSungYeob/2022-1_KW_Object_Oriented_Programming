#include <iostream>
#include <fstream>

using namespace std;


int main() {
    ifstream fin("Assignment.txt");//파일 찾고 열기
    int num[20];
    cout << "Input array : ";
    for (int i = 0; i < 20; i++) {
        fin >> num[i];
        cout << num[i] << " ";
    }
    cout << endl;
    int temp;
    for (int i = 0; i < 20; i++) {
        for (int j = i + 1; j < 20; j++) {
            if (num[i] > num[j]) {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    cout << "Sorted array : ";
    for (int i = 0; i < 20; i++) {
        cout << num[i] << " ";
    }

    fin.close();//파일 닫기

    return 0;
}
//
// Created by 정성엽 on 2022/03/23.
//