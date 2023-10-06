#include "Class.h"

// Constructors
Class::Class() {};
Class::Class(Teacher teacher, Grade grade) {
    this->teacher = teacher;
    this->grade = grade;
}

// Getters
Teacher Class::getTeacher() const {
    return teacher;
}

Grade Class::getGrade() const {
    return grade;
}

// Setters
void Class::setTeacher(Teacher teacher) {
    this->teacher = teacher;
}

void Class::setGrade(Grade grade) {
    this->grade = grade;
}

// Overloaded operators
ostream& operator << (ostream& os, const Class& c) {
    os << c.getTeacher() << "-" << c.getGrade();
    return os;
}

bool Class::operator == (const Class &c) {
    if (teacher == c.getTeacher() && grade == c.getGrade()) {
        return true;
    } else {
        return false;
    }
}

// Function to read classes from csv
bool getClassDataFromFile(string filename, vector<Class>& classes) {

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
    string gradeString;
    Grade grade;
    string teacherString;
    char comma;

    //While the file is still in a good state to be read from
    //and we're not at the end of the file (check for end of file character)
    //inFile.peek() looks at next character
    while (inFile && inFile.peek() != EOF) {
        // Grade
        getline(inFile, gradeString, ',');
        // convert to Grade object
        if (gradeString == "kindergarten") {
            grade = kindergarten;
        } else if (gradeString == "first") {
            grade = first;
        } else if (gradeString == "second") {
            grade = second;
        } else if (gradeString == "third") {
            grade = third;
        } else if (gradeString == "fourth") {
            grade = fourth;
        } else {
            grade = fifth;
        }

        // Teacher
        getline(inFile, teacher, '\n');



        //Create a class object and add it to the vector
        classes.push_back(Class(teacher, grade));
    }

    //close the file
    inFile.close();
    return true;
};