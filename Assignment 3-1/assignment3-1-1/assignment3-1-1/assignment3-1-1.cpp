#include <iostream>

using namespace std;

class Person {
    friend istream& operator >> (istream&, Person&);
    friend ostream& operator << (ostream&, const Person&);
private:
    char P_name[10];
    int P_num;
    char P_location[10];
};
istream& operator>>(istream& input, Person& P)
{
    input >> P.P_name;
    input >> P.P_num;
    input >> P.P_location;
    return input;
}
ostream& operator <<(ostream& output, const Person& P)
{
    output << "이름 :" << P.P_name << endl;
    output << "나이 :" << P.P_num << endl;
    output << "거주지 :" << P.P_location << endl;
    return output;
}
int main() {
    Person P;
    cin >> P;
    cout << P;
    return 0;
}

//
// Created by 정성엽 on 2022/05/17.
//
