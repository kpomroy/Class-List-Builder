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




bool getTeacherDataFromFile(string filename, vector<Teacher>& teachers) {
    //create a file handler object
    ifstream inFile;
    //open the file
    inFile.open(filename);

    string header;

    //check if the file can be read from
    if (inFile) {
        //read a full line from the inFile into the header string
        getline(inFile, header);
    } else {
        return false;
    }
    // Declare variables to be read in from csv
    string firstName;
    string lastName;
    string gradeNum;
    Grade grade;
    string sexString;
    Sex sex;
    Department dept;
    char comma;

}