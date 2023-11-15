#include <iostream>
#include <cstring>

using namespace std;

class Student_info {
private:
    char name[10];
    int age = 0;
    char university[100];
    char major[100];
public:
    Student_info(char* name, int age, char* univ, char* major);

    bool find(char* name);

    void print();

    void change(char* name, int age, char* univ, char* major);
};

Student_info::Student_info(char* input_name, int Age, char* univ, char* Major) {
    strcpy_s(name, input_name);
    age = Age;
    strcpy_s(university, univ);
    strcpy_s(major, Major);
}

bool Student_info::find(char* input_name) {
    if (strcmp(name, input_name) == 0)
        return true;
    else
        return false;
}

void Student_info::print() {
    cout << "Name : " << name << endl;
    cout << "Age : " << age << endl;
    cout << "University : " << university << endl;
    cout << "Major : " << major << endl;
    cout << "--------------------" << endl;
}

void Student_info::change(char* input_name, int Age, char* univ, char* Major) {
    strcpy_s(name, input_name);
    age = Age;
    strcpy_s(university, univ);
    strcpy_s(major, Major);
}

int main() {
    Student_info* arr[10];
    int student_num = 0;
    while (1) {
        char word[10];
        cout << "Please Enter Command(insert, find, change, print, exit) :";
        cin >> word;
        if (strcmp(word, "exit") == 0)
            break;
        else if (strcmp(word, "insert") == 0) {
            char Name[10];
            int Age;
            char University[100];
            char Major[100];
            cin >> Name >> Age >> University >> Major;
            arr[student_num++] = new Student_info(Name, Age, University, Major);
        }
        else if (strcmp(word, "find") == 0) {
            cout << "--------find--------" << endl;
            char Compare_Name[10];
            cin >> Compare_Name;
            for (int i = 0; i < student_num; i++) {
                if (arr[i]->find(Compare_Name) == 1) {
                    arr[i]->print();
                }
            }
        }
        else if (strcmp(word, "change") == 0) {
            char Compare_Name[10];
            cin >> Compare_Name;
            for (int i = 0; i < student_num; i++) {
                if (arr[i]->find(Compare_Name) == 1) {
                    char Name[10];
                    int Age;
                    char University[100];
                    char Major[100];
                    cin >> Name >> Age >> University >> Major;
                    arr[i]->change(Name, Age, University, Major);
                    break;
                }
            }

        }
        else if (strcmp(word, "print") == 0) {
            cout << "--------print--------" << endl;
            for (int i = 0; i < student_num; i++)
                arr[i]->print();
            cout << "--------------------" << endl;
        }
        else {
            cout << endl;
            continue;
        }
    }
    for (int i = 0; i < student_num; i++)
    {
        delete arr[i];
    }

    return 0;
}

//
// Created by Á¤¼º¿± on 2022/04/27.
//