#ifndef M2OEP_KPOMROY_SALAMUTU_PERSON_H
#define M2OEP_KPOMROY_SALAMUTU_PERSON_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

enum Sex {male, female};

class Person {
private:
    string firstName;
    string lastName;
    Sex sex;

public:
    // constructors
    Person();
    Person(string firstName, string lastName, Sex sex);

    // getters and setters
    string getFirstName() const;
    string getLastName() const;
    Sex getSex() const;

    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setSex(Sex sex);

    // Overloaded operators
    friend ostream& operator << (ostream& os, const Person& p);

    bool operator == (const Person &p);
};


#endif //M2OEP_KPOMROY_SALAMUTU_PERSON_H
