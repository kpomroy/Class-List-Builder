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
    string reason;
public:
    // constructor
    Relationship(Student s1, Student s2);

    // getters and setters
    Student getStudent1();
    Student getStudent2();
    string getReason();

    void setReason(string reason);

    virtual string print() = 0;
};


#endif //M2OEP_KPOMROY_SALAMUTU_RELATIONSHIP_H
