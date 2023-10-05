#ifndef M2OEP_KPOMROY_SALAMUTU_RELATIONSHIP_H
#define M2OEP_KPOMROY_SALAMUTU_RELATIONSHIP_H

#include "Student.h";

// This class will represent a relationship between two students: a pairing or a conflict
// If two students have a conflict, they will not be placed in the same class if possible
// If two students have a pairing they will be prioritized to be in the same class
class Relationship {
private:
    Student student1;
    Student student2;

public:
    // constructor
    Relationship(Student s1, Student s2);

    // getters and setters
    Student getStudent1();
    Student getStudent2();

    // Overloaded operators
    friend ostream& operator << (ostream& os, const Relationship& r);
};


#endif //M2OEP_KPOMROY_SALAMUTU_RELATIONSHIP_H
