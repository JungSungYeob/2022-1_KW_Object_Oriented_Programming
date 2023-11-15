#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Node {
public:
    Node(char* Food, int Time) {
        strcpy_s(food, Food);
        time = Time;
    }

    Node* next, * prev;
    int time;
    int cnt = 1;
    char food[20];
};

class Jack {
private:
    Node* head;
public:
    Jack() { head = NULL; }

    void insert(char* name, int time) {
        if (head != NULL) {
            Node* currNode = head;
            while (1) {
                if (currNode->next != NULL) {
                    currNode = currNode->next;
                }
                else {
                    currNode->next = new Node(name, time);
                    break;
                }
            }
        }
        else {
            head = new Node(name, time);
        }
    }

    char* currPrint() {
        static char word[100];
        Node* currNode = head;
        if (currNode->cnt != currNode->time) {
            strcpy_s(word, "Cooking(");
            strcat_s(word, currNode->food);
            int tmp_num = currNode->time - currNode->cnt;
            char tmp1[2];
            sprintf_s(tmp1, "%d", tmp_num);
            strcat_s(word, tmp1);
            strcat_s(word, "/");
            char tmp2[2];
            sprintf_s(tmp2, "%d", currNode->time);
            strcat_s(word, tmp2);
            strcat_s(word, ")");
            currNode->cnt++;
        }
        else {
            strcpy_s(word, "Done!(");
            strcat_s(word, currNode->food);
            strcat_s(word, ")");
            head = currNode->next;
            delete currNode;
        }
        return word;
    }

    bool check_Done() {
        Node* currNode = head;
        if (currNode != NULL) {
            return false;
        }
        else {
            return true;
        }
    }
};

class Bob {
private:
    Node* head;
public:
    Bob() { head = NULL; }

    void insert(char* name, int time) {
        if (head != NULL) {
            Node* currNode = head;
            while (1) {
                if (currNode->next != NULL) {
                    currNode = currNode->next;
                }
                else {
                    currNode->next = new Node(name, time);
                    break;
                }
            }
        }
        else {
            head = new Node(name, time);
        }
    }

    char* currPrint() {
        static char word[100];
        Node* currNode = head;
        if (currNode->cnt != currNode->time) {
            strcpy_s(word, "Cooking(");
            strcat_s(word, currNode->food);
            int tmp_num = currNode->time - currNode->cnt;
            char tmp1[2];
            sprintf_s(tmp1, "%d", tmp_num);
            strcat_s(word, tmp1);
            strcat_s(word, "/");
            char tmp2[2];
            sprintf_s(tmp2, "%d", currNode->time);
            strcat_s(word, tmp2);
            strcat_s(word, ")");
            currNode->cnt++;
        }
        else {
            strcpy_s(word, "Done!(");
            strcat_s(word, currNode->food);
            strcat_s(word, ")");
            head = currNode->next;
            delete currNode;
        }
        return word;
    }

    bool check_Done() {
        Node* currNode = head;
        if (currNode != NULL) {
            return false;
        }
        else {
            return true;
        }
    }
};

class John {
private:
    Node* head;
public:
    John() { head = NULL; }

    void insert(char* name, int time) {
        if (head != NULL) {
            Node* currNode = head;
            while (1) {
                if (currNode->next != NULL) {
                    currNode = currNode->next;
                }
                else {
                    currNode->next = new Node(name, time);
                    break;
                }
            }
        }
        else {
            head = new Node(name, time);
        }
    }

    char* currPrint() {
        static char word[100];
        Node* currNode = head;
        if (currNode->cnt != currNode->time) {
            strcpy_s(word, "Cooking(");
            strcat_s(word, currNode->food);
            int tmp_num = currNode->time - currNode->cnt;
            char tmp1[2];
            sprintf_s(tmp1, "%d", tmp_num);
            strcat_s(word, tmp1);
            strcat_s(word, "/");
            char tmp2[2];
            sprintf_s(tmp2, "%d", currNode->time);
            strcat_s(word, tmp2);
            strcat_s(word, ")");
            currNode->cnt++;
        }
        else {
            strcpy_s(word, "Done!(");
            strcat_s(word, currNode->food);
            strcat_s(word, ")");
            head = currNode->next;
            delete currNode;
        }
        return word;
    }

    bool check_Done() {
        Node* currNode = head;
        if (currNode != NULL) {
            return false;
        }
        else {
            return true;
        }
    }
};


int main() {
    Jack jack;
    Bob bob;
    John john;
    ifstream fin1("Assignment3-3-3-1.txt");
    char chef[50][10];
    char food[50][20];
    int time[50];

    int end = 0;
    while (!fin1.eof()) {
        fin1 >> chef[end];
        fin1 >> food[end];
        fin1 >> time[end++];
    }
    fin1.close();
    ifstream fin2("Assignment3-3-3-2.txt");
    char order[50][20];
    int order_end = 0;
    while (!fin2.eof()) {
        fin2 >> order[order_end++];
    }
    fin2.close();
    for (int i = 0; i < order_end; i++) {
        cout << "New order : " << order[i] << endl;
        bool available_jack = false;
        int available_jack_num;
        bool available_bob = false;
        int available_bob_num;
        bool available_john = false;
        int available_john_num;
        for (int j = 0; j < end; j++) {
            if (strcmp(order[i], food[j]) == 0) {
                if (j >= 0 && j <= 6) {
                    available_jack = true;
                    available_jack_num = j;
                }
                else if (j >= 7 && j <= 12) {
                    available_bob = true;
                    available_bob_num = j;
                }
                else if (j >= 13 && j <= 21) {
                    available_john = true;
                    available_john_num = j;
                }
            }
        }
        cout << "Pick Cooker : ";
        char input_cooker[10];
        cin >> input_cooker;
        if (strcmp(input_cooker, "Jack") == 0) {
            if (available_jack == true) {
                jack.insert(order[i], time[available_jack_num]);
            }
            else {
                i--;
                continue;
            }
        }
        else if (strcmp(input_cooker, "Bob") == 0) {
            if (available_bob == true) {
                bob.insert(order[i], time[available_bob_num]);
            }
            else {
                i--;
                continue;
            }
        }
        else if (strcmp(input_cooker, "John") == 0) {
            if (available_john == true) {
                john.insert(order[i], time[available_john_num]);
            }
            else {
                i--;
                continue;
            }
        }
    }
    cout << std::left << setw(18) << " " << setw(22) << "Jack" << setw(18) << " " << setw(22) << "John" << setw(18)
        << " " << setw(22) << "Bob" << endl;
    bool Jack_done = false;
    bool John_done = false;
    bool Bob_done = false;
    int cnt = 0;
    while (Jack_done == false || John_done == false || Bob_done == false) {
        if (Jack_done == false) {
            char* name = jack.currPrint();
            int num = (40 - strlen(name)) / 2;
            cout << std::left << setw(num) << " " << setw(40 - num) << name;
        }
        if (John_done == false) {
            char* name = john.currPrint();
            int num = (40 - strlen(name)) / 2;
            cout << std::left << setw(num) << " " << setw(40 - num) << name;
        }
        if (Bob_done == false) {
            char* name = bob.currPrint();
            int num = (40 - strlen(name)) / 2;
            cout << std::left << setw(num) << " " << setw(40 - num) << name;
        }
        cout << endl;
        if (jack.check_Done() == true)
            Jack_done = true;
        if (john.check_Done() == true)
            John_done = true;
        if (bob.check_Done() == true)
            Bob_done = true;
        cnt++;
    }
    cout << "\nTotal Time is :" << cnt;

    return 0;
}

//
// Created by Á¤¼º¿± on 2022/06/02.
//
