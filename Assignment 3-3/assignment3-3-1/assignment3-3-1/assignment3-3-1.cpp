#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Node {
public:
    Node(int n) {
        num = n;
    }

    int num;
    Node* lower_next;
    Node* upper_next;
};

class Tree {
private:
    Node* root, * leaf;
public:
    Tree() { root = NULL; }

    void insert(int num) {
        //처음이 아닌 경우
        if (root != NULL) {
            Node* currNode = root;
            while (1) {
                if (currNode->lower_next != NULL || currNode->upper_next != NULL) {
                    if (currNode->num == num)
                        break;
                    else if (currNode->num < num)
                        if (currNode->upper_next == NULL) {
                            currNode->upper_next = new Node(num);
                        }
                        else
                            currNode = currNode->upper_next;
                    else {
                        if (currNode->lower_next == NULL) {
                            currNode->lower_next = new Node(num);
                        }
                        else
                            currNode = currNode->lower_next;
                    }
                }
                else {
                    if (currNode->num == num)
                        break;
                    else if (currNode->num < num)
                        currNode->upper_next = new Node(num);
                    else
                        currNode->lower_next = new Node(num);
                    break;
                }
            }
            //처음인 경우
        }
        else {
            root = new Node(num);
        }
    }

    void delete_node(int num) {
        Node* currNode = root;
        Node* prevNode = NULL;
        while (1) {
            if (currNode->num > num) {
                prevNode = currNode;
                currNode = currNode->lower_next;
            }
            else if (currNode->num < num) {
                prevNode = currNode;
                currNode = currNode->upper_next;
            }
            else {
                if (currNode != root) {
                    if (currNode->upper_next != NULL && currNode->lower_next != NULL) {
                        Node* tmpNode = currNode;
                        prevNode = currNode;
                        currNode = currNode->upper_next;
                        while (currNode->lower_next != NULL) {
                            prevNode = currNode;
                            currNode = currNode->lower_next;
                        }
                        tmpNode->num = currNode->num;
                        if (currNode->upper_next != NULL) {
                            if (currNode->upper_next->num < prevNode->num) {
                                prevNode->lower_next = currNode->upper_next;
                            }
                            else {
                                prevNode->upper_next = currNode->upper_next;
                            }
                        }
                        else {
                            if (currNode->num < prevNode->num) {
                                prevNode->lower_next = NULL;
                            }
                            else {
                                prevNode->upper_next = NULL;
                            }
                        }
                        delete currNode;
                    }
                    else if (currNode->upper_next != NULL && currNode->lower_next == NULL) {
                        if (currNode->upper_next->num < prevNode->num) {
                            prevNode->lower_next = currNode->upper_next;
                        }
                        else {
                            prevNode->upper_next = currNode->upper_next;
                        }
                        delete currNode;
                    }
                    else if (currNode->upper_next == NULL && currNode->lower_next != NULL) {
                        if (currNode->lower_next->num < prevNode->num) {
                            prevNode->lower_next = currNode->lower_next;
                        }
                        else {
                            prevNode->upper_next = currNode->lower_next;
                        }
                        delete currNode;
                    }
                    else if (currNode->upper_next == NULL && currNode->lower_next == NULL) {
                        if (currNode->num < prevNode->num) {
                            prevNode->lower_next = NULL;
                        }
                        else {
                            prevNode->upper_next = NULL;
                        }
                        delete currNode;
                    }
                }
                else {
                    if (currNode->upper_next != NULL && currNode->lower_next != NULL) {
                        Node* tmpNode = currNode;
                        prevNode = currNode;
                        currNode = currNode->upper_next;
                        while (currNode->lower_next != NULL) {
                            prevNode = currNode;
                            currNode = currNode->lower_next;
                        }
                        tmpNode->num = currNode->num;
                        if (currNode->upper_next != NULL) {
                            if (currNode->upper_next->num < prevNode->num) {
                                prevNode->lower_next = currNode->upper_next;
                            }
                            else {
                                prevNode->upper_next = currNode->upper_next;
                            }
                        }
                        else {
                            if (currNode->num < prevNode->num) {
                                prevNode->lower_next = NULL;
                            }
                            else {
                                prevNode->upper_next = NULL;
                            }
                        }
                        delete currNode;
                    }
                    else if (currNode->upper_next != NULL && currNode->lower_next == NULL) {
                        root = currNode->upper_next;
                        delete currNode;
                    }
                    else if (currNode->upper_next == NULL && currNode->lower_next != NULL) {
                        root = currNode->lower_next;
                        delete currNode;
                    }
                    else if (currNode->upper_next == NULL && currNode->lower_next == NULL) {
                        root = NULL;
                        delete currNode;
                    }
                }
                break;
            }
        }
    }

    void print_path(int num) {
        Node* currNode = root;
        while (1) {
            if (currNode->num == num) {
                cout << currNode->num << endl;
                break;
            }
            else if (currNode->num < num) {
                cout << currNode->num << "->";
                currNode = currNode->upper_next;
            }
            else {
                cout << currNode->num << "->";
                currNode = currNode->lower_next;
            }
        }
    }

    ~Tree() {
        freeNode(root);
    }

    void freeNode(Node*& currNode) {
        if (currNode != nullptr) {
            freeNode(currNode->upper_next);
            freeNode(currNode->lower_next);
            delete currNode;
        }
    }

};

int main() {
    Tree tree;
    while (1) {
        cout << "Enter Any Command(1:Insert, 2:Delete, 3:Find, 4:Exit): ";
        int command;
        cin >> command;
        if (command == 1) {
            int input_num;
            cin >> input_num;
            tree.insert(input_num);
        }
        else if (command == 2) {
            int delete_num;
            cin >> delete_num;
            tree.delete_node(delete_num);
        }
        else if (command == 3) {
            int find_num;
            cin >> find_num;
            tree.print_path(find_num);
        }
        else if (command == 4)
            break;
    }
}


//
// Created by 정성엽 on 2022/06/01.
//
