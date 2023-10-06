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
    string deptString;
    Grade grade;
    string sexString;
    Sex sex;
    Department dept;
    char comma;

    //While the file is still in a good state to be read from
    //and we're not at the end of the file (check for end of file character)
    //inFile.peek() looks at next character
    while (inFile && inFile.peek() != EOF) {
        // first name
        getline(inFile, firstName, ',');
        // last name
        getline(inFile, lastName, ',');
        // grade
        getline(inFile, gradeNum, ',');
        // convert to Grade object
        if (gradeNum == "0") {
            grade = kindergarten;
        } else if (gradeNum == "1") {
            grade = first;
        } else if (gradeNum == "2") {
            grade = second;
        } else if (gradeNum == "3") {
            grade = third;
        } else if (gradeNum == "4") {
            grade = fourth;
        } else {
            grade = fifth;
        }

        // sex
        getline(inFile, sexString, '\n');
        if (sexString == "m") {
            sex = male;
        } else {
            sex = female;
        }

        //Departement
        getline(inFile, deptString, '\n');
        if(deptString == "Math"){
            dept = Math;
        }
        if(deptString == "Science"){
            dept = Science;
        }
        if(deptString == "English"){
            dept = English;
        }
        if(deptString == "Athletics"){
            dept = Athletics;
        }
        if(deptString == "Arts"){
            dept = Arts;
        }

        //Create a class object and add it to the vector
        teachers.push_back(Teacher(firstName, lastName, sex, grade, dept));
    }
    //close the file
    inFile.close();
    return true;

}