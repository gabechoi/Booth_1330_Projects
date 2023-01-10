/**
 * file: proj1-main.cpp
 * author: Gabriel Choi
 * course: CSI 1440
 * assignment: Project 1
 * due date: 8/28/22
 */

#include <iostream>
#include <fstream>
#include "proj1-person.hpp"
#include <sstream>

using namespace std;

int main(){
    Person thePeople[25];
    Person *referenceToThePeople[25];
    int count = -1;
    ifstream inFile;
    string test;
    string fileName = "people.dat";
    istringstream inSS;
    string name;
    Person *testPerson;


    inFile.open(fileName);

    for(int i = 0; i < 25; ++i) {
        referenceToThePeople[i] = &thePeople[i];
    }

    while(inFile){
        getline(inFile, test);
        inSS.clear();
        inSS.str(test);
        if(!test.empty()){
            ++count;
            getAPersonFromStream(inSS, referenceToThePeople[count]);
        }
    }

    inFile.close();

    if(count < 0){
        count = 0;
    }


    sortPersonArrayByAge(referenceToThePeople, count);

    for(int i = 0; i < 5; ++i){
        displayAPerson(cout, referenceToThePeople[i]);
    }

    sortPersonArrayByName(referenceToThePeople, count);

    for(int i = 0; i < 5; ++i){
        displayAPerson(cout, referenceToThePeople[i]);
    }

    cout << "Enter name: ";
    getline(cin, name);

    while(name != "no more"){
        if(findAPerson(referenceToThePeople, count, name) != nullptr){
            displayAPerson(cout, findAPerson(referenceToThePeople, count, name));
        }
        else {
            cout << "Not in List" << endl;
        }
        getline(cin, name);
    }

    return 0;
}