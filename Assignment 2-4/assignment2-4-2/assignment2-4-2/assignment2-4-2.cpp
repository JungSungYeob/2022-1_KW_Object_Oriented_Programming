#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
    char name[20];
    int Score;
public:
    char* rt_name() { return name; }

    void set_name(char* Name) { strcpy_s(name, Name); }

    int rt_Score() { return Score; }

    void set_Score(int num) { Score = num; }
};

class Manage {
private:
    class Student* list[100];

    int size = 0;
public:
    void Insert_student(char* name, int score);

    void sort_by_name();

    void sort_by_score();

    ~Manage() {
        for (int i = 0; i < size; i++) {
            delete[]list[i];
        }
    }
};

void Manage::Insert_student(char* name, int score) {
    list[size] = new Student;
    list[size]->set_name(name);
    list[size]->set_Score(score);
    size++;
}

void Manage::sort_by_name() {

    //sort by name
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            char* tmp_name1 = list[i]->rt_name();
            char* tmp_name2 = list[j]->rt_name();
            int seq = 0;
        retry:
            if (tmp_name1[seq] > tmp_name2[seq]) {
                int tmp_num = list[i]->rt_Score();
                list[i]->set_Score(list[j]->rt_Score());
                list[j]->set_Score(tmp_num);

                char* tmp_name = list[i]->rt_name();
                char tmp[20];
                for (int l = 0; l < 20; l++) {
                    tmp[l] = tmp_name[l];
                }
                list[i]->set_name(list[j]->rt_name());
                list[j]->set_name(tmp);
            }
            else if (tmp_name1[seq] == tmp_name2[seq]) {
                seq++;
                goto retry;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout << list[i]->rt_name() << " " << list[i]->rt_Score() << endl;
    }
}

void Manage::sort_by_score() {

    //sort by score
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list[i]->rt_Score() >= list[j]->rt_Score()) {
                int tmp_num = list[i]->rt_Score();
                list[i]->set_Score(list[j]->rt_Score());
                list[j]->set_Score(tmp_num);

                char* tmp_name = list[i]->rt_name();
                char tmp[20];
                for (int l = 0; l < 20; l++) {
                    tmp[l] = tmp_name[l];
                }
                list[i]->set_name(list[j]->rt_name());
                list[j]->set_name(tmp);
            }
        }
    }
    for (int i = 0; i < size; i++) {
        cout << list[i]->rt_name() << " " << list[i]->rt_Score() << endl;
    }

}

int main() {
    class Manage A;
    while (1) {
        cout << "Please Enter Command(1:insert, 2:sort by name, 3:sort by score, 4:quit :";
        int command;
        cin >> command;
        if (command == 1) {
            cout << "Name :";
            char name[10];
            cin >> name;
            cout << "Score :";
            int score;
            cin >> score;
            A.Insert_student(name, score);
        }
        if (command == 2) {
            A.sort_by_name();
        }
        if (command == 3) {
            A.sort_by_score();
        }
        if (command == 4)
            break;
        else
            continue;
    }
    return 0;
}


//
// Created by Á¤¼º¿± on 2022/05/10.
//
