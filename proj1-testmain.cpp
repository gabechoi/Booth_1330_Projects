/**
 * file: proj1-testmain.cpp
 * author: Gabriel Choi
 * course: CSI 1440
 * assignment: Project 1
 * due date: 8/28/22
 */

#include <iostream>
#include <sstream>

#include "proj1-person.hpp"

using namespace std;

int main(){

    Person myPersons[25];
    Person *refPersons[25];
    istringstream inSS;
    string test;

    for(int i = 0; i < 25; ++i){
        refPersons[i] = &myPersons[i];
    }


    test = "Gabe Choi, 23\nTyler Johnson Ryan, 12\nKyle Rayner, 45\nClark, 39";

    inSS.clear();
    inSS.str(test);

    //test all functions

    cout << "testing getAPersonFromStream" << endl;
    getAPersonFromStream(inSS, refPersons[0]);
    getAPersonFromStream(inSS, refPersons[1]);
    getAPersonFromStream(inSS, refPersons[2]);
    getAPersonFromStream(inSS, refPersons[3]);

    cout << "testing displayAPerson:" << endl;

    cout << "Should be:\n Gabe Choi, 23\nTyler Johnson Ryan, 12\nKyle Rayner, 45\nClark, 39\n" << endl;

    displayAPerson(cout, refPersons[0]);
    displayAPerson(cout, refPersons[1]);
    displayAPerson(cout, refPersons[2]);
    displayAPerson(cout, refPersons[3]);

    cout << "\ntesting sortPersonArrayByAge:" << endl;
    cout << "Should be:\nTyler Johnson Ryan, 12\nGabe Choi, 23\nClark, 39\nKyle Rayner, 45\n" << endl;

    sortPersonArrayByAge(refPersons, 4);

    displayAPerson(cout, refPersons[0]);
    displayAPerson(cout, refPersons[1]);
    displayAPerson(cout, refPersons[2]);
    displayAPerson(cout, refPersons[3]);

    cout << "\ntesting sortPersonArrayByName:" << endl;
    cout << "Should be:\nClark, 39\nGabe Choi, 23\nKyle Rayner, 45\nTyler Johnson Ryan, 12\n" << endl;

    sortPersonArrayByName(refPersons, 4);

    displayAPerson(cout, refPersons[0]);
    displayAPerson(cout, refPersons[1]);
    displayAPerson(cout, refPersons[2]);
    displayAPerson(cout, refPersons[3]);

    cout << "\ntesting findAPerson:" << endl;

    cout << "Should be:\nGabe Choi, 23\n" << endl;
    string name = "Gabe Choi";
    displayAPerson(cout, findAPerson(refPersons, 4, name));
    cout << endl;

    string name2 = "Hayden Clark";

    cout << "Should be:\nnullptr\n" << endl;
    if(findAPerson(refPersons, 4, name2) == nullptr){
        cout << "nullptr" << endl << endl;
    }


    cout << "testing capacity of array: " << endl;
    for(int i = 4; i < 25; ++i){
        refPersons[i]->name = "Kaden Pomper";
        refPersons[i]->age = rand() % 80;
    }

    for(int i = 0; i < 25; ++i){
        cout << i << ".  ";
        displayAPerson(cout,refPersons[i]);
    }

    cout << endl;

    cout << "testing sort by age with full array" << endl << endl;

    sortPersonArrayByAge(refPersons, 25);

    for(int i = 0; i < 25; ++i){
        displayAPerson(cout,refPersons[i]);
    }

    cout << endl;

    cout << "testing for blank lines:" << endl << endl;

    istringstream inSS1;
    istringstream inSS2;
    Person myPeople[3];
    Person *refToMyPeople[3];
    int count = -1;

    for(int i = 0; i < 3; ++i){
        refToMyPeople[i] = &myPeople[i];
    }

    string test1 = "Gabe Choi, 23\nJoe Ingles, 76\n\n\nPlanter Man, 25";
    string test2;
    inSS1.str(test1);
    for(int i = 0; i < 5; ++i){
        getline(inSS1, test2);
        inSS2.clear();
        inSS2.str(test2);
        if(!test2.empty()){
            ++count;
            getAPersonFromStream(inSS2, refToMyPeople[count]);
        }
    }

    for(int i = 0; i < 3; ++i){
        displayAPerson(cout, refToMyPeople[i]);
    }

    return 0;
}

