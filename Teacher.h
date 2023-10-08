//
// Created by Sam Alamutu on 2023-10-06.
//

#ifndef M1OEP_TEACHER_H
#define M1OEP_TEACHER_H


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Person.h"
using namespace std;

enum Grade {
    kindergarten,
    first,
    second,
    third,
    fourth,
    fifth};

enum Department{
    Math,
    Science,
    English,
    Athletics,
    Arts
};

class Teacher : public Person{
/*
 * This class represents a Teacher to be assigned to a class based on their teaching grade level, teaching department,  and other attributes
 * including behavioral and relational issues with other Teachers.
 *
 */

private:
    // Fields
    Grade grade;
    Department dept;



public:
    // Constructors
    Teacher();
    Teacher(string firstName, string lastName, Sex sex, Grade grade, Department dept);

    // Getters
    Grade getGrade() const;
    Department getDept() const;


    // Setters
    void setGrade(Grade grade);
    void setDept(Department dept);
};



#endif //M1OEP_TEACHER_H
