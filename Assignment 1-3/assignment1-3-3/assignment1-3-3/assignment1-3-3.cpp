#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("Assignment.txt");
    char word[100][21] = { '\0', };
    int length[100];
    int amount_length[21] = { 0, };
    int i = 0;
    while (!fin.eof()) {
        fin >> word[i++];
    }
    for (int j = 0; j < 100; j++) {
        if (word[j][0] == '\0')
            break;
        for (int a = 0; a < 21; a++) {
            if (word[j][a] == '\0') {
                length[j] = a;
                break;
            }
        }
    }
    for (int a = 0; a < 100; a++) {
        if (word[a][0] == '\0')
            break;
        for (int b = 1; b <= 20; b++) {
            if (length[a] == b)
                amount_length[b]++;
        }
    }
    for (int a = 1; a < 21; a++) {
        if (amount_length[a] > 0) {
            cout << "Length " << a << " :";
            for (int b = 0; b < 100; b++) {
                if (length[b] == a)
                    cout << word[b] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
//
// Created by Á¤¼º¿± on 2022/03/24.
//