#include "Student.h"

// Constructors
Student::Student() {
}

Student::Student(string firstName, string lastName, Grade grade, Sex sex) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->grade = grade;
    this->sex = sex;
}

// Getters
string Student::getFirstName() const {
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

Grade Student::getGrade() const {
    return grade;
}

Sex Student::getSex() const {
    return sex;
}

// Setters
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setGrade(Grade grade) {
    this->grade = grade;
}

void Student::setSex(Sex sex) {
    this->sex = sex;
}

// Overloaded operators
ostream& operator << (ostream& os, const Student& s) {
    os << s.getFirstName() << " " << s.getLastName();
    return os;
}

bool Student::operator == (const Student &s) {
    if (firstName == s.firstName && lastName == s.lastName) {
        return true;
    } else {
        return false;
    }
}

bool getStudentDataFromFile(string filename, vector<Student>& students) {
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

        //Create a class object and add it to the vector
        students.push_back(Student(firstName, lastName, grade, sex));
    }

    //close the file
    inFile.close();
    return true;
}
