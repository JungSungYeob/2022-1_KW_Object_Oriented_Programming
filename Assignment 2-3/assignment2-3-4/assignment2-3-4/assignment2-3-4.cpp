#include <iostream>
#include <cstring>

using namespace std;

class animal {
private:
    char name[10];
    int year = 0;
    char species[100];
public:
    char* rt_name() {
        return name;
    }

    void set_name(char* Name) {
        strcpy_s(name, Name);
    }

    int rt_year() {
        return year;
    }

    void set_year(int Year) {
        year = Year;
    }

    char* rt_species() {
        return species;
    }

    void set_species(char* Species) {
        strcpy_s(species, Species);
    }
};

class zoo {
private:
    class animal* animal_list[100];

    int size = 0;
public:

    void new_animal(char* name, int year, char* species);

    void print_species(char* species);

    void print_all();

    ~zoo() {
        for (int i = 0; i < size; i++)
        {
            delete animal_list[i];
        }
    }
};

void zoo::new_animal(char* Name, int Year, char* Species) {
    animal_list[size] = new animal;
    animal_list[size]->set_name(Name);
    animal_list[size]->set_year(Year);
    animal_list[size]->set_species(Species);
    size++;
}

void zoo::print_species(char* Species) {
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(animal_list[i]->rt_species(), Species) == 0) {
            cout << "---------" << cnt << "----------" << endl;
            cout << "Name :" << animal_list[i]->rt_name() << endl;
            cout << "Year :" << animal_list[i]->rt_year() << endl;
            cout << "Species :" << animal_list[i]->rt_species() << endl;
            cout << "--------------------" << endl;
            cnt++;
        }
    }
    cout << "Number of Species is :" << cnt << endl;
    cout << "--------------------" << endl;
}

void zoo::print_all() {
    cout << "------print_all------" << endl;
    for (int i = 0; i < size; i++) {
        cout << "---------" << i << "----------" << endl;
        cout << "Name :" << animal_list[i]->rt_name() << endl;
        cout << "Year :" << animal_list[i]->rt_year() << endl;
        cout << "Species :" << animal_list[i]->rt_species() << endl;
        cout << "--------------------" << endl;
    }
    cout << "--------------------" << endl;
}

int main() {
    class zoo Zoo;
    while (1) {
        cout << "Please Enter Any Command(new_animal, print_all, print_species, exit) :";
        char command[15];
        cin >> command;
        if (strcmp(command, "exit") == 0)
            break;
        else if (strcmp(command, "new_animal") == 0) {
            char animal_name[10];
            int animal_year;
            char animal_species[100];
            cin >> animal_name >> animal_year >> animal_species;
            Zoo.new_animal(animal_name, animal_year, animal_species);
        }
        else if (strcmp(command, "print_all") == 0) {
            Zoo.print_all();
        }
        else if (strcmp(command, "print_species") == 0) {
            char tmp_word[100];
            cin >> tmp_word;
            Zoo.print_species(tmp_word);
        }
        else {
            cout << endl;
            continue;
        }
    }
    return 0;
}

//
// Created by Á¤¼º¿± on 2022/04/27.
//
