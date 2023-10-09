#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include "Student.cpp"
#include "Class.cpp"
#include "Person.cpp"

using namespace std;

/*
 * This program places students within an elementary school into two class lists. The program will make class sizes as even as possible
 * as well as optimize the split between males and females in each class. This is designed to save teachers and administrators
 * time with creating class lists.
 */

/*
 * Function to display menu options for grade selection
 */
void printGrades() {
    cout << "\n";
    cout << "0: Kindergarten" << endl;
    cout << "1: First" << endl;
    cout << "2: Second" << endl;
    cout << "3: Third" << endl;
    cout << "4: Fourth" << endl;
    cout << "5: Fifth" << endl;
}

/*
 * Function to display an input request message and validate a string input from the user
 * Does not allow for an empty input
 * Takes: desiredInput - string that will print before a string input is prompted and validated
 * Returns: user input as a string
 */
string getStringFromUser(string desiredInput) {
    cin.clear();
    string input;
    cout << desiredInput;
    while (true) {
        getline(cin, input);
        if (input.empty() || input.find_first_not_of(' ') == string::npos) {
            cout << "No input. " << desiredInput;
        } else {
            return input;
        }
    }
}

/*
 * Function to get user input for grade selection and validate input to be 0-5 for kindergarten - fifth grade
 * Returns: integer representing the grade number
 */
int getGradeNum() {
    string input;
    cout << "Grade: ";
    while (true) {
        getline(cin, input);
        if (input != "0" && input != "1" && input != "2" && input != "3" && input != "4" && input != "5") {
            cout << "Invalid choice. Enter a grade (0-5): ";
        } else {
            if (input == "0") {
                return 0;
            } else if (input == "1") {
                return 1;
            } else if (input == "2") {
                return 2;
            } else if (input == "3") {
                return 3;
            } else if (input == "4") {
                return 4;
            } else {
                return 5;
            }
        }
    }
}

/*
 * Function to take an integer grade number (0-5) and return the Grade enum value
 * Takes: gradeNum - integer representing a grade number
 * Returns: corresponding Grade enum value
 */
Grade intToGrade(int gradeNum) {
    if (gradeNum == 0) {
        return kindergarten;
    } else if ( gradeNum == 1) {
        return first;
    } else if ( gradeNum == 2) {
        return second;
    } else if ( gradeNum == 3) {
        return third;
    } else if ( gradeNum == 4) {
        return fourth;
    } else {
        return fifth;
    }
}

/*
 * Function to take a Grade enum value and return it as a string
 * Takes: Grade enum value
 * Returns: the grade as a string
 */
string gradeToString(Grade grade) {
    switch (grade) {
        case kindergarten : return "kindergarten";
        case first : return "first";
        case second : return "second";
        case third : return "third";
        case fourth : return "fourth";
        case fifth : return "fifth";
    }
}

/*
 * Custom sort function to compare Student objects and sort them by Sex enum (male or female)
 * Takes: two Student objects to compare sex
 * Returns: boolean value true if student 1 is male and student 2 is female else false
 */
bool sortBySex(const Student &student1, const Student &student2) {
    return student1.getSex() < student2.getSex();
}

/*
 * Function that uses the custom sort function to sort a vector of Students by sex and divides them into two classes
 * with equal class sizes and gender splits (or as close to equal as possible)
 * Takes: students - vector of students to sort
 *        class1/class2 - vectors of students to place half of the students in
 */
void assignClasses(vector<Student> students, vector<Student> &class1, vector<Student> &class2) {
    sort(students.begin(), students.end(), sortBySex);

    // Iterate through sorted students and assign them to classes
    for (const Student &s : students) {
        // Choose the class with fewer students of the same sex
        if (class1.size() <= class2.size()) {
            class1.push_back(s);
        } else {
            class2.push_back(s);
        }
    }
}

/*
 * Function to output class lists to a txt file for easy viewing by the user
 * txt file displays grade, student names, and the number of males and females in each class
 * Takes: grade - Grade enum value
 *        clas1/class2 - vectors of students that have been split into two classes
 *        outFileName - string representing the name of the file to print results to
 */
void outputResults(Grade grade, vector<Student> &class1, vector<Student> &class2, vector<Class> &allClasses, string outFileName) {

    ofstream outFile;
    outFile.open(outFileName);
    outFile << "GRADE: " << gradeToString(grade) << endl;
    outFile << "\n" << endl;
    // TODO: read from a vector of classes to determine which class is which
    vector<Class> applicableClasses;

    for (Class c : allClasses) {
        if (c.getGrade() == grade) {
            applicableClasses.push_back(c);
        }
    }

    Teacher classOneTeacher = applicableClasses[0].getTeacher();
    Teacher classTwoTeacher = applicableClasses[1].getTeacher();
    outFile << "TEACHER: " << classOneTeacher << endl;
    int maleCount = 0;
    int femaleCount = 0;
    for (Student s : class1) {
        outFile << s << endl;
        if (s.getSex() == 0) {
            maleCount++;
        } else {
            femaleCount++;
        }
    }
    outFile << "\n";
    outFile << "MALES: " << maleCount << endl;
    outFile << "FEMALES: " << femaleCount << endl;
    outFile << "\n";
    outFile << "\n";
    maleCount = 0;
    femaleCount = 0;
    outFile << "TEACHER: " << classTwoTeacher << endl;
    for (Student s : class2) {
        outFile << s << endl;
        if (s.getSex() == 0) {
            maleCount++;
        } else {
            femaleCount++;
        }
    }
    outFile << "\n";
    outFile << "MALES: " << maleCount << endl;
    outFile << "FEMALES: " << femaleCount << endl;
    outFile << "\n";

    outFile.close();
}

int main() {
    vector<Student> students;
    vector<Class> classes;
    int gradeNum;

    // Start menu and get grade level
    cout << "Welcome to the class list builder" << endl;
    cout << "\n";

    // get csv file names and try to read them into vectors
    bool studentFileRead = false;
    bool classFileRead = false;

    // read student file
    while (!studentFileRead) {
        string studentFile = getStringFromUser("Please enter the name of the students csv file: ");
        if(getStudentDataFromFile(studentFile, students)) {
            studentFileRead = true;
        } else {
            cout << "File not found" << endl;
        }
    }
    cout << "\n";

    // read class file
    while (!classFileRead) {
        string classFile = getStringFromUser("Please enter the name of the teachers csv file: ");
        if(getClassDataFromFile(classFile, classes)) {
            classFileRead = true;
        } else {
            cout << "File not found" << endl;
        }
    }
    cout << "\n";

    // separate students into grade vectors
    vector<Student> kindergarten;
    vector<Student> firstGrade;
    vector<Student> secondGrade;
    vector<Student> thirdGrade;
    vector<Student> fourthGrade;
    vector<Student> fifthGrade;

    for (Student s : students) {
        if (s.getGrade() == 0) {
            kindergarten.push_back(s);
        } else if (s.getGrade() == 1) {
            firstGrade.push_back(s);
        } else if (s.getGrade() == 2) {
            secondGrade.push_back(s);
        } else if (s.getGrade() == 3) {
            thirdGrade.push_back(s);
        } else if (s.getGrade() == 4) {
            fourthGrade.push_back(s);
        } else {
            fifthGrade.push_back(s);
        }
    }

    // allow user to choose which grade(s) they want to make class lists for
    cout << "What grade(s) would you like class lists for?" << endl;
    vector<Grade> selectedGrades;
    string addGrade;
    Grade gradeString;
    bool additionalGrade = true;

    while (additionalGrade) {
        bool duplicate = false;
        // display grade options and get user input
        printGrades();
        gradeNum = getGradeNum();
        gradeString = intToGrade(gradeNum);
        for (Grade g : selectedGrades) {
            if (gradeString == g) {
                cout << "You already selected this grade" << endl;
                duplicate = true;
            }
        }
        // dont allow duplicate grade selections and end loop once all grades are selected
        if (!duplicate) {
            selectedGrades.push_back(gradeString);
        }
        if (selectedGrades.size() < 6) {
            cout << "\n";
            cout << "Would you like to add another grade? (y/n) ";
            getline(cin, addGrade);
        } else {
            additionalGrade = false;
        }

        // validate user input
        while (addGrade != "n" && addGrade != "N" && addGrade != "y" && addGrade != "Y") {
            cout << "Invalid choice." << endl;
            cout << "Would you like to add another grade? (y/n) ";
            getline(cin, addGrade);
        }
        if (addGrade == "n" || addGrade == "N") {
            additionalGrade = false;
        }
    }
    // print selection(s) for user feedback
    cout << "\n";
    cout << "Creating class lists for: " << endl;
    for (Grade g : selectedGrades) {
        if (g == 0) {
            cout << gradeToString(g) << endl;
        } else {
            cout << gradeToString(g) << " grade" << endl;
        }
    }

    // make lists for selected grades
    // repeat sorting algorithm for each grade
    for (Grade g : selectedGrades) {
        string gradeName = gradeToString(g);
        string gradeVector;
        vector<Student> class1;
        vector<Student> class2;

        if (g == 0) {
            assignClasses(kindergarten, class1, class2);
            outputResults(g, class1, class2, classes, "kindergarten.txt");
        } else if (g == 1) {
            assignClasses(firstGrade, class1, class2);
            outputResults(g, class1, class2, classes, "firstGrade.txt");
        } else if (g == 2) {
            assignClasses(secondGrade, class1, class2);
            outputResults(g, class1, class2, classes, "secondGrade.txt");
        } else if (g == 3) {
            assignClasses(thirdGrade, class1, class2);
            outputResults(g, class1, class2, classes, "thirdGrade.txt");
        } else if (g == 4) {
            assignClasses(fourthGrade, class1, class2);
            outputResults(g, class1, class2, classes, "fourthGrade.txt");
        } else {
            assignClasses(fifthGrade, class1, class2);
            outputResults(g, class1, class2, classes, "fifthGrade.txt");
        }
    }
    return 0;
}
