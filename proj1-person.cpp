/**
 * file: proj1-person.cpp
 * author: Gabriel Choi
 * course: CSI 1440
 * assignment: Project 1
 * due date: 8/28/22
 */

#include <iostream>
#include <sstream>
#include "proj1-person.hpp"

istream &getAPersonFromStream(istream &in, Person *p) {
    string buffer;
    istringstream inSS;

    getline(in, p->name, ',');
    inSS.clear();
    getline(in, buffer);
    inSS.str(buffer);
    inSS >> p->age;

    return in;
}

void sortPersonArrayByAge(Person **pArray, int count){
    int min;
    Person *temp;
    for(int i = 0; i < count; ++i){
        min = i;
        for(int j = i + 1; j < count; ++j){
            if(pArray[j]->age < pArray[min]->age){
               min = j;
            }
        }
        temp = pArray[i];
        pArray[i] = pArray[min];
        pArray[min] = temp;
    }
}
void sortPersonArrayByName(Person **pArray, int count){
    Person *temp;
    for(int i = 0; i < count - 1; ++i){
        for(int j = 0; j < count - i - 1; ++j){
            if(pArray[j]->name > pArray[j+1]->name){
                temp = pArray[j];
                pArray[j] = pArray[j+1];
                pArray[j+1] = temp;
            }
        }
    }
}
Person * findAPerson(Person ** pArray, int count, string name){
    for(int i = 0; i < count; ++i){
        if(pArray[i]->name == name){
            return pArray[i];
        }
    }
    return nullptr;

}
void displayAPerson(ostream &out, const Person *p){
    out << p->name << ", " << p->age << endl;
}

