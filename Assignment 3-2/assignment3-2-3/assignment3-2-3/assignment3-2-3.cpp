#include <iostream>
#include <cstring>
using namespace std;

class item {
private:
    int price;
    int stock;
    int discount;
public:
    item(int price, int stock) {
        this->price = price;
        this->stock = stock;
        discount = 0;
    }

    int getprice() { return price; }

    int getstock() { return stock; }

    int getdiscount() { return discount; }

    void addstock(int num) { this->stock += num; }

    void sell_item(int num) { this->stock -= num; }

    void setdiscount(int num) { discount = num; }
};

class Pen : public item {
private:
public:
    Pen(int a, int b) : item(a, b) {};
};

class Pencil : public item {
private:
public:
    Pencil(int a, int b) : item(a, b) {};
};

class Eraser : public item {
private:
public:
    Eraser(int a, int b) : item(a, b) {};
};


int main() {
    class Pen pen(600, 100);
    class Pencil pencil(1200, 100);
    class Eraser eraser(500, 100);
    int command;
    int Sales = 0;
    cout << "====================" << endl;
    cout << "---------Pen--------" << endl;
    cout << "Price: " << pen.getprice() << endl;
    cout << "Stock: " << pen.getstock() << endl;
    cout << "Discount: " << pen.getdiscount() << endl;
    cout << "--------------------" << endl;
    cout << "-------Pencil-------" << endl;
    cout << "Price: " << pencil.getprice() << endl;
    cout << "Stock: " << pencil.getstock() << endl;
    cout << "Discount: " << pencil.getdiscount() << endl;
    cout << "--------------------" << endl;
    cout << "-------Eraser-------" << endl;
    cout << "Price: " << eraser.getprice() << endl;
    cout << "Stock: " << eraser.getstock() << endl;
    cout << "Discount: " << eraser.getdiscount() << endl;
    cout << "--------------------" << endl;
    cout << "====================" << endl;
    while (1) {
        cout << "Enter Any Command(0: Sell, 1: AddStock. 2: Discount, 3: Print, 4: Quit) :";
        cin >> command;
        if (command == 0) {
            char item[10];
            cin >> item;
            int cnt;
            cin >> cnt;
            if (strcmp(item, "Pen") == 0) {
                if (cnt * 3 > pen.getstock())
                    continue;
                else {
                    pen.sell_item(cnt * 3);
                    if (pen.getdiscount() == 0)
                        Sales += pen.getprice() * cnt;
                    else
                        Sales += pen.getprice() * (100-pen.getdiscount()) / 100 * cnt;
                }
            }
            else if (strcmp(item, "Pencil") == 0) {
                if (cnt * 12 > pencil.getstock())
                    continue;
                else {
                    pencil.sell_item(cnt * 12);
                    if (pencil.getdiscount() == 0)
                        Sales += pencil.getprice() * cnt;
                    else
                        Sales += pencil.getprice() * (100-pencil.getdiscount()) / 100 * cnt;
                }
            }
            else if (strcmp(item, "Eraser") == 0) {
                if (cnt > eraser.getstock())
                    continue;
                else {
                    eraser.sell_item(cnt);
                    if (eraser.getdiscount() == 0)
                        Sales += eraser.getprice() * cnt;
                    else
                        Sales += eraser.getprice() * (100-eraser.getdiscount()) / 100 * cnt;
                }
            }
            else
                continue;
            cout << "====================" << endl;
            cout << "Sales : " << Sales << endl;
            cout << "====================" << endl;
        }
        else if (command == 1) {
            char item[10];
            cin >> item;
            int cnt;
            cin >> cnt;
            if (strcmp(item, "Pen") == 0) {
                pen.addstock(cnt);
            }
            else if (strcmp(item, "Pencil") == 0) {
                pencil.addstock(cnt);
            }
            else if (strcmp(item, "Eraser") == 0) {
                eraser.addstock(cnt);
            }
            else
                continue;
            cout << "====================" << endl;
            cout << "Sales : " << Sales << endl;
            cout << "====================" << endl;
        }
        else if (command == 2) {
            char item[10];
            cin >> item;
            int num;
            cin >> num;
            if (strcmp(item, "Pen") == 0) {
                pen.setdiscount(num);
            }
            else if (strcmp(item, "Pencil") == 0) {
                pencil.setdiscount(num);
            }
            else if (strcmp(item, "Eraser") == 0) {
                eraser.setdiscount(num);
            }
            else
                continue;
            cout << "====================" << endl;
            cout << "Sales : " << Sales << endl;
            cout << "====================" << endl;
        }
        else if (command == 3) {
            {
                cout << "====================" << endl;
                cout << "---------Pen--------" << endl;
                cout << "Price: " << pen.getprice() << endl;
                cout << "Stock: " << pen.getstock() << endl;
                cout << "Discount: " << pen.getdiscount() << endl;
                cout << "--------------------" << endl;
                cout << "-------Pencil-------" << endl;
                cout << "Price: " << pencil.getprice() << endl;
                cout << "Stock: " << pencil.getstock() << endl;
                cout << "Discount: " << pencil.getdiscount() << endl;
                cout << "--------------------" << endl;
                cout << "-------Eraser-------" << endl;
                cout << "Price: " << eraser.getprice() << endl;
                cout << "Stock: " << eraser.getstock() << endl;
                cout << "Discount: " << eraser.getdiscount() << endl;
                cout << "--------------------" << endl;
                cout << "====================" << endl;
                cout << "====================" << endl;
                cout << "Sales : " << Sales << endl;
                cout << "====================" << endl;

            }
        }
        else if (command == 4) {
            break;
        }
        else
            continue;
    }
    return 0;
}
//
// Created by Á¤¼º¿± on 2022/05/24.
//
