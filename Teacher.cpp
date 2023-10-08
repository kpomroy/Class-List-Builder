//
// Created by Sam Alamutu on 2023-10-06.
//
#include "Teacher.h"

// Constructors
Teacher::Teacher(string firstName, string lastName, Sex sex, Department dept) : Person(firstName, lastName, sex), dept(dept){
}

// Getters
Department Teacher::getDept() const {
    return dept;
}


// Setters
    void Teacher::setDept(Department dept) {
    this->dept = dept;
}




