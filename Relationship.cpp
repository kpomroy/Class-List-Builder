#include "Relationship.h"

// constructor
Relationship::Relationship(Student student1, Student student2) {
    this->student1 = student1;
    this->student2 = student2;
}

// getters and setters
Student Relationship::getStudent1() {
    return student1;
}

Student Relationship::getStudent2() {
    return student2;
}

string Relationship::getReason() {
    return reason;
}

void Relationship::setReason(string reason) {
    this->reason = reason;
}

