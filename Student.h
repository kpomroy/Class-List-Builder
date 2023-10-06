#ifndef M1OEP_KPOMROY_STUDENT_H
#define M1OEP_KPOMROY_STUDENT_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Person.h"
using namespace std;

enum Grade {
    kindergarten,
    first,
    second,
    third,
    fourth,
    fifth};



class Student : private Person{
    /*
     * This class represents a student to be assigned to a class based on their grade level and other attributes
     * including behavioral and relational issues with other students.
     *
     */

private:
    // Fields
    Grade grade;



public:
    // Constructors
    Student();
    Student(string firstName, string lastName, Sex sex, Grade grade);

    // Getters
    Grade getGrade() const;


    // Setters
    void setGrade(Grade grade);
};

/*
 * Function to read in student data from a csv file and save students as Student objects in a vector
 * Takes: filename - the csv filename
 *        students - the vector of Students to save the information to
 * Returns: boolean value true if successful else false
 */
bool getStudentDataFromFile(string filename, vector<Student>& students);

#endif //M1OEP_KPOMROY_STUDENT_H
