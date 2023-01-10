//
// Created by gabec on 8/27/2022.
//

#ifndef PROJ1_1_PROJ1_PERSON_HPP
#define PROJ1_1_PROJ1_PERSON_HPP

#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
};

istream &getAPersonFromStream(istream &, Person *); // reads a single Person from the stream
void sortPersonArrayByAge(Person **, int); // implements selection sort ascending order
void sortPersonArrayByName(Person **, int); // implements bubble sort ascending order
Person * findAPerson(Person **, int, string); // implements linear search
void displayAPerson(ostream &, const Person *); // writes a single Person to the stream

#endif //PROJ1_1_PROJ1_PERSON_HPP
