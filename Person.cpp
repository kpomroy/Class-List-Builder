#include "Person.h"

Person::Person(string firstName, string lastName, Sex sex) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->sex = sex;
}

string Person::getFirstName() const {
    return firstName;
}

string Person::getLastName() const {
    return lastName;
}

Sex Person::getSex() const {
    return sex;
}

void Person::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Person::setLastName(string lastName) {
    this->lastName = lastName;
}

void Person::setSex(Sex sex) {
    this->sex = sex;
}

// Overloaded operators
ostream& operator << (ostream& os, const Person& p) {
    os << p.getFirstName() << " " << p.getLastName();
    return os;
}

bool Person::operator == (const Person &p) {
    if (firstName == p.firstName && lastName == p.lastName) {
        return true;
    } else {
        return false;
    }
}
