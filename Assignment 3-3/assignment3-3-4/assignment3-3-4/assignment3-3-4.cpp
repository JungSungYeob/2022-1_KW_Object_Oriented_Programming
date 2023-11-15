#include <iostream>
#include <fstream>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Node {
public:
    Node(char* Major, int Year, char* Name, Node* Next) { //다음 노드도 저장하도록 함.
        //전공 입력
        if (Major != NULL) {
            strcpy_s(this->major, Major);
            major_next = Next;
        }
        //년도 입력
        else if (Year != 0) {
            this->year = Year;
            year_next = Next;
        }
        //이름 입력
        else if (Name != NULL) {
            strcpy_s(this->name, Name);
        }
    }

    Node* major_next, * year_next, * name_next, * name_Lnext, * name_Rnext;
    char major[50];
    int year;
    char name[50];
};

class Manage {
private:
    Node* head;
public:
    Manage() { head = NULL; }

    ~Manage() {
        Node* majorNode = head;
        Node* prevNode = NULL;
        Node* yearNode = NULL;
        Node* nameNode = NULL;
        while (majorNode != NULL) {
            yearNode = majorNode->year_next;
            while (yearNode != NULL) {
                nameNode = yearNode->name_next;
                freeNode(nameNode);
                prevNode = yearNode;
                yearNode = yearNode->year_next;
                delete prevNode;
            }
            prevNode = majorNode;
            majorNode = majorNode->major_next;
            delete prevNode;
        }
    }

    void freeNode(Node* currNode) {
        if (currNode != nullptr) {
            freeNode(currNode->name_Rnext);
            freeNode(currNode->name_Lnext);
            delete currNode;
        }
    }


    void print_all() {
        Node* majorNode = head;
        Node* yearNode = NULL;
        Node* nameNode = NULL;
        while (majorNode != NULL) {
            yearNode = majorNode->year_next;
            while (yearNode != NULL) {
                nameNode = yearNode->name_next;
                print_info(majorNode, yearNode, nameNode);
                yearNode = yearNode->year_next;
            }
            majorNode = majorNode->major_next;
        }
    }

    void print_info(Node* Majornode, Node* Yearnode, Node* Namenode) {
        if (Namenode != nullptr) {
            cout << Majornode->major << " " << Yearnode->year << " " << Namenode->name << endl;
            print_info(Majornode, Yearnode, Namenode->name_Rnext);
            print_info(Majornode, Yearnode, Namenode->name_Lnext);
        }
    }

    void insert_major(char* major, bool file = true) {
        Node* currNode = head;
        Node* prevNode = NULL;
        if (head != NULL) {
            while (1) {
                if (strcmp(major, currNode->major) == 0) {
                    break;
                }
                else {
                    int tmp = 0;
                    bool escape = false;
                    while (currNode->major[tmp] != '\0' || major[tmp] != '\0') {
                        if (currNode->major[tmp] < major[tmp]) {
                            prevNode = currNode;
                            currNode = currNode->major_next;
                            if (currNode != NULL) {
                                tmp = 0;
                                continue;
                            }
                            else {
                                prevNode->major_next = new Node(major, 0, NULL, NULL);
                                escape = true;
                                break;
                            }
                        }
                        else if (currNode->major[tmp] == major[tmp]) {
                            tmp++;
                            continue;
                        }
                        else {
                            if (prevNode != NULL) {
                                prevNode->major_next = new Node(major, 0, NULL, currNode);
                                escape = true;
                                break;
                            }
                            else {
                                head = new Node(major, 0, NULL, currNode); \
                                    escape = true;
                                break;
                            }
                        }
                    }
                    if (escape == true)
                        break;
                }
            }
        }
        else {
            head = new Node(major, 0, NULL, NULL);
        }
    }

    void insert_year(char* major, int year, bool file = true) {
        Node* currNode = head;
        Node* prevNode = NULL;
        while (strcmp(major, currNode->major) != 0) {
            currNode = currNode->major_next;
        }
        prevNode = currNode;
        currNode = currNode->year_next;
        Node* tmp = currNode;
        if (currNode != NULL) {
            while (1) {
                if (currNode->year == year) {
                    break;
                }
                else if (currNode->year < year) {
                    prevNode = currNode;
                    currNode = currNode->year_next;
                    if (currNode == NULL) {
                        prevNode->year_next = new Node(NULL, year, NULL, NULL);
                        break;
                    }
                    else {
                        continue;
                    }
                }
                else {
                    prevNode->year_next = new Node(NULL, year, NULL, currNode);
                    break;
                }
            }
        }
        else {
            prevNode->year_next = new Node(NULL, year, NULL, NULL);
        }
    }

    void insert_name(char* major, int year, char* name, bool file = true) {
        Node* currNode = head;
        Node* prevNode = NULL;
        while (strcmp(major, currNode->major) != 0) {
            if (file == false)
                cout << currNode->major << " -> ";
            currNode = currNode->major_next;
        }
        if (file == false)
            cout << currNode->major << " -> ";
        currNode = currNode->year_next;
        while (year != currNode->year) {
            if (file == false)
                cout << currNode->year << " -> ";
            currNode = currNode->year_next;
        }
        if (file == false)
            cout << currNode->year << " -> ";
        prevNode = currNode;
        currNode = currNode->name_next;
        if (currNode != NULL) {
            while (1) {
                int tmp = 0;
                bool escape = false;
                while (currNode->name[tmp] != '\0' && name[tmp] != '\0') {
                    if (currNode->name[tmp] == name[tmp]) {
                        tmp++;
                        continue;
                    }
                    else if (currNode->name[tmp] < name[tmp]) {
                        if (currNode->name_Rnext != NULL) {
                            if (file == false)
                                cout << currNode->name << " -> ";
                            currNode = currNode->name_Rnext;
                            tmp = 0;
                        }
                        else {
                            currNode->name_Rnext = new Node(NULL, 0, name, NULL);
                            if (file == false)
                                cout << currNode->name_Rnext->name << endl;
                            escape = true;
                            break;
                        }
                    }
                    else {
                        if (currNode->name_Lnext != NULL) {
                            if (file == false)
                                cout << currNode->name << " -> ";
                            currNode = currNode->name_Lnext;
                            tmp = 0;
                        }
                        else {
                            currNode->name_Lnext = new Node(NULL, 0, name, NULL);
                            if (file = false)
                                cout << currNode->name_Lnext->name << endl;
                            escape = true;
                            break;
                        }
                    }
                }
                if (escape == true)
                    break;
            }
        }
        else {
            prevNode->name_next = new Node(NULL, 0, name, NULL);
            if (file == false)
                cout << prevNode->name_next->name << endl;
        }
    }

    void delete_node(char* major, int year, char* name) {
        Node* majorNode = head;
        Node* prevmajorNode = NULL;
        Node* yearNode = NULL;
        Node* prevyearNode = NULL;
        while (strcmp(majorNode->major, major) != 0) {
            prevmajorNode = majorNode;
            majorNode = majorNode->major_next;
        }
        prevyearNode = majorNode;
        yearNode = majorNode->year_next;
        while (yearNode->year != year) {
            prevyearNode = yearNode;
            yearNode = yearNode->year_next;
        }
        Node* currNode = yearNode->name_next;
        Node* prevNode = yearNode;
        //위치 찾기
        while (currNode != NULL) {
            if (strcmp(currNode->name, name) == 0) {
                break;
            }
            else {
                int tmp = 0;
                while (currNode->name[tmp] != '\0' && name[tmp] != '\0') {
                    if (currNode->name[tmp] == name[tmp]) {
                        tmp++;
                        continue;
                    }
                    else if (currNode->name[tmp] < name[tmp]) {
                        prevNode = currNode;
                        currNode = currNode->name_Rnext;
                        tmp = 0;
                        break;
                    }
                    else {
                        prevNode = currNode;
                        currNode = currNode->name_Lnext;
                        tmp = 0;
                        break;
                    }
                }
            }
        }

        //찾았으면
        if (prevNode != yearNode) {
            if (currNode->name_Lnext != NULL && currNode->name_Rnext != NULL) {
                Node* tmpNode = currNode;
                prevNode = currNode;
                currNode = currNode->name_Rnext;
                int cnt = 0;
                while (currNode->name_Lnext != NULL) {
                    prevNode = currNode;
                    currNode = currNode->name_Lnext;
                    cnt++;
                }
                if (cnt > 0) {
                    strcpy_s(tmpNode->name, currNode->name);
                    if (currNode->name_Rnext != NULL) {
                        int tmp = 0;
                        while (prevNode->name[tmp] != '\0' && currNode->name_Rnext->name[tmp] != '\0') {
                            if (prevNode->name[tmp] == currNode->name_Rnext->name[tmp]) {
                                tmp++;
                                continue;
                            }
                            else if (prevNode->name[tmp] < currNode->name_Rnext->name[tmp]) {
                                prevNode->name_Rnext = currNode->name_Rnext;
                                break;
                            }
                            else {
                                prevNode->name_Lnext = currNode->name_Rnext;
                                break;
                            }
                        }
                    }
                    else {
                        int tmp = 0;
                        while (prevNode->name[tmp] != '\0' && currNode->name[tmp] != '\0') {
                            if (prevNode->name[tmp] == currNode->name[tmp]) {
                                tmp++;
                                continue;
                            }
                            else if (prevNode->name[tmp] < currNode->name[tmp]) {
                                prevNode->name_Rnext = NULL;
                                break;
                            }
                            else {
                                prevNode->name_Lnext = NULL;
                                break;
                            }
                        }
                    }
                    delete currNode;
                }
                else {
                    if (currNode->name_Rnext != NULL) {
                        strcpy_s(tmpNode->name, currNode->name);
                        tmpNode->name_Rnext = currNode->name_Rnext;
                        delete currNode;
                    }
                    else {
                        strcpy_s(tmpNode->name, currNode->name);
                        tmpNode->name_Rnext = NULL;
                        delete currNode;
                    }
                }
            }
            else if (currNode->name_Lnext != NULL && currNode->name_Rnext == NULL) {
                int tmp = 0;
                while (prevNode->name[tmp] != '\0' && currNode->name_Lnext->name[tmp] != '\0') {
                    if (prevNode->name[tmp] == currNode->name_Lnext->name[tmp]) {
                        tmp++;
                        continue;
                    }
                    else if (prevNode->name[tmp] < currNode->name_Lnext->name[tmp]) {
                        prevNode->name_Rnext = currNode->name_Lnext;
                        break;
                    }
                    else {
                        prevNode->name_Lnext = currNode->name_Lnext;
                        break;
                    }
                }
                delete currNode;
            }
            else if (currNode->name_Lnext == NULL && currNode->name_Rnext != NULL) {
                int tmp = 0;
                while (prevNode->name[tmp] != '\0' && currNode->name_Rnext->name[tmp] != '\0') {
                    if (prevNode->name[tmp] == currNode->name_Rnext->name[tmp]) {
                        tmp++;
                        continue;
                    }
                    else if (prevNode->name[tmp] < currNode->name_Rnext->name[tmp]) {
                        prevNode->name_Rnext = currNode->name_Rnext;
                        break;
                    }
                    else {
                        prevNode->name_Lnext = currNode->name_Rnext;
                        break;
                    }
                }
                delete currNode;
            }
            else {
                int tmp = 0;
                while (prevNode->name[tmp] != '\0' && currNode->name[tmp] != '\0') {
                    if (prevNode->name[tmp] == currNode->name[tmp]) {
                        tmp++;
                        continue;
                    }
                    else if (prevNode->name[tmp] < currNode->name[tmp]) {
                        prevNode->name_Rnext = NULL;
                        break;
                    }
                    else {
                        prevNode->name_Lnext = NULL;
                        break;
                    }
                }
                delete currNode;
            }
        }
        else //첫번째인 경우
        {
            if (currNode->name_Lnext != NULL && currNode->name_Rnext != NULL) {
                Node* tmpNode = currNode;
                prevNode = currNode;
                currNode = currNode->name_Rnext;
                int cnt = 0;
                while (currNode->name_Lnext != NULL) {
                    prevNode = currNode;
                    currNode = currNode->name_Lnext;
                    cnt++;
                }
                if (cnt > 0) {
                    strcpy_s(tmpNode->name, currNode->name);
                    if (currNode->name_Rnext != NULL) {
                        int tmp = 0;
                        while (prevNode->name[tmp] != '\0' && currNode->name_Rnext->name[tmp] != '\0') {
                            if (prevNode->name[tmp] == currNode->name_Rnext->name[tmp]) {
                                tmp++;
                                continue;
                            }
                            else if (prevNode->name[tmp] < currNode->name_Rnext->name[tmp]) {
                                prevNode->name_Rnext = currNode->name_Rnext;
                                delete currNode;
                                break;
                            }
                            else {
                                prevNode->name_Lnext = currNode->name_Rnext;
                                delete currNode;
                                break;
                            }
                        }
                        delete currNode;

                    }
                    else {
                        int tmp = 0;
                        while (prevNode->name[tmp] != '\0' && currNode->name[tmp] != '\0') {
                            if (prevNode->name[tmp] == currNode->name[tmp]) {
                                tmp++;
                                continue;
                            }
                            else if (prevNode->name[tmp] < currNode->name[tmp]) {
                                delete currNode;
                                prevNode->name_Rnext = NULL;
                                break;
                            }
                            else {
                                delete currNode;
                                prevNode->name_Lnext = NULL;
                                break;
                            }
                        }

                    }
                }
                else {
                    if (currNode->name_Rnext != NULL) {
                        strcpy_s(tmpNode->name, currNode->name);
                        tmpNode->name_Rnext = currNode->name_Rnext;
                        delete currNode;
                    }
                    else {
                        strcpy_s(tmpNode->name, currNode->name);
                        tmpNode->name_Rnext = NULL;
                        delete currNode;
                    }
                }
            }
            else if (currNode->name_Lnext != NULL && currNode->name_Rnext == NULL) {
                prevNode->name_next = currNode->name_Lnext;
                delete currNode;
            }
            else if (currNode->name_Lnext == NULL && currNode->name_Rnext != NULL) {
                prevNode->name_next = currNode->name_Rnext;
                delete currNode;
            }
            else {
                delete currNode;
                prevNode->name_next = NULL;
            }
        }
        cout << "Delete_Name : " << name << endl;
        if (yearNode->name_next == NULL) {
            cout << "Delete_Name : " << yearNode->year << endl;
            prevyearNode->year_next = yearNode->year_next;
            delete yearNode;
        }
        if (majorNode->year_next == NULL) {
            cout << "Delete_Major : " << majorNode->major << endl;
            if (prevmajorNode == NULL) {
                head = majorNode->major_next;
            }
            else {
                prevmajorNode->major_next = majorNode->major_next;
            }
            delete majorNode;
        }


    }

    void Print_major(char* major) {
        Node* currNode = head;
        Node* yearNode = NULL;
        Node* nameNode = NULL;
        while (strcmp(major, currNode->major) != 0) {
            currNode = currNode->major_next;
        }
        Node* majorNode = currNode;
        yearNode = majorNode->year_next;
        while (yearNode != NULL) {
            nameNode = yearNode->name_next;
            print_info(majorNode, yearNode, nameNode);
            yearNode = yearNode->year_next;
        }
    }

    void Print_year(int year) {
        Node* majorNode = head;
        Node* yearNode = NULL;
        Node* nameNode = NULL;
        while (majorNode != NULL) {
            yearNode = majorNode->year_next;
            while (yearNode != NULL) {
                if (yearNode->year == year) {
                    nameNode = yearNode->name_next;
                    print_info(majorNode, yearNode, nameNode);
                }
                yearNode = yearNode->year_next;
            }

            majorNode = majorNode->major_next;
        }
    }

    void Print_Name(char* name) {
        Node* majorNode = head;
        Node* yearNode = NULL;
        Node* nameNode = NULL;
        while (majorNode != NULL) {
            yearNode = majorNode->year_next;
            while (yearNode != NULL) {
                nameNode = yearNode->name_next;
                int tmp = 0;
                while (nameNode != NULL) {
                    if (strcmp(nameNode->name, name) == 0) {
                        print_path_info(majorNode, yearNode, nameNode);
                        break;
                    }
                    else {
                        while (nameNode->name[tmp] != '\0' && name[tmp] != '\0') {
                            if (nameNode->name[tmp] == name[tmp]) {
                                tmp++;
                                continue;
                            }
                            else if (nameNode->name[tmp] < name[tmp]) {
                                nameNode = nameNode->name_Rnext;
                                tmp = 0;
                                break;
                            }
                            else {
                                nameNode = nameNode->name_Lnext;
                                tmp = 0;
                                break;
                            }
                        }
                    }

                }
                yearNode = yearNode->year_next;
            }
            majorNode = majorNode->major_next;
        }

    }

    void print_path_info(Node* Majornode, Node* Yearnode, Node* Namenode) {
        Node* currNode = head;
        while (1) {
            cout << currNode->major << " -> ";
            if (currNode == Majornode)
                break;
            currNode = currNode->major_next;
        }
        currNode = Majornode->year_next;
        while (1) {
            cout << currNode->year << " -> ";
            if (currNode == Yearnode)
                break;
            currNode = currNode->year_next;
        }
        currNode = Yearnode->name_next;
        while (1) {
            if (strcmp(currNode->name, Namenode->name) == 0) {
                cout << currNode->name << endl;
                break;
            }
            else {
                cout << currNode->name << " -> ";
                int tmp = 0;
                while (currNode->name[tmp] != '\0' && Namenode->name[tmp] != '\0') {
                    if (currNode->name[tmp] == Namenode->name[tmp]) {
                        tmp++;
                        continue;
                    }
                    else if (currNode->name[tmp] > Namenode->name[tmp]) {
                        currNode = currNode->name_Lnext;
                        tmp = 0;
                        break;
                    }
                    else {
                        currNode = currNode->name_Rnext;
                        tmp = 0;
                        break;
                    }
                }
            }
        }
    }

};


int main() {
    Manage manage;
    ifstream fin("Assignment3-3-4.txt");
    while (!fin.eof()) {
        char Major[50];
        fin >> Major;
        int Year;
        fin >> Year;
        char Name[50];
        fin >> Name;
        manage.insert_major(Major);
        manage.insert_year(Major, Year);
        manage.insert_name(Major, Year, Name);
    }
    fin.close();
    while (1) {
        cout
            << "Enter Any Command(1:Insert, 2:Delete, 3:Print_all, 4:Print_major, 5:Print_id, 6:Print_Name, 7:Exit): ";
        int command;
        cin >> command;
        if (command == 1) {
            char input_major[50];
            cin >> input_major;
            int input_year;
            cin >> input_year;
            char input_name[50];
            cin >> input_name;
            manage.insert_major(input_major, false);
            manage.insert_year(input_major, input_year, false);
            manage.insert_name(input_major, input_year, input_name, false);
        }
        else if (command == 2) {
            char input_major[50];
            cin >> input_major;
            int input_year;
            cin >> input_year;
            char input_name[50];
            cin >> input_name;
            manage.delete_node(input_major, input_year, input_name);
        }
        else if (command == 3) {
            manage.print_all();
        }
        else if (command == 4) {
            char input_major[50];
            cin >> input_major;
            manage.Print_major(input_major);
        }
        else if (command == 5) {
            int input_year;
            cin >> input_year;
            manage.Print_year(input_year);
        }
        else if (command == 6) {
            char input_name[50];
            cin >> input_name;
            manage.Print_Name(input_name);
        }
        else if (command == 7) {
            break;
        }
    }
    return 0;
}

//
// Created by 정성엽 on 2022/06/04.
//