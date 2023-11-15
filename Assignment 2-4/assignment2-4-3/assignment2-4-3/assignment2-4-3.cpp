#include <iostream>
#include <cstring>
using namespace std;

class Node {
public:
    Node* next;
    int num;
};

class Link {
private:
    int cnt = 0;
public:
    Node* head = new Node();

    void insert(int x);
    void find(int x);
    int deleteNode(int x);
    void print_all();
    ~Link()
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
void Link::insert(int x) {
    if (cnt == 0)
    {
        head->num = x;
        head->next = nullptr;
    }
    else
    {
        Node* currNode = new Node();

        currNode->num = x;
        currNode->next = nullptr;

        Node* tmpNode = head;

        while (tmpNode->next != nullptr) {
            tmpNode = tmpNode->next;
        }

        tmpNode->next = currNode;
    }
    cnt++;
}
void Link::print_all() {
    Node* currNode = head;
    for (int i = 0; i < cnt; i++)
    {
        cout << currNode->num << endl;
        currNode = currNode->next;
    }
    cout << "Number of nodes in the list: " << cnt <<endl;
}

void Link::find(int x) {
    Node* currNode = head;
    for (int i = 1; i <= cnt; i++) {
        if (currNode->num == x) {
            cout << "Found Index: " << i << endl;
        }
        currNode = currNode->next;
    }
}

int Link::deleteNode(int x) {
    Node* prevNode = NULL;
    Node* currNode = head;
    for (int i = 1; i <= cnt; i++) {
        if (currNode->num == x) {
            if (i == 1)
            {
                head = currNode->next;
                delete currNode;
                cnt--;
                return 1;
            }
            else {
                prevNode->next = currNode->next;
                delete currNode;
                cnt--;
                return 1;
            }
        }
        else
            prevNode = currNode;
        currNode = currNode->next;
    }
    return 0;
}



int main() {
    class Link List;
    while (1) {
        cout << "Please Enter Command(1:insert, 2:find, 3:delete, 4:print, 5:quit : ";
        char command[10];
        cin >> command;
        if (strcmp(command, "insert") == 0) {
            int num;
            cin >> num;
            List.insert(num);
        }
        else if (strcmp(command, "find") == 0) {
            int num;
            cin >> num;
            List.find(num);
        }
        else if (strcmp(command, "delete") == 0) {
            int num;
            cin >> num;
            while (true) {
                if (List.deleteNode(num) != 0)
                    continue;
                else
                    break;
            }
        }
        else if (strcmp(command, "print") == 0) {
            List.print_all();
        }
        else if (strcmp(command, "quit") == 0) {
            break;
        }
        else
            continue;
    }
    return 0;
}

//
// Created by Á¤¼º¿± on 2022/05/11.
//
