#include <iostream>
#include <cstring>
using namespace std;

class ���� {
private:
    char U_Name[20];
    int year;
    char U_StuID[20];
public:
    ����(char* Uname, char* ID, int Year, char OOT, char DLC, char* Sname, int Sage) {
        strcpy_s(U_Name, Uname);
        strcpy_s(U_StuID, ID);
        year = Year;
    }

    void U_print() {
        cout << "�б�: " << U_Name << endl << "�й� :" << U_StuID << endl << "�г� :" << year << endl;
    }
    char* rt_ID()
    {
        return U_StuID;
    }
};

class ��ǻ���������� : public ���� {
private:
    char Object_Oriented_Progrmaing;
    char Digital_Logic_Circuit;
public:
    ��ǻ����������(char* Uname, char* ID, int Year, char OOT, char DLC, char* Sname, int Sage) : ����(Uname, ID, Year, OOT, DLC,
        Sname, Sage) {
        Object_Oriented_Progrmaing = OOT;
        Digital_Logic_Circuit = DLC;
    }

    void C_print() {
        cout << "��ü�������α׷��� ���� :" << Object_Oriented_Progrmaing << endl << "�����г�ȸ�� ���� :" << Digital_Logic_Circuit << endl;
    }
};

class �л����� : public ��ǻ���������� {
private:
    char Name[10];
    int age;
public:
    �л�����(char* Uname, char* ID, int Year, char OOT, char DLC, char* Sname, int Sage) : ��ǻ����������(Uname, ID, Year, OOT,
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
    class �л�����* A[100];
    while (1) {
        char command[10];
        cin >> command;
        if (strcmp(command, "INSERT") == 0) {
            if (size >= 100)
                continue;
            char Uni_name[20];
            cout << "�б� :";
            cin >> Uni_name;
            char Uni_ID[20];
            cout << "�й�: ";
            cin >> Uni_ID;
            int year;
            cout << "�г�: ";
            cin >> year;
            char OOT_grade;
            cout << "��ü�������α׷��� ���� :";
            cin >> OOT_grade;
            char DLC_grade;
            cout << "�����г�ȸ�� ���� :";
            cin >> DLC_grade;
            char name[10];
            cout << "�̸� :";
            cin >> name;
            int age;
            cout << "���� :";
            cin >> age;
            A[size++] = new �л�����(Uni_name, Uni_ID, year, OOT_grade, DLC_grade, name, age);
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
// Created by ������ on 2022/05/24.
//
