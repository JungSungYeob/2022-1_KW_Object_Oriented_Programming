#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char node[3][3] = { 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(10) << std::left << node[i][j];
        }
        cout << endl;
    }
    int currentX = 0, currentY = 0;
    while (true) {
        node[currentX][currentY] = 'O';
        cout << "Enter Move Command(a : Left, d: Right, w: Up, s: Down, q: Finish :";
        char control;
        cin >> control;
        if (control == 'a') {
            if (currentY != 0)
                currentY -= 1;
        }
        else if (control == 'd') {
            if (currentY != 2)
                currentY += 1;
        }
        else if (control == 'w') {
            if (currentX != 0)
                currentX -= 1;
        }
        else if (control == 's') {
            if (currentX != 2)
                currentX += 1;
        }
        else if (control == 'q')
            break;
        else
            continue;
        node[currentX][currentY] = 'X';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << setw(10) << std::left << node[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
//
// Created by Á¤¼º¿± on 2022/03/17.
//