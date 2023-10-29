#ifndef M1OEP_KPOMROY_CLASS_H
#define M1OEP_KPOMROY_CLASS_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Student.h"
#include "Teacher.h"
// #include "Teacher.cpp"
using namespace std;

/*
 * This class represents a class of students within an elementary school.
 * Each class has a teacher and grade level. Teachers in the school only teach one class per year.
 */
class Class {
private:
    // Fields
    Teacher teacher;
    Grade grade;

public:
    // Constructors
    Class();
    Class(Teacher teacher, Grade grade);

    // Getters
    Teacher getTeacher() const;
    Grade getGrade() const;

    // Setters
    void setTeacher(Teacher teacher);
    void setGrade(Grade grade);

    // Overloaded operators
    friend ostream& operator << (ostream& os, const Class& c);
    bool operator == (const Class &c);
};

/*
 * Function to read in Teacher data from a csv file and save teachers as teacher objects in a vector
 * Takes: filename - the csv filename
 *        teachers - the vector of teachers to save the information to
 * Returns: boolean value true if successful else false
 */
bool getClassDataFromFile(string filename, vector<Class>& classes);

#endif //M1OEP_KPOMROY_CLASS_H
