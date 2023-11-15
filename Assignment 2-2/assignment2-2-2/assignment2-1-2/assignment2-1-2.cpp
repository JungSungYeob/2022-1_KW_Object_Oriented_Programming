#include<iostream>

using namespace std;

void Fullsent(int len1, int len2, char* result, char *input_sent1, char *input_sent2) {

    for (int i = 0; i < len1; i++) {
        result[i] = input_sent1[i];
    }
    result[len1] = ' ';

    for (int i = 0; i < len2 + 1; i++) {
        result[i + len1 + 1] = input_sent2[i];
    }
}
int main() {
    char sent1[50];
    cout << "String 1 :";
    cin.getline(sent1, 50, '\n');

    int length1 = 0;
    while (sent1[length1] != NULL)
        length1++;

    char sent2[50];
    cout << "String 2 :";
    cin.getline(sent2, 50, '\n');

    int length2 = 0;
    while (sent2[length2] != NULL)
        length2++;

    char* result_Sent = new char[length1 + length2 + 2];

    Fullsent(length1, length2, result_Sent, sent1, sent2);

    cout << "Result : ";
    cout << result_Sent;

    delete []result_Sent;

    return 0;
}

//
// Created by Á¤¼º¿± on 2022/03/31.
//