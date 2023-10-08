#ifndef M2OEP_KPOMROY_SALAMUTU_PERSON_H
#define M2OEP_KPOMROY_SALAMUTU_PERSON_H

#include <string>
#include <iostream>
using namespace std;

enum Sex {male, female};

class Person {
private:
    string firstName;
    string lastName;
    Sex sex;

public:
    // constructor
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
