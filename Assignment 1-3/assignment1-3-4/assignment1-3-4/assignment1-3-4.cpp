#include <iostream>

using namespace std;

void current_location(char block[5][5])
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << block[i][j];
        }
        cout << endl;
    }
}

int main() {
    char node[5][5] = { 'H', 'O', 'O', 'O', 'O',
                       'O', 'O', 'O', 'O', 'O',
                       'O', 'O', 'O', 'O', 'O',
                       'O', 'O', 'O', 'O', 'O',
                       'O', 'O', 'O', 'O', 'O' };
    int currentX = 0, currentY = 0;
    int pastX[5] = { 0, }, pastY[5] = { 0, };
    while (true) {
        node[pastX[4]][pastY[4]] = 'O';
        for (int i = 0; i < 4; i++) {
            node[pastX[i]][pastY[i]] = 'X';
        }
        node[currentX][currentY] = 'H';

        current_location(node);
        for (int i = 4; i > 0; i--) {
            pastX[i] = pastX[i - 1];
            pastY[i] = pastY[i - 1];
        }
        pastX[0] = currentX;
        pastY[0] = currentY;
    again:
        char control;
        cin >> control;
        if (control == 'a') {
            if (currentY != 0)
                currentY -= 1;
            else
            {
                current_location(node); 
                goto again;
            }
        }
        else if (control == 'd') {
            if (currentY != 4)
                currentY += 1;
            else
            {
                current_location(node);
                goto again;
            }
        }
        else if (control == 'w') {
            if (currentX != 0)
                currentX -= 1;
            else
            {
                current_location(node);
                goto again;
            }
        }
        else if (control == 's') {
            if (currentX != 4)
                currentX += 1;
            else
            {
                current_location(node);
                goto again;
            }
        }
        else if (control == 'q')
            break;
        else
        {
            current_location(node);
            goto again;
        }
    }
    return 0;
}
//
// Created by Á¤¼º¿± on 2022/03/17.
//