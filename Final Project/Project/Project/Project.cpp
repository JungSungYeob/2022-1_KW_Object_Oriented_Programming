#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Node {

public:
    Node(int Z = NULL, int Y = NULL, int X = NULL, Node* U = NULL, Node* D = NULL, Node* L = NULL, Node* R = NULL) {
        x = X;
        y = Y;
        z = Z;
        up = U;
        down = D;
        left = L;
        right = R;
    }

    int x, y, z;
    char word[50];
    Node* up;
    Node* down;
    Node* left;
    Node* right;
    Node* front;
    Node* behind;
    Node* word_next;
    Node* upper_next;
    Node* lower_next;
};

class Manage {
private:
    Node* head0, * head1, * head2, * tmp1, * tmp2, * center;
    int cnt = 0;
public:
    Manage() { head0 = NULL, head1 = NULL, head2 = NULL, tmp1 = NULL, tmp2 = NULL, center = NULL; }

    ~Manage() {
        Node* currNode = head0;
        Node* wordNode = NULL;

        //BST delete
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 0) {
                    currNode = head0;
                }
                else if (i == 1) {
                    currNode = head1;
                }
                else if (i == 2) {
                    currNode = head2;
                }

                for (int m = 0; m < j; m++) {
                    currNode = currNode->down;
                }

                for (int k = 0; k < 3; k++) {
                    wordNode = currNode->word_next;
                    currNode->word_next = NULL;
                    freeBST(wordNode);
                    currNode = currNode->right;
                }
            }
        }
        //delete cube
        currNode = head0;
        freeCube(currNode);
    }

    void freeBST(Node*& BST) {
        if (BST != nullptr) {
            freeBST(BST->lower_next);
            freeBST(BST->upper_next);
            BST->upper_next = NULL;
            BST->lower_next = NULL;
            delete BST;
        }
    }

    void freeCube(Node*& block) {
        Node* a = NULL;
        Node* b = NULL;
        Node* c = NULL;
        if (block != NULL) {
            int x = cnt;
            cnt++;
            a = block->right;
            b = block->down;
            c = block->behind;
            freeCube(a);
            freeCube(b);
            freeCube(c);

            near_change(block, NULL);

            delete block;
        }
    }

    void create2() {
        head0 = new Node(0, 0, 0);
        Node* currNode0 = NULL;
        Node* prevNode0 = NULL;
        for (int k = 0; k < 3; k++) {
            currNode0 = head0;
            for (int l = 0; l < k; l++) {
                currNode0 = currNode0->behind;
            }
            if (k < 2) {
                currNode0->behind = new Node(0, k + 1, 0);
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 1; j < 3; j++) {
                    currNode0->right = new Node(i, k, j, prevNode0, NULL, currNode0);
                    currNode0 = currNode0->right;
                    if (prevNode0 != NULL) {
                        prevNode0->down = currNode0;
                        prevNode0 = prevNode0->right;
                    }
                }
                currNode0 = currNode0->left->left;
                prevNode0 = currNode0->right;
                if (i < 2) {
                    currNode0->down = new Node(i + 1, k, 0, currNode0);
                }
                currNode0 = currNode0->down;
            }
            prevNode0 = NULL;
        }

        for (int i = 0; i < 3; i++) {
            currNode0 = head0;
            Node* currNode1 = head0->behind;
            Node* currNode2 = head0->behind->behind;
            for (int j = 0; j < i; j++) {
                currNode0 = currNode0->down;
                currNode1 = currNode1->down;
                currNode2 = currNode2->down;
            }
            while (currNode0 != NULL && currNode1 != NULL && currNode2 != NULL) {
                currNode0->behind = currNode1;
                currNode1->front = currNode0;
                currNode1->behind = currNode2;
                currNode2->front = currNode1;
                currNode0 = currNode0->right;
                currNode1 = currNode1->right;
                currNode2 = currNode2->right;
            }
        }
        head1 = head0->behind;
        head2 = head1->behind;
    }

    void insert_BST(int z, int y, int x, char* word) {
        if (z < 0 || z > 2 || y < 0 || y > 2 || x < 0 || x > 2) {
            cout << "The value is not appropriate!" << endl;
            return;
        }


        Node* currNode = head0;
        for (int i = 0; i < z; i++) {
            currNode = currNode->down;
        }
        for (int i = 0; i < y; i++) {
            currNode = currNode->behind;
        }
        for (int i = 0; i < x; i++) {
            currNode = currNode->right;
        }

        if (currNode->word_next != NULL) {
            currNode = currNode->word_next;
            while (1) {
                int num;
                num = size_cmp(currNode->word, word);
                if (num == 1) {
                    if (currNode->upper_next != NULL) {
                        currNode = currNode->upper_next;
                        continue;
                    }
                    else {
                        currNode->upper_next = new Node();
                        currNode = currNode->upper_next;
                        strcpy_s(currNode->word, word);
                        break;
                    }
                }
                else if (num == -1) {
                    if (currNode->lower_next != NULL) {
                        currNode = currNode->lower_next;
                        continue;
                    }
                    else {
                        currNode->lower_next = new Node();
                        currNode = currNode->lower_next;
                        strcpy_s(currNode->word, word);
                        break;
                    }
                }
                else {
                    break;
                }


            }
        }
        else {
            currNode->word_next = new Node();
            currNode = currNode->word_next;
            strcpy_s(currNode->word, word);
        }

    }

    int size_cmp(char* Word1, char* Word2) {
        char word1[50], word2[50];
        strcpy_s(word1, Word1);
        strcpy_s(word2, Word2);
        int end = 0;
        while (word1[end] != NULL && word2[end] != NULL) {
            if (word1[end] >= 97)
                word1[end] -= 32;
            if (word2[end] >= 97)
                word2[end] -= 32;

            if (word1[end] < word2[end]) {
                return 1;
            }
            else if (word1[end] > word2[end]) {
                return -1;
            }
            else {
                end++;
                continue;
            }
        }
        return 0;
    }

    void Find(char* cmp_word) {
        Node* currNode = head0;
        Node* wordNode = NULL;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 0) {
                    currNode = head0;
                }
                else if (i == 1) {
                    currNode = head1;
                }
                else if (i == 2) {
                    currNode = head2;
                }

                for (int m = 0; m < j; m++) {
                    currNode = currNode->down;
                }

                for (int k = 0; k < 3; k++) {
                    wordNode = currNode->word_next;
                    int cmp = cmp_BST(wordNode, cmp_word);
                    if (cmp >= 1) {
                        cout << currNode->z << currNode->y << currNode->x << endl;
                    }
                    currNode = currNode->right;
                }
            }
        }
    }

    int cmp_BST(Node* tmp, char* Word) {
        int exist = 0;
        if (tmp != nullptr) {
            exist += cmp_BST(tmp->lower_next, Word);
            exist += cmp_BST(tmp->upper_next, Word);
            if (strcmp(tmp->word, Word) == 0) {
                exist++;
            }
        }
        return exist;
    }

    void Print(int z, int y, int x) {
        if (z < 0 || z > 2 || y < 0 || y > 2 || x < 0 || x > 2) {
            cout << "The value is not appropriate!" << endl;
            return;
        }
        Node* currNode = head0;
        for (int i = 0; i < z; i++) {
            currNode = currNode->down;
        }
        for (int i = 0; i < y; i++) {
            currNode = currNode->behind;
        }
        for (int i = 0; i < x; i++) {
            currNode = currNode->right;
        }
        currNode = currNode->word_next;
        cout << "Preorder :";
        Print_BST_pre(currNode);
        cout << "\nPostorder: ";
        Print_BST_post(currNode);
        cout << "\nInorder: ";
        Print_BST_in(currNode);
        cout << endl;
    }

    void Print_BST_pre(Node* tmp) {
        if (tmp != nullptr) {
            cout << tmp->word << " ";
            Print_BST_pre(tmp->lower_next);
            Print_BST_pre(tmp->upper_next);
        }
    }

    void Print_BST_post(Node* tmp) {
        if (tmp != nullptr) {
            Print_BST_post(tmp->lower_next);
            Print_BST_post(tmp->upper_next);
            cout << tmp->word << " ";
        }
    }

    void Print_BST_in(Node* tmp) {
        if (tmp != nullptr) {
            Print_BST_in(tmp->lower_next);
            cout << tmp->word << " ";
            Print_BST_in(tmp->upper_next);
        }
    }

    void Print_all() {
        Node* currNode = head0;
        Node* wordNode = NULL;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 0) {
                    currNode = head0;
                }
                else if (i == 1) {
                    currNode = head1;
                }
                else if (i == 2) {
                    currNode = head2;
                }

                for (int m = 0; m < j; m++) {
                    currNode = currNode->down;
                }

                for (int k = 0; k < 3; k++) {
                    wordNode = currNode->word_next;
                    int num = cnt_BST(wordNode);
                    cout << num << "\t";
                    currNode = currNode->right;
                }
                cout << endl;
            }
            cout << endl;
        }
    }

    int cnt_BST(Node* tmp) {
        int cnt = 0;
        if (tmp != nullptr) {
            cnt += cnt_BST(tmp->lower_next);
            cnt += cnt_BST(tmp->upper_next);
            cnt++;
        }
        return cnt;
    }

    void Delete_BST(int z, int y, int x, char* del_word) {
        if (z < 0 || z > 2 || y < 0 || y > 2 || x < 0 || x > 2) {
            cout << "The value is not appropriate!" << endl;
            return;
        }
        Node* currNode = head0;
        Node* prevNode = NULL;
        for (int i = 0; i < z; i++) {
            currNode = currNode->down;
        }
        for (int i = 0; i < y; i++) {
            currNode = currNode->behind;
        }
        for (int i = 0; i < x; i++) {
            currNode = currNode->right;
        }
        prevNode = currNode;
        currNode = currNode->word_next;
        bool exist = true;
        while (1) {
            int num = size_cmp(currNode->word, del_word);
            if (num == 1) {
                if (currNode->upper_next != NULL) {
                    prevNode = currNode;
                    currNode = currNode->upper_next;
                    continue;
                }
                else {
                    exist = false;
                    break;
                }
            }
            else if (num == -1) {
                if (currNode->lower_next != NULL) {
                    prevNode = currNode;
                    currNode = currNode->lower_next;
                    continue;
                }
                else {
                    exist = false;
                    break;
                }
            }
            else {
                break;
            }
        }

        if (exist == true) {
            if (currNode->upper_next != NULL && currNode->lower_next != NULL) {
                Node* tmp = currNode;
                prevNode = currNode;
                currNode = currNode->upper_next;
                while (currNode->lower_next != NULL) {
                    prevNode = currNode;
                    currNode = currNode->lower_next;
                }
                strcpy_s(tmp->word, currNode->word);
                if (currNode->upper_next != NULL) {
                    pre_curr(prevNode, currNode, currNode->upper_next);
                }
                else {
                    pre_curr(prevNode, currNode, NULL);
                }
            }
            else if (currNode->upper_next != NULL && currNode->lower_next == NULL) {
                pre_curr(prevNode, currNode, currNode->upper_next);
            }
            else if (currNode->upper_next == NULL && currNode->lower_next != NULL) {
                pre_curr(prevNode, currNode, currNode->lower_next);
            }
            else {
                pre_curr(prevNode, currNode, NULL);
            }
        }
        else {
            cout << "No matching words found!" << endl;
            return;
        }

    }

    void pre_curr(Node* pre, Node* curr, Node* des) {
        if (pre->word_next == curr) {
            pre->word_next = des;
            delete curr;
        }
        else if (pre->upper_next == curr) {
            pre->upper_next = des;
            delete curr;
        }
        else if (pre->lower_next == curr) {
            pre->lower_next = des;
            delete curr;
        }
        else
            return;
    }

    void Turn(int A, int B, int C) {
        if (A < 0 || A > 2 || B < 0 || B > 1 || C < 0 || C > 2) {
            cout << "The value is not appropriate!" << endl;
            return;
        }
        Node* currNode = head0;
        if (A == 0) {
            for (int i = 0; i < C; i++) {
                currNode = currNode->behind;
            }
            center = currNode->right->down;
            //대각선 바꾸기
            Exchange_turn(center->left->up, center->right->up);
            Exchange_turn(center->left->down, center->right->down);
            Exchange_turn(center->left, center->up);
            Exchange_turn(center->right, center->down);
            if (B == 0) { //시계방향
                Exchange_turn(center->left->up, center->right->down);
                Exchange_turn(center->left, center->right);
            }
            else if (B == 1) //반시계방향
            {
                Exchange_turn(center->right->up, center->left->down);
                Exchange_turn(center->up, center->down);
            }

        }
        else if (A == 1) {
            for (int i = 0; i < C; i++) {
                currNode = currNode->down;
            }
            center = currNode->right->behind;
            Exchange_turn(center->left->front, center->left->behind);
            Exchange_turn(center->right->front, center->right->behind);
            Exchange_turn(center->left, center->front);
            Exchange_turn(center->right, center->behind);
            if (B == 0) { //시계방향
                Exchange_turn(center->left->front, center->right->behind);
                Exchange_turn(center->front, center->behind);
            }
            else if (B == 1) //반시계방향
            {
                Exchange_turn(center->right->front, center->left->behind);
                Exchange_turn(center->left, center->right);
            }

        }
        else if (A == 2) {
            for (int i = 0; i < C; i++) {
                currNode = currNode->right;
            }
            center = currNode->down->behind;
            Exchange_turn(center->up->front, center->up->behind);
            Exchange_turn(center->down->front, center->down->behind);
            Exchange_turn(center->up, center->front);
            Exchange_turn(center->down, center->behind);
            if (B == 0) { //시계방향
                Exchange_turn(center->up->front, center->down->behind);
                Exchange_turn(center->front, center->behind);
            }
            else if (B == 1) //반시계방향
            {
                Exchange_turn(center->down->front, center->up->behind);
                Exchange_turn(center->up, center->down);
            }
        }
        Print_all();
        center = NULL;
    }

    void Exchange_turn(Node* ex1, Node* ex2) {
        tmp1 = new Node();
        tmp2 = new Node();
        save(tmp1, ex1);
        save(tmp2, ex2);
        save(ex1, tmp2);
        save(ex2, tmp1);
        near_change(tmp1, ex2);
        near_change(tmp2, ex1);
        if (ex1->z == 0 && ex1->y == 0 && ex1->x == 0) {
            head0 = ex1;
        }
        else if (ex2->z == 0 && ex2->y == 0 && ex2->x == 0) {
            head0 = ex2;
        }
        if (ex1->z == 0 && ex1->y == 1 && ex1->x == 0) {
            head1 = ex1;
        }
        else if (ex2->z == 0 && ex2->y == 1 && ex2->x == 0) {
            head1 = ex2;
        }
        if (ex1->z == 0 && ex1->y == 2 && ex1->x == 0) {
            head2 = ex1;
        }
        else if (ex2->z == 0 && ex2->y == 2 && ex2->x == 0) {
            head2 = ex2;
        }
    }


    void Exchange(int Z1, int Y1, int X1, int Z2, int Y2, int X2) {
        if (Z1 < 0 || Z1 > 2 || Y1 < 0 || Y1 > 2 || X1 < 0 || X1 > 2 || Z2 < 0 || Z2 > 2 || Y2 < 0 || Y2 > 2 ||
            X2 < 0 || X2 > 2) {
            cout << "The value is not appropriate!" << endl;
            return;
        }
        Node* ex1 = head0;
        Node* ex2 = head0;
        for (int i = 0; i < Z1; i++) {
            ex1 = ex1->down;
        }
        for (int i = 0; i < Y1; i++) {
            ex1 = ex1->behind;
        }
        for (int i = 0; i < X1; i++) {
            ex1 = ex1->right;
        }

        for (int i = 0; i < Z2; i++) {
            ex2 = ex2->down;
        }
        for (int i = 0; i < Y2; i++) {
            ex2 = ex2->behind;
        }
        for (int i = 0; i < X2; i++) {
            ex2 = ex2->right;
        }

        tmp1 = new Node(Z1, Y1, X1);
        tmp2 = new Node(Z2, Y2, X2);

        if (ex1->right == ex2) {
            ex1->right = NULL;
            ex2->left = NULL;
            save(tmp1, ex1);
            save(tmp2, ex2);
            save(ex1, tmp2);
            save(ex2, tmp1);
            near_change(tmp1, ex2);
            near_change(tmp2, ex1);
            ex2->right = ex1;
            ex1->left = ex2;
        }
        else if (ex1->left == ex2) {
            ex1->left = NULL;
            ex2->right = NULL;
            save(tmp1, ex1);
            save(tmp2, ex2);
            save(ex1, tmp2);
            save(ex2, tmp1);
            near_change(tmp1, ex2);
            near_change(tmp2, ex1);
            ex2->left = ex1;
            ex1->right = ex2;
        }
        else if (ex1->up == ex2) {
            ex1->up = NULL;
            ex2->down = NULL;
            save(tmp1, ex1);
            save(tmp2, ex2);
            save(ex1, tmp2);
            save(ex2, tmp1);
            near_change(tmp1, ex2);
            near_change(tmp2, ex1);
            ex2->up = ex1;
            ex1->down = ex2;
        }
        else if (ex1->down == ex2) {
            ex1->down = NULL;
            ex2->up = NULL;
            save(tmp1, ex1);
            save(tmp2, ex2);
            save(ex1, tmp2);
            save(ex2, tmp1);
            near_change(tmp1, ex2);
            near_change(tmp2, ex1);
            ex2->down = ex1;
            ex1->up = ex2;
        }
        else if (ex1->front == ex2) {
            ex1->front = NULL;
            ex2->behind = NULL;
            save(tmp1, ex1);
            save(tmp2, ex2);
            save(ex1, tmp2);
            save(ex2, tmp1);
            near_change(tmp1, ex2);
            near_change(tmp2, ex1);
            ex2->front = ex1;
            ex1->behind = ex2;
        }
        else if (ex1->behind == ex2) {
            ex1->behind = NULL;
            ex2->front = NULL;
            save(tmp1, ex1);
            save(tmp2, ex2);
            save(ex1, tmp2);
            save(ex2, tmp1);
            near_change(tmp1, ex2);
            near_change(tmp2, ex1);
            ex2->behind = ex1;
            ex1->front = ex2;
        }
        else {
            save(tmp1, ex1);
            save(tmp2, ex2);
            save(ex1, tmp2);
            save(ex2, tmp1);
            near_change(tmp1, ex2);
            near_change(tmp2, ex1);
        }
        if (Z1 == 0 && Y1 == 0 && X1 == 0) {
            head0 = ex2;
        }
        else if (Z2 == 0 && Y2 == 0 && X2 == 0) {
            head0 = ex1;
        }
        if (Z1 == 0 && Y1 == 1 && X1 == 0) {
            head1 = ex2;
        }
        else if (Z2 == 0 && Y2 == 1 && X2 == 0) {
            head1 = ex1;
        }
        if (Z1 == 0 && Y1 == 2 && X1 == 0) {
            head2 = ex2;
        }
        else if (Z2 == 0 && Y2 == 2 && X2 == 0) {
            head2 = ex1;
        }

        delete tmp1;
        delete tmp2;
    }

    void save(Node* a, Node* b) {
        a->up = b->up;
        a->down = b->down;
        a->left = b->left;
        a->right = b->right;
        a->front = b->front;
        a->behind = b->behind;
        a->z = b->z;
        a->y = b->y;
        a->x = b->x;
    }

    void near_change(Node* a, Node* b) {
        if (a->up != NULL) {
            a->up->down = b;
        }
        if (a->down != NULL) {
            a->down->up = b;
        }
        if (a->left != NULL) {
            a->left->right = b;
        }
        if (a->right != NULL) {
            a->right->left = b;
        }
        if (a->front != NULL) {
            a->front->behind = b;
        }
        if (a->behind != NULL) {
            a->behind->front = b;
        }
    }
};


int main() {
    Manage manage;
    manage.create2();
    ifstream fin("WordBook.txt");
    while (!fin.eof()) {
        int Z, Y, X;
        char Word[50];
        fin >> Z;
        fin >> Y;
        fin >> X;
        fin >> Word;
        manage.insert_BST(Z, Y, X, Word);
    }
    while (1) {
        cout << "Enter Any Command(1:Insert, 2:Delete, 3:Find, 4:Print, 5:Print_All, 6:Turn, 7:Exchange, 8:Exit : ";
        int command;
        cin >> command;
        if (command == 1) {
            int z, y, x;
            char word[50];
            cin >> z >> y >> x >> word;
            if (cin.fail())
                if (cin.fail()) {
                    cout << "Invalid Input!" << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                }
            manage.insert_BST(z, y, x, word);
        }
        else if (command == 2) {
            int z, y, x;
            char word[50];
            cin >> z >> y >> x >> word;
            if (cin.fail()) {
                cout << "Invalid Input!" << endl;
                cin.clear();
                cin.ignore(256, '\n');
            }
            manage.Delete_BST(z, y, x, word);
        }
        else if (command == 3) {
            char word[50];
            cin >> word;
            if (cin.fail()) {
                cout << "Invalid Input!" << endl;
                cin.clear();
                cin.ignore(256, '\n');
            }
            manage.Find(word);
        }
        else if (command == 4) {
            int z, y, x;
            cin >> z >> y >> x;
            if (cin.fail()) {
                cout << "Invalid Input!" << endl;
                cin.clear();
                cin.ignore(256, '\n');
            }
            manage.Print(z, y, x);
        }
        else if (command == 5) {
            manage.Print_all();
        }
        else if (command == 6) {
            int a, b, c;
            cin >> a >> b >> c;
            if (cin.fail()) {
                cout << "Invalid Input!" << endl;
                cin.clear();
                cin.ignore(256, '\n');
            }
            manage.Turn(a, b, c);
        }
        else if (command == 7) {
            int z1, z2, y1, y2, x1, x2;
            cin >> z1 >> y1 >> x1 >> z2 >> y2 >> x2;
            if (cin.fail()) {
                cout << "Invalid Input!" << endl;
                cin.clear();
                cin.ignore(256, '\n');
            }
            manage.Exchange(z1, y1, x1, z2, y2, x2);
        }
        else if (command == 8) {
            break;
        }
        else {
            cout << "Invalid Input!" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            continue;
        }

    }
    return 0;
}

//
// Created by 정성엽 on 2022/06/07.
//
