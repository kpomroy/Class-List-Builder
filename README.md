Kevin Pomroy
9/17/23
CS 2300
M1OEP

Description:
This program is used to create class lists of students in an elementary school (grades K-5) to save teachers and administrators time 
with creating them manually. It takes a csv of students with fields firstName, lastName, grade, and sex and separates them by grade to
split them into two classes with as close to as equal number of students and equal splits of males and females as possible. The user
chooses which grades they are looking for lists for and the lists are outputted to txt files for easy viewing and modification if necessary.

When testing, the program will ask for the name of the students csv file. The testing file I included is called "students.csv" and it includes
a list of randomly generated students through grades K-5.

Module 1 concepts used:
Class: Student class
Overloaded operators: == , <<
Enumerated types: Grade (kindergarten-fifth grade), Sex (male/female)

Known bugs: 
none

Future work:
I originally intended for this program to be able to take a csv of classes with teacher and grade fields and create class lists for any
number of classes per grade, however after spending too much time on an extremely innefficient algorithm with exponential time complexity 
and creating multiple classes for the algorithm, I realized that the program wouldn't work for any reasonably sized class due to run time.
Moving forward, I plan to implement this ability to split students into any number of classes. I also plan for users to be able to mark 
students that cannot be in class together or need to be in class together and create class lists that follow these criteria as closely as
possible.

Expected grade:
 - Main program complexity and usability: 35 pts
This program uses three of the four Module 1 concepts listed in the description. It also has a higher complexity than a guided project,
however I did not have time to make it as complex as I wanted.
 - Concept: C++ class: 20 pts
The Student class is designed well, implemented robustly and effectively, and includes overloaded operators. It also uses a function
to read in data from the students csv file and store each student as an object.
 - Concepts: Overloaded Operators, enums, structs: 5 pts
Overloaded operators and enums were designed well and were essential to the implementation of the Student class. Both were used 
effectively throughout the program.
 - Style and documentation: 0pts
All functions are well documented and the program is commented throughout. Student class is also separated into .h and .cpp files.
 - Video: 0pts 
Video includes multiple demo runs and demonstrates input validation.
 - Lifespan of project: 
First repository commits were 7 days before the due date (9/10) and there are commits on 5 separate days.

**Note** The Class and StudentClassPair classes are not implemented in this program because of the algorithm change to sort the students. 
They are not fully complete or documented since they aren't being used, however I left them in the repository for timestamp purposes.