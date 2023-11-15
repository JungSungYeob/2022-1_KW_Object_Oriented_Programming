#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Alpha_Node {
private:
    Alpha_Node* next;
    Alpha_Node* w_next;
    Alpha_Node* head;
    char word[30];
    char Alpha;
public:
    void create_Alpha() {
        head = new Alpha_Node();
        head->Alpha = 'A';
        Alpha_Node* currNode = head;
        for (int i = 1; i < 26; i++) {
            currNode->next = new Alpha_Node();
            currNode = currNode->next;
            currNode->Alpha = 65 + i;
        }
    }

    void insert_Word(char* word) {
        Alpha_Node* currNode = head;
        while (currNode != NULL) {
            if (currNode->Alpha == word[0] || currNode->Alpha == word[0] - 32) {
                if (currNode->w_next != NULL) {
                    while (currNode->w_next != NULL) {
                        currNode = currNode->w_next;
                    }
                    currNode->w_next = new Alpha_Node();
                    currNode = currNode->w_next;
                    strcpy_s(currNode->word, word);
                    break;
                }
                else {
                    currNode->w_next = new Alpha_Node();
                    currNode = currNode->w_next;
                    strcpy_s(currNode->word, word);
                    break;
                }
            }
            else
                currNode = currNode->next;
        }
    }

    void print() {
        Alpha_Node* currNode = head;
        Alpha_Node* alphaNode = head;
        while (alphaNode != NULL) {
            currNode = alphaNode->w_next;
            if (currNode == NULL)
            {
                alphaNode = alphaNode->next;
                continue;
            }
            cout << alphaNode->Alpha;
            while (currNode != NULL)
            {
                cout << " -> " << currNode->word;
                currNode = currNode->w_next;
            }
            cout << endl;
            alphaNode = alphaNode->next;
        }
    }
    ~Alpha_Node()
    {
        Alpha_Node* currNode = head, * alphaNode = head, * nextNode = NULL;
        while (alphaNode != NULL)
        {
            currNode = alphaNode->w_next;
            while (currNode != NULL)
            {
                nextNode = currNode->next;
                delete currNode;
                currNode = nextNode;
            }
            nextNode = alphaNode->next;
            delete alphaNode;
            alphaNode = nextNode;
        }
    }
};



int main() {
    Alpha_Node Alpha;
    Alpha.create_Alpha();
    ifstream fin("Assignment.txt");
    char word[1000][30] = { '\0', };
    char tmpword[1000][30] = { '\0', };
    int end = 0;
    while (!fin.eof()) {
        fin >> word[end++];
    }
    fin.close();
    int cnt = 0;
    while (word[cnt][0] != '\0') {
        strcpy_s(tmpword[cnt], word[cnt]);
        for (int j = 0; j < 30; j++) {
            if (tmpword[cnt][j] >= 97)
                tmpword[cnt][j] -= 32;
        }
        cnt++;
    }
    for (int i = 0; i < cnt; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            int k = 0;
        retry:
            if (tmpword[i][k] > tmpword[j][k]) {
                char tmp[30];
                strcpy_s(tmp, tmpword[i]);
                strcpy_s(tmpword[i], tmpword[j]);
                strcpy_s(tmpword[j], tmp);
                strcpy_s(tmp, word[i]);
                strcpy_s(word[i], word[j]);
                strcpy_s(word[j], tmp);
            }
            else if (tmpword[i][k] == tmpword[j][k])
            {
                k++;
                goto retry;
            }
        }
    }
    for (int i = 0; i < cnt; i++) {
        Alpha.insert_Word(word[i]);
    }
    Alpha.print();
    return 0;
}
//
// Created by Á¤¼º¿± on 2022/05/24.
//
