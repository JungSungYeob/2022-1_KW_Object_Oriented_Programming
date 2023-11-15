#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

class mystring {

private:
    char *string = new char[100];
public:

    mystring() {
        string[0] = '\0';
    }
    ~mystring() {
        delete string;
    }
    void operator += (const char* str) {
        strcat(string, str);
    }

    void operator-=(const char str) {
        int i = 0;
        while (string[i] != '\0') {
            if (string[i] == str) {
                int j = i;
                while (string[j] != '\0')
                {
                    string[j] = string[j + 1];
                    j++;
                }
            }
            else {
                i++;
            }
        }
    }

    void operator --(int) {
        int len = strlen(string);
        string[len - 1] = '\0';
    }

    void operator&&(const char str) {
        int len = strlen(string);
        for (int i = 0; i < len; i++) {
            if (string[i] != str) {
                string[i] = '0';
            }
        }
    }

    void print();

};

void mystring::print() {
    cout << string << endl;
}

int main() {
    mystring A;
    while (1) {
        cout
            << "Please Enter command(1: add, 2: delete_char, 3: delete_lastchar, 4: and_operator, 5: print, 6: exit) : ";
        int command;
        cin >> command;
        if (command == 1) {
            char word[50];
            cin >> word;
            A += word;
        }
        else if (command == 2) {
            char word;
            cin >> word;
            A -= word;
        }
        else if (command == 3) {
            A--;
        }
        else if (command == 4) {
            char word;
            cin >> word;
            A&& word;
        }
        else if (command == 5) {
            A.print();
        }
        else if (command == 6) {
            break;
        }
        else
            continue;
    }
    return 0;
}
//
// Created by Á¤¼º¿± on 2022/05/17.
//
