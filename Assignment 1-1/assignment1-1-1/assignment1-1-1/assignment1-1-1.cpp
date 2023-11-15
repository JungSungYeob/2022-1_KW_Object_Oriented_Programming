#include <iostream>

using namespace std;

int main() {

    cout << "이름 : ";
    char name[10];
    cin >> name;
    cout << "학번 : ";
    char num[11];
    cin >> num;
    cout << "전공 : ";
    char major[50];
    cin >> major;

    cout << major << " " << num << " " << name;
    return 0;
}