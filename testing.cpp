#include "Person.cpp"
#include "Student.cpp"
#include "Teacher.cpp"
#include "Class.cpp"

#include <iostream>
using namespace std;

bool personTesting();
bool studentTesting();
bool teacherTesting();
bool classTesting();

int main() {
    if(personTesting()) {
        cout << "Passed person test cases" << endl;
    }
    if(studentTesting()) {
        cout << "Passed student test cases" << endl;
    }

    if(teacherTesting()){
        cout << "Passed all test cases!" << endl;
    }

    if(classTesting()){
        cout << "Passed all test cases!" << endl;
    }

    return 0;
}

bool personTesting() {
    bool passed = true;
    // default constructor
    Person p;
    if (p.getFirstName() != "" || p.getLastName() != "") {
        cout << "Failed person default constructor test case" << endl;
        passed = false;
    }
    // constructor
    Person p2("first", "last", male);
    if (p2.getFirstName() != "first" || p2.getLastName() != "last" || p2.getSex() != male) {
        cout << "Failed person constructor test case" << endl;
        passed = false;
    }
    // getters and setters
    p.setFirstName("first");
    if (p.getFirstName() != "first") {
        cout << "Failed person first name test case" << endl;
        passed = false;
    }
    p.setLastName("last");
    if (p.getLastName() != "last") {
        cout << "Failed person last name test case" << endl;
        passed = false;
    }
    p.setSex(female);
    if (p.getSex() != female) {
        cout << "Failed person sex test case" << endl;
        passed = false;
    }
    // overloaded operators
    if (!(p == p2)) {
        cout << "Failed person == case" << endl;
        passed = false;
    }
    return passed;
}

bool studentTesting() {
    bool passed = true;
    // default constructor
    Student s;
    if (s.getFirstName() != "" || s.getLastName() != "") {
        cout << "Failed student default constructor test case" << endl;
        passed = false;
    }
    // constructor
    Student s2("first", "last", male, kindergarten, 4.0);
    if (s2.getFirstName() != "first" || s2.getLastName() != "last" || s2.getSex() != male || s2.getGrade() != kindergarten || s2.getGPA() != 4.0) {
        cout << "Failed student constructor test case" << endl;
        passed = false;
    }
    // getters and setters
    s.setFirstName("first");
    if (s.getFirstName() != "first") {
        cout << "Failed student first name test case" << endl;
        passed = false;
    }
    s.setLastName("last");
    if (s.getLastName() != "last") {
        cout << "Failed student last name test case" << endl;
        passed = false;
    }
    s.setSex(female);
    if (s.getSex() != female) {
        cout << "Failed student sex test case" << endl;
        passed = false;
    }
    // overloaded operators
    if (!(s == s2)) {
        cout << "Failed student == case" << endl;
        passed = false;
    }
    return passed;
}

bool teacherTesting() {
    bool passed = true;
    // default constructor
    Teacher t;
    if (t.getFirstName() != "" || t.getLastName() != "") {
        cout << "Failed default constructor test case" << endl;
        passed = false;
    }
    // constructor
    Teacher t2("first", "last", male, Math);
    if (t2.getFirstName() != "first" || t2.getLastName() != "last" || t2.getSex() != male || t2.getDept() != Math) {
        cout << "Failed constructor test case" << endl;
        passed = false;
    }
    // getters and setters
    t.setDept(Math);
    if (t.getDept() != Math) {
        cout << "Failed department test case" << endl;
        passed = false;
    }

    return passed;
}

    bool classTesting() {
        bool passed = true;
        // default constructor
        Class c;
        if (c.getTeacher() != "" || c.getGrade() != "") {
            cout << "Failed default constructor test case" << endl;
            passed = false;
        }
        // constructor
        Teacher t2("first", "last", male, Math);
        if (t2.getFirstName() != "first" || t2.getLastName() != "last" || t2.getSex() != male ||
            t2.getDept() != Math) {
            cout << "Failed constructor test case" << endl;
            passed = false;
        }
        // getters and setters
        c.setDept(Math);
        if (c.getDept() != Math) {
            cout << "Failed department test case" << endl;
            passed = false;
        }

        return passed;
    }


