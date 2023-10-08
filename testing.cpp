#include "Person.h"
#include "Person.cpp"
#include "Student.h"
#include "Teacher.h"
#include "Class.h"

#include <iostream>
using namespace std;

bool personTesting();
bool studentTesting();
bool teacherTesting();
bool classTesting();

int main() {
    if(personTesting()) {
        cout << "Passed all test cases!" << endl;
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
        cout << "Failed default constructor test case" << endl;
        passed = false;
    }
    // constructor
    Person p2("first", "last", male);
    if (p2.getFirstName() != "first" || p2.getLastName() != "last" || p2.getSex() != male) {
        cout << "Failed constructor test case" << endl;
        passed = false;
    }
    // getters and setters
    p.setFirstName("first");
    if (p.getFirstName() != "first") {
        cout << "Failed first name test case" << endl;
        passed = false;
    }
    p.setLastName("last");
    if (p.getLastName() != "last") {
        cout << "Failed last name test case" << endl;
        passed = false;
    }
    p.setSex(female);
    if (p.getSex() != female) {
        cout << "Failed sex test case" << endl;
        passed = false;
    }
    // overloaded operators
    if (!(p == p2)) {
        cout << "Failed == case" << endl;
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
        Teacher t;
        if (t.getFirstName() != "" || t.getLastName() != "") {
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
        t.setDept(Math);
        if (t.getDept() != Math) {
            cout << "Failed department test case" << endl;
            passed = false;
        }

        return passed;
    }


