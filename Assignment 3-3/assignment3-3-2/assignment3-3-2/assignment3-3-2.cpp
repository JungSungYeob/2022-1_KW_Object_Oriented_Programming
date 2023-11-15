#include <iostream>
#include <fstream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Node {
public:
    Node(char* Name, Node* Next, Node* Prev) {
        strcpy_s(name, Name);
        next = Next;
        prev = Prev;
    }

    Node* next, * prev;
    char name[30];
};

class Line1 {
private:
    Node* head, * tail;
public:
    Line1() { head = NULL, tail = NULL; }

    ~Line1() {
        freeNode(head);
    }

    void freeNode(Node*& currNode) {
        if (currNode != nullptr) {
            freeNode(currNode->next);
            delete currNode;
        }
    }

    void insert(char* name) {
        //처음이 아닌 경우
        if (head != NULL) {
            Node* currNode = head;
            while (1) {
                if (currNode->next != NULL) {
                    currNode = currNode->next;
                }
                else {
                    currNode->next = new Node(name, NULL, currNode);
                    tail = currNode->next;
                    break;
                }
            }
        }
        //처음인 경우
        else {
            head = new Node(name, NULL, NULL);
            tail = head;
        }
    }

    int find(char* name) {
        Node* currNode = head;
        while (currNode != NULL) {
            if (strcmp(currNode->name, name) == 0) {
                return 1;
            }
            else {
                currNode = currNode->next;
            }
        }
        return 0;
    }

    void path(char* arr, char* des, int x = 0) {
        Node* currNode1 = head;
        int num1 = 1;
        while (strcmp(currNode1->name, arr) != 0) {
            currNode1 = currNode1->next;
            num1++;
        }
        Node* currNode2 = head;
        int num2 = 1;
        while (strcmp(currNode2->name, des) != 0) {
            currNode2 = currNode2->next;
            num2++;
        }
        if (num1 < num2) {
            if (x == 1) {
                currNode1 = currNode1->next;
            }
            while (currNode1 != currNode2) {
                cout << currNode1->name << "->";
                currNode1 = currNode1->next;
            }
            cout << currNode2->name;
        }
        else {
            if (x == 1) {
                currNode1 = currNode1->prev;
            }
            while (currNode1 != currNode2) {
                cout << currNode1->name << "->";
                currNode1 = currNode1->prev;
            }
            cout << currNode2->name;
        }
    }

};

class Line2 {
private:
    Node* head, * tail;
    int size = 0;
public:
    Line2() { head = NULL, tail = NULL; }

    ~Line2() {
        Node* currNode = head, * nextNode = NULL;
        while (nextNode != head)
        {
            nextNode = currNode->next;
            delete currNode;
            currNode = nextNode;
        }
    }

    void insert(char* name) {
        //처음이 아닌 경우
        if (head != NULL) {
            Node* currNode = head;
            while (1) {
                if (currNode != tail) //tail 일 때까지
                {
                    currNode = currNode->next;
                }
                else {
                    currNode->next = new Node(name, head, currNode);
                    currNode = currNode->next;
                    head->prev = currNode;
                    tail = currNode;
                    size++;
                    break;
                }
            }
        }
        //처음인 경우
        else {
            head = new Node(name, NULL, NULL);
            tail = head;
            size++;
        }
    }

    void path(char* arr, char* des, int x = 0) {
        Node* currNode1 = head;
        int num1 = 1;
        while (strcmp(currNode1->name, arr) != 0) {
            currNode1 = currNode1->next;
            num1++;
        }
        Node* currNode2 = head;
        int num2 = 1;
        while (strcmp(currNode2->name, des) != 0) {
            currNode2 = currNode2->next;
            num2++;
        }

        if (num1 < num2) {
            if (num2 - num1 < size - num2 + num1) {
                if (x == 1) {
                    currNode1 = currNode1->next;
                }
                while (currNode1 != currNode2) {
                    cout << currNode1->name << "->";
                    currNode1 = currNode1->next;
                }
                cout << currNode2->name;
            }
            else {
                if (x == 1) {
                    currNode1 = currNode1->prev;
                }
                while (currNode1 != currNode2) {
                    cout << currNode1->name << "->";
                    currNode1 = currNode1->prev;
                }
                cout << currNode2->name;
            }
        }
        else {
            if (num1 - num2 < size - num1 + num2) {
                if (x == 1) {
                    currNode1 = currNode1->prev;
                }
                while (currNode1 != currNode2) {
                    cout << currNode1->name << "->";
                    currNode1 = currNode1->prev;
                }
                cout << currNode2->name;
            }
            else {
                if (x == 1) {
                    currNode1 = currNode1->next;
                }
                while (currNode1 != currNode2) {
                    cout << currNode1->name << "->";
                    currNode1 = currNode1->next;
                }
                cout << currNode2->name;
            }
        }
    }

};


int main() {
    Line1 line1;
    Line2 line2;
    ifstream fin1("Assignment3-3-2-1.txt");
    char word1[1000][30];
    int end = 0;
    while (!fin1.eof()) {
        fin1 >> word1[end++];
    }
    for (int i = 0; i < end; i++) {
        line1.insert(word1[i]);
    }
    fin1.close();
    ifstream fin2("Assignment3-3-2-2.txt");
    char word2[1000][30];
    end = 0;
    while (!fin2.eof()) {
        fin2 >> word2[end++];
    }
    for (int i = 0; i < end; i++) {
        line2.insert(word2[i]);
    }
    fin2.close();


    cout << "출발역 : ";
    char arr[30];
    cin >> arr;
    int arr_num;
    if (line1.find(arr) != 0) {
        arr_num = 1;
    }
    else {
        arr_num = 2;
    } // 1호선 아님 2호선
    cout << "도착역 : ";
    char des[30];
    cin >> des;
    int des_num;
    if (line1.find(des) != 0) {
        des_num = 1;
    }
    else {
        des_num = 2;
    }
    if (arr_num == des_num) {
        if (arr_num == 1) {
            line1.path(arr, des);
        }
        else {
            line2.path(arr, des);
        }
    }
    else {
        char cityhall[10];
        strcpy_s(cityhall, "시청");
        if (arr_num == 1) {
            line1.path(arr, cityhall);
            cout << "->";
            line2.path(cityhall, des, 1);
        }
        else {
            line2.path(arr, cityhall);
            cout << "->";
            line1.path(cityhall, des, 1);
        }
    }

    return 0;

}
//
// Created by 정성엽 on 2022/06/02.
//
