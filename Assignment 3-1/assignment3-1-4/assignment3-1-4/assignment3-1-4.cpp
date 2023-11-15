#include <iostream>
#include <cstring>

using namespace std;

class Node {
    friend class Doubly_linked_list;

private:
    int ID;
    char NAME[20];
    Node* next, * prev;

public:
    Node(Node* n, Node* p, int id, char* name) {
        next = n;
        prev = p;
        ID = id;
        strcpy_s(NAME, name);
    }
};

class Doubly_linked_list {
private:
    int index = 0;
    Node* head, * tail;
public:
    Doubly_linked_list() { head = NULL, tail = NULL; };

    void insert(int id, char* name);

    void print();

    void print_reverse();

    void sort_name();

    void sort_id();

    void delete_node(int id);
    ~Doubly_linked_list()
    {
        Node* currNode = head, * nextNode = NULL;
        while (currNode != NULL)
        {
            nextNode = currNode->next;
            delete currNode;
            currNode = nextNode;
        }
    }
};

void Doubly_linked_list::insert(int id, char* name) {
    if (head == NULL) {
        head = new Node(NULL, head, id, name);
        tail = head;
        index++;
    }
    else {
        Node* currNode = head;
        while (currNode != NULL) {
            if (currNode->ID == id)
                return;
            currNode = currNode->next;
        }
        currNode = head;
        Node* prevNode = head;
        for (int i = 0; i <= index; i++) {
            if (currNode->ID > id) {
                if (currNode != head) {
                    currNode->prev = new Node(currNode, currNode->prev, id, name);
                    prevNode->next = currNode->prev;
                    while (currNode != NULL) {
                        tail = currNode;
                        currNode = currNode->next;
                    }
                    index++;
                    break;
                }
                else {
                    head = new Node(currNode, NULL, id, name);
                    currNode->prev = head;
                    while (currNode != NULL) {
                        tail = currNode;
                        currNode = currNode->next;
                    }
                    index++;
                    break;
                }
            }
            else if (currNode->ID < id && currNode->next == NULL) {
                tail->next = new Node(NULL, tail, id, name);
                tail = tail->next;
                index++;
                break;
            }
            prevNode = currNode;
            currNode = currNode->next;
        }
    }
}

void Doubly_linked_list::print() {
    Node* currNode = head;
    while (currNode != NULL) {
        cout << currNode->ID << " " << currNode->NAME << endl;
        currNode = currNode->next;
    }
}

void Doubly_linked_list::print_reverse() {
    Node* currNode = tail;
    while (currNode != NULL) {
        cout << currNode->ID << " " << currNode->NAME << endl;
        currNode = currNode->prev;
    }
}

void Doubly_linked_list::sort_name() {
    Node* currNode = head;
    while (currNode->next != NULL)
    {
        Node* nextNode = currNode->next;
        while (nextNode != NULL) {
            char* tmp1 = currNode->NAME;
            char* tmp2 = nextNode->NAME;
            int seq = 0;
        retry:
            if (tmp1[seq] > tmp2[seq]) {
                int tmp_num;
                tmp_num = currNode->ID;
                currNode->ID = nextNode->ID;
                nextNode->ID = tmp_num;
                char tmp_name[20];
                strcpy_s(tmp_name, currNode->NAME);
                strcpy_s(currNode->NAME, nextNode->NAME);
                strcpy_s(nextNode->NAME, tmp_name);
            }
            else if (tmp1[seq] == tmp2[seq]) {
                seq++;
                goto retry;
            }
            nextNode = nextNode->next;
        }
        currNode = currNode->next;
    }
}

void Doubly_linked_list::sort_id() {
    Node* currNode = head;
    while (currNode->next != NULL)
    {
        Node* nextNode = currNode->next;
        while (nextNode != NULL) {
            int tmp1 = currNode->ID;
            int tmp2 = nextNode->ID;
            if (tmp1 > tmp2) {
                int tmp_num;
                tmp_num = currNode->ID;
                currNode->ID = nextNode->ID;
                nextNode->ID = tmp_num;
                char tmp_name[20];
                strcpy_s(tmp_name, currNode->NAME);
                strcpy_s(currNode->NAME, nextNode->NAME);
                strcpy_s(nextNode->NAME, tmp_name);
            }
            nextNode = nextNode->next;
        }
        currNode = currNode->next;
    }
}

void Doubly_linked_list::delete_node(int id) {
    Node* prevNode = NULL;
    Node* currNode = head;
    Node* nextNode = currNode->next;
    while (currNode != NULL)
    {
        if (currNode->ID == id)
        {
            if (currNode == head)
            {
                head = head->next;
                if (head != NULL)
                {
                    head->prev = NULL;
                }
                delete currNode;
                index--;
                break;
            }
            else if (currNode == tail)
            {
                prevNode->next = NULL;
                tail = prevNode;
                delete currNode;
                index--;
                break;
            }
            else
            {
                prevNode->next = currNode->next;
                currNode->next->prev = prevNode;
                delete currNode;
                index--;
                break;
            }
        }
        prevNode = currNode;
        currNode = currNode->next;
        nextNode = currNode->next;
    }
    Node* cntNode=head;
    while (cntNode != NULL)
    {
        tail = cntNode;
        cntNode = cntNode->next;
    }
    return;
}

int main() {
    Doubly_linked_list A;
    while (1) {
        cout
            << "Please Enter command(1: insert, 2: print, 3: print_reverse, 4: sort_by_name, 5: sort_by_ID, 6: delete, 7: exit) :";
        int command;
        cin >> command;
        if (command == 1) {
            int num;
            cin >> num;
            char name[20];
            cin >> name;
            A.insert(num, name);
        }
        else if (command == 2) {
            A.print();
        }
        else if (command == 3) {
            A.print_reverse();
        }
        else if (command == 4) {
            A.sort_name();
        }
        else if (command == 5) {
            A.sort_id();
        }
        else if (command == 6) {
            int num;
            cin >> num;
            A.delete_node(num);
        }
        else if (command == 7) {
            break;
        }
        else
            continue;
    }
    return 0;
}
//
// Created by Á¤¼º¿± on 2022/05/18.
//
