#include <iostream>

using namespace std;

void Matrix_Multiplication(int** A_Matrix, int** B_Matrix, int numA[2], int numB[2], int** result) {
    for (int i = 0; i < numA[0]; i++)
    {
        for (int j = 0; j < numB[1]; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < numA[1]; k++)
            {
                result[i][j] += A_Matrix[i][k] * B_Matrix[k][j];
            }
        }
    }
}

int main() {
    srand(time(NULL));
    cout << "Matrix A :";
    int Mt_numA[2];
    cin >> Mt_numA[0] >> Mt_numA[1];
    cout << "Matrix B :";
    int Mt_numB[2];
    cin >> Mt_numB[0] >> Mt_numB[1];

    //동적 할당 A
    int** Mt_outputA;
    Mt_outputA = new int* [Mt_numA[0]];
    for (int i = 0; i < Mt_numA[0]; i++)
        Mt_outputA[i] = new int[Mt_numA[1]];

    cout << "\nA Matrix :" << endl;
    for (int i = 0; i < Mt_numA[0]; i++) {
        for (int j = 0; j < Mt_numA[1]; j++) {
            Mt_outputA[i][j] = rand() % 11;
            cout << Mt_outputA[i][j] << "\t\t";
        }
        cout << endl;
    }
    //동적 할당 B
    int** Mt_outputB;
    Mt_outputB = new int* [Mt_numB[0]];
    for (int i = 0; i < Mt_numB[0]; i++)
        Mt_outputB[i] = new int[Mt_numB[1]];

    cout << "\nB Matrix :" << endl;
    for (int i = 0; i < Mt_numB[0]; i++) {
        for (int j = 0; j < Mt_numB[1]; j++) {
            Mt_outputB[i][j] = rand() % 11;
            cout << Mt_outputB[i][j] << "\t\t";
        }
        cout << endl;
    }

    int** Mt_result = new int* [Mt_numA[0]];
    for (int i = 0; i < Mt_numA[0]; i++)
        Mt_result[i] = new int[Mt_numB[1]];

    //행렬 곱셈
    if (Mt_numA[1] != Mt_numB[0])
        cout << "\n\nCan't Operate Matrix Multiplication(" << Mt_numB[0] << "!=" << Mt_numA[1] << ")" << endl;
    else {
        cout << "\nA*B Result :" << endl;
        Matrix_Multiplication(Mt_outputA, Mt_outputB, Mt_numA, Mt_numB, Mt_result);
        for (int i = 0; i < Mt_numA[0]; i++)
        {
            for (int j = 0; j < Mt_numB[1]; j++)
                cout << Mt_result[i][j] << "\t\t";
            cout << endl;
        }
    }

    //누수 방지
    for (int i = 0; i < Mt_numA[0]; i++)
        delete[]Mt_outputA[i];
    delete[]Mt_outputA;
    for (int i = 0; i < Mt_numB[0]; i++)
        delete[]Mt_outputB[i];
    delete[]Mt_outputB;
    for (int i = 0; i < Mt_numA[0]; i++)
        delete[]Mt_result[i];
    delete[]Mt_result;
    return 0;
}

//
// Created by 정성엽 on 2022/04/08.
//
