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

class Student : public Person{
    /*
     * This class represents a student to be assigned to a class based on their grade level and other attributes
     * including behavioral and relational issues with other students.
     *
     */

private:
    // Fields
    Grade grade;
    float gpa;


public:
    // Constructors
    Student(string firstName, string lastName, Sex sex, Grade grade, float gpa);

    // Getters
    Grade getGrade() const;
    float getGPA() const;

    // Setters
    void setGrade(Grade grade);
    void setGPA(float gpa);
};

/*
 * Function to read in student data from a csv file and save students as Student objects in a vector
 * Takes: filename - the csv filename
 *        students - the vector of Students to save the information to
 * Returns: boolean value true if successful else false
 */
bool getStudentDataFromFile(string filename, vector<Student>& students);

#endif //M1OEP_KPOMROY_STUDENT_H
