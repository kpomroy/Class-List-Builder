#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include "Student.h"
#include "Class.h"
#include "Person.h"

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


// Create a function to execute the python script
void executePythonScript(const std::string& script) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(script.c_str(), "r");
    if (!pipe) {
        std::cerr << "Failed to execute Python script" << std::endl;
        cout << result << endl;
    }

    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        result += buffer;
    }

    pclose(pipe);
    cout << result << endl;
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
    vector<Class> applicableClasses;

    for (Class c : allClasses) {
        if (c.getGrade() == grade) {
            applicableClasses.push_back(c);
        }
    }

    Teacher classOneTeacher = applicableClasses[0].getTeacher();
    Teacher classTwoTeacher = applicableClasses[1].getTeacher();
    outFile << "TEACHER: " << classOneTeacher << endl;
    int maleCount1 = 0;
    int femaleCount1 = 0;
    for (Student s : class1) {
        outFile << s << endl;
        if (s.getSex() == 0) {
            maleCount1++;
        } else {
            femaleCount1++;
        }
    }

    outFile << "\n";
    outFile << "MALES: " << maleCount1 << endl;
    outFile << "FEMALES: " << femaleCount1 << endl;
    outFile << "\n";
    outFile << "\n";
    int maleCount2 = 0;
    int femaleCount2 = 0;
    outFile << "TEACHER: " << classTwoTeacher << endl;
    for (Student s : class2) {
        outFile << s << endl;
        if (s.getSex() == 0) {
            maleCount2++;
        } else {
            femaleCount2++;
        }
    }

    outFile << "\n";
    outFile << "MALES: " << maleCount2 << endl;
    outFile << "FEMALES: " << femaleCount2 << endl;
    outFile << "\n";

    // Pass these values to be used in the python script class.py
    executePythonScript("python class.py " + to_string(maleCount1) + " " + to_string(femaleCount1) + " " +to_string(femaleCount2) + " " +to_string(femaleCount2));

    outFile.close();
}

int main(int argc, char* argv[]) {
    vector<Student> students;
    vector<Class> classes;
    int gradeNum;
    string grade = argv[1];
    string studentFile = argv[2];
    string classFile = argv[3];

    getStudentDataFromFile(studentFile, students);
    getClassDataFromFile(classFile, classes);


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

    // make lists for selected grades
    // repeat sorting algorithm for each grade
    // for (Grade g : selectedGrades) {
        // string gradeName = gradeToString(g);
        // string gradeVector;
    vector<Student> class1;
    vector<Student> class2;

    if (grade == "Kindergarten") {
        assignClasses(kindergarten, class1, class2);
        cout << "Starting output" << endl;
        outputResults(intToGrade(0), class1, class2, classes, "kindergarten.txt");
        cout << "Ending output" << endl;
    } else if (grade == "First") {
        assignClasses(firstGrade, class1, class2);
        outputResults(intToGrade(1), class1, class2, classes, "firstGrade.txt");
    } else if (grade == "Second") {
        assignClasses(secondGrade, class1, class2);
        outputResults(intToGrade(2), class1, class2, classes, "secondGrade.txt");
    } else if (grade == "Third") {
        assignClasses(thirdGrade, class1, class2);
        outputResults(intToGrade(3), class1, class2, classes, "thirdGrade.txt");
    } else if (grade == "Fourth") {
        assignClasses(fourthGrade, class1, class2);
        outputResults(intToGrade(4), class1, class2, classes, "fourthGrade.txt");
    } else {
        assignClasses(fifthGrade, class1, class2);
        outputResults(intToGrade(5), class1, class2, classes, "fifthGrade.txt");
    }
    return 0;
}
