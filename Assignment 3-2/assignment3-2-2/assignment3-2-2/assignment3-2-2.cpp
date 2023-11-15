#include <iostream>
#include <cstring>
using namespace std;

class 대학 {
private:
    char U_Name[20];
    int year;
    char U_StuID[20];
public:
    대학(char* Uname, char* ID, int Year, char OOT, char DLC, char* Sname, int Sage) {
        strcpy_s(U_Name, Uname);
        strcpy_s(U_StuID, ID);
        year = Year;
    }

    void U_print() {
        cout << "학교: " << U_Name << endl << "학번 :" << U_StuID << endl << "학년 :" << year << endl;
    }
    char* rt_ID()
    {
        return U_StuID;
    }
};

class 컴퓨터정보공학 : public 대학 {
private:
    char Object_Oriented_Progrmaing;
    char Digital_Logic_Circuit;
public:
    컴퓨터정보공학(char* Uname, char* ID, int Year, char OOT, char DLC, char* Sname, int Sage) : 대학(Uname, ID, Year, OOT, DLC,
        Sname, Sage) {
        Object_Oriented_Progrmaing = OOT;
        Digital_Logic_Circuit = DLC;
    }

    void C_print() {
        cout << "객체지향프로그래밍 학점 :" << Object_Oriented_Progrmaing << endl << "디지털논리회로 학점 :" << Digital_Logic_Circuit << endl;
    }
};

class 학생정보 : public 컴퓨터정보공학 {
private:
    char Name[10];
    int age;
public:
    학생정보(char* Uname, char* ID, int Year, char OOT, char DLC, char* Sname, int Sage) : 컴퓨터정보공학(Uname, ID, Year, OOT,
        DLC, Sname, Sage) {
        strcpy_s(Name, Sname);
        age = Sage;
    }
    char* rt_Name()
    {
        return Name;
    }
};

int main() {
    int size = 0;
    class 학생정보* A[100];
    while (1) {
        char command[10];
        cin >> command;
        if (strcmp(command, "INSERT") == 0) {
            if (size >= 100)
                continue;
            char Uni_name[20];
            cout << "학교 :";
            cin >> Uni_name;
            char Uni_ID[20];
            cout << "학번: ";
            cin >> Uni_ID;
            int year;
            cout << "학년: ";
            cin >> year;
            char OOT_grade;
            cout << "객체지향프로그래밍 학점 :";
            cin >> OOT_grade;
            char DLC_grade;
            cout << "디지털논리회로 학점 :";
            cin >> DLC_grade;
            char name[10];
            cout << "이름 :";
            cin >> name;
            int age;
            cout << "나이 :";
            cin >> age;
            A[size++] = new 학생정보(Uni_name, Uni_ID, year, OOT_grade, DLC_grade, name, age);
        }
        else if (strcmp(command, "FIND") == 0) {
            char name[10];
            cin >> name;
            char ID[20];
            cin >> ID;
            for (int i = 0; i <= size; i++)
            {
                if (strcmp(A[i]->rt_Name(), name) == 0 && strcmp(A[i]->rt_ID(), ID) == 0)
                {
                    cout << endl;
                    A[i]->U_print();
                    A[i]->C_print();
                    break;
                }
            }
        }
        else if (strcmp(command, "EXIT") == 0) {
            break;
        }
        else
            continue;
    }
    for (int i = 0; i < size; i++)
    {
        delete A[i];
    }
    return 0;
}

//
// Created by 정성엽 on 2022/05/24.
//
