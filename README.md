# Elementary School Class List Generator - M2OEP

## Contributors
- Sam Alamutu
- Kevin Pomroy

## Date
October 8, 2023

## Overview
This program automates the creation of class lists for an elementary school, covering grades K-5. It saves teachers and administrators valuable time by generating class lists based on a CSV file containing student information, including fields for first name, last name, grade, and gender. The program divides students by grade and aims to distribute them as evenly as possible across classes, ensuring an equal split between males and females.

## Usage
When running the program, it will prompt the user to provide the name of the CSV file containing student data. A sample testing file named "students.csv" with randomly generated student data is included in the repository.

## Module 2 Concepts Used
- **Inheritance relationships (is-a relationship)**: The program utilizes the `Person` class to represent individual people and serves as a template for different types of people in an elementary school. These people include, students from the `Student` class, and `Teachers` from the teacher class.
- **Component relationships (has-a)**: The program utilizes the `Class` class to represent a class in the elementary school. Each class has a teacher from the `Teacher` class and this ties all  the teachers components into the elementary school class.
- **File input and/or output**: Read information from different `.csv` files about students and teachers into the main program. The main program was then able to generate elementary school classes based on the requirements of the user and print the info to a `.txt` file

## Known Bugs
No known bugs have been reported in the current version of the program.

## Future Work
Future goals of this project include editing the algorithm to work for any number of classes per grade. Another goal is implementing relationships between students that would require them or prevent them from being in class with other specific students who they either get along with or don't get along with.

## Expected Grade
- **Main Program Complexity and Usability**: 40 pts
  This program is interactive with validation, uses all concepts from module 2, and exhibits a higher complexity level than a guided project. It's read and write capabilities also increase complexity.
- **Concept: C++ Class**: 20 pts
  The `Student` class is well-designed and effectively implemented, demonstrating strong usage of C++ classes.
- **Concepts: Inheritance Relationships, Component Relationships, File Input and Output**: 25 pts
  One parent class and two children classes are implemented in this program. The `Class` class has a component relationship with the Teacher class. CSV files are read in to get information about teachers, classes and students, and class lists are written out as txt files for every grade requested.
- **Style and Documentation**: 0 pts
  The program is well-documented with comments, and all classes are neatly separated into header and implementation files.
- **Video**: 0 pts
  The video presentation includes multiple demonstrations and showcases input validation.
- **Lifespan of Project**: 0 pts
  The first repository commits were made ten days before the due date (on 9/28), with commits spanning across five separate days.
