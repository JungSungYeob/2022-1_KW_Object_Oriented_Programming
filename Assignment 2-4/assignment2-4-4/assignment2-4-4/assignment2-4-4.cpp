#include <iostream>
#include <cstring>
using namespace std;

class node {
public:
    char word[10];
    node* next;
};

class seq {
private:
    node* head, * tail;
public:
    seq() { head == NULL, tail == NULL; }
    void insert(char* word);
    bool exist_check(char* word);
    void print_all();
    ~seq()
    {
        if (head != NULL)
        {
            node* tmpNode1 = head, * tmpNode2;
            while (tmpNode1 != NULL)
            {
                tmpNode2 = tmpNode1->next;
                delete tmpNode1;
                tmpNode1 = tmpNode2;
            }
            head = tail = NULL;
        }
    }
};

void seq::insert(char* word) {
    if (NULL != head)
    {
        tail->next = new node;
        tail = tail->next;
    }
    else
    {
        head = new node;
        tail = head;
    }
    strcpy_s(tail->word, word);
    tail->next = NULL;
}
bool seq::exist_check(char* word) {
    node* currNode = head;
    while (currNode != NULL)
    {
        if (_stricmp(currNode->word, word) != 0)
        {
            currNode = currNode->next;
        }
        else
        {
            cout << "Already Exists" << endl;
            while (currNode != NULL)
            {
                currNode = currNode->next;
            }
            return true;
        }
    }
    return false;
}

void seq::print_all()
{
    node* currNode = head;
    while (currNode != NULL)
    {
        cout << currNode->word << "-> ";
        currNode = currNode->next;
    }
    cout << endl;
}

int main()
{
    class seq Seq;
    int cnt = 0;
    char re_word[20];
    bool exist_check_num = false;
    while (1)
    {
        cout << "CMD(Word/exit)>> ";
        char word[20];
        cin >> word;
        if (strcmp(word, "exit") != 0)
        {
            exist_check_num = Seq.exist_check(word);
            if (word[0] == re_word[strlen(re_word) - 1] || word[0] == re_word[strlen(re_word) - 1] + 32 || word[0] == re_word[strlen(re_word) - 1] - 32 || cnt == 0)
            {
                if (exist_check_num == true)
                    Seq.print_all();
                else
                {
                    Seq.insert(word);
                    Seq.print_all();
                    strcpy_s(re_word, word);
                }
            }
            else
            {
                cout << "Not chained" << endl;
                Seq.print_all();
            }
            cnt++;
        }
        else
            break;
    }
    return 0;
}


//
// Created by Á¤¼º¿± on 2022/05/11.
//
