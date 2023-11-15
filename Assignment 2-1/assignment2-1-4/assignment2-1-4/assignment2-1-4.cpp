#include <iostream>

using namespace std;

int main() {
    srand(time(NULL));
    cout << "Original Matrix" << endl;

    int **tmp_Mat = new int *[10];
    for (int i = 0; i < 10; i++)
        tmp_Mat[i] = new int[10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tmp_Mat[i][j] = rand() % 101;
        }
    }

    int** OG_Mat = tmp_Mat;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << OG_Mat[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\n\nSort by row" << endl;

    int tmp;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                if (OG_Mat[i][j] > OG_Mat[i][k]) {
                    tmp = OG_Mat[i][j];
                    OG_Mat[i][j] = OG_Mat[i][k];
                    OG_Mat[i][k] = tmp;
                }
            }
        }
    }

    int sum[10];
    for (int i = 0; i < 10; i++) {
        sum[i] = 0;
        for (int j = 0; j < 10; j++) {
            cout << OG_Mat[i][j] << "\t";
            sum[i] += OG_Mat[i][j];
        }
        cout << "Sum is " << sum[i] << "(" << &sum[i] << ")" << endl;
    }

    cout << "\n\nSort by Sum" << endl;
    int sum_seq[10];
    int sum_tmp[10];
    for (int i = 0; i < 10; i++) {
        sum_tmp[i] = sum[i];
    }
    int high;
    for (int i = 0; i < 10; i++) {
        high = 0;
        for (int j = 0; j < 10; j++) {
            if (sum_tmp[high] < sum_tmp[j])
                high = j;
        }
        sum_seq[i] = high;
        sum_tmp[high] = 0;
    }

    for(int i=0;i<10;i++)
        OG_Mat[i]=&tmp_Mat[sum_seq[i]][0];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << OG_Mat[i][j] << "\t";
        }
        cout << "Sum is " << sum[sum_seq[i]] << "(" << &sum[sum_seq[i]] << ")" << endl;
    }
    delete[]tmp_Mat;
    return 0;

}

//
// Created by Á¤¼º¿± on 2022/04/12.
//
