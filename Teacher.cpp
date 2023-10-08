//
// Created by Sam Alamutu on 2023-10-06.
//
#include "Teacher.h"

// Constructors
Teacher::Teacher(string firstName, string lastName, Sex sex, Grade grade, Department dept) : Person(firstName, lastName, sex), grade(grade), dept(dept){
}

// Getters
Grade Teacher::getGrade() const {
    return grade;
}
    Department Teacher::getDept() const {
        return dept;
    }


// Setters
    void Teacher::setGrade(Grade grade) {
        this->grade = grade;
    }

    void Teacher::setDept(Department dept) {
    this->dept = dept;
}




