#include <iostream>

using namespace std;

int my_strcmp(const char* pStr1, const char* pStr2) {
    if (pStr1 == NULL || pStr2 == NULL)
        return -1;
    for (; (*pStr1) != '\0' || (*pStr2) != '\0'; pStr1++, pStr2++) {
        if ((*pStr1) > (*pStr2)) return 1;
        if ((*pStr1) < (*pStr2)) return -1;
    }
    return 0;
}

class My_string {
private:
    char* str;
public:

    My_string(char* tmp_input) {
        str = tmp_input;
    }

    int my_strlen() {
        int i = 0;
        while (str[i] != '\0')
            i++;
        return i;
    }

    void my_strcpy(char* tmp_str) {
        int i=0;
        while (str[i] != '\0' || tmp_str[i]!='\0')
        {
            str[i] = tmp_str[i++];
        }
        cout << "strcpy is done" << endl;
    }

    void my_strcat(char* tmp_str) {
        int length = my_strlen();
        for (int i = 0; tmp_str[i] != '\0'; i++)
            str[length++] = tmp_str[i];
        str[length] = '\0';
        cout << "strcat is done" << endl;
    }
    void print() {
        cout << "Current String :" << str << endl;
    }
};

int main() {
    cout << "First String :";
    char* input_string = new char[20];
    cin >> input_string;
    class My_string command(input_string);
    while (1) {
        char word[10];
        cout << "Please Enter Command(strlen, strcpy, strcat, print, quit) :";
        cin >> word;
        if (my_strcmp(word, "quit") == 0)
            break;
        else if (my_strcmp(word, "strlen") == 0)
            cout << "String Length :" << command.my_strlen() << endl;
        else if (my_strcmp(word, "strcpy") == 0) {
            char* tmp_word1 = new char[20];
            cin >> tmp_word1;
            command.my_strcpy(tmp_word1);
            delete[]tmp_word1;
        }
        else if (my_strcmp(word, "strcat") == 0) {
            char* tmp_word2 = new char[20];
            cin >> tmp_word2;
            command.my_strcat(tmp_word2);
            delete[]tmp_word2;
        }
        else if (my_strcmp(word, "print") == 0)
            command.print();
        else {
            cout << endl;
            continue;
        }
    }
    delete[]input_string;

    return 0;
}



//
// Created by Á¤¼º¿± on 2022/04/27.
