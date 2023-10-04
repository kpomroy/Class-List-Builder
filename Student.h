#ifndef M1OEP_KPOMROY_STUDENT_H
#define M1OEP_KPOMROY_STUDENT_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

enum Grade {
    kindergarten,
    first,
    second,
    third,
    fourth,
    fifth};

enum Sex {male, female};

class Student {
    /*
     * This class represents a student to be assigned to a class based on their grade level and other attributes
     * including behavioral and relational issues with other students.
     *
     */

private:
    // Fields
    string firstName;
    string lastName;
    Grade grade;
    Sex sex;


public:
    // Constructors
    Student();
    Student(string firstName, string lastName, Grade grade, Sex sex);

    // Getters
    string getFirstName() const;
    string getLastName() const;
    Grade getGrade() const;
    Sex getSex() const;

    // Setters
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setGrade(Grade grade);
    void setSex(Sex sex);

    // Overloaded operators
    friend ostream& operator << (ostream& os, const Student& s);

    bool operator == (const Student &s);
};

/*
 * Function to read in student data from a csv file and save students as Student objects in a vector
 * Takes: filename - the csv filename
 *        students - the vector of Students to save the information to
 * Returns: boolean value true if successful else false
 */
bool getStudentDataFromFile(string filename, vector<Student>& students);

#endif //M1OEP_KPOMROY_STUDENT_H
