# Elementary School Class List Generator - M2OEP

## Contributors
- Sam Alamutu
- Kevin Pomroy
- Kira Safferstein

## Date
October 29, 2023

## Overview
This program automates the creation of class lists for an elementary school, covering grades K-5. It saves teachers and administrators valuable time by generating class lists based on a CSV file containing student information, including fields for first name, last name, grade, and gender. The program divides students by grade and aims to distribute them as evenly as possible across classes, ensuring an equal split between males and females. It then outputs this information to a web page, where the user is able to interact and choose what grade they would like to generate a class list for. The class list and teacher list will be output to the webpage as well as a bar graph showing the distribution of students based on gender within each class. 

## Usage
When running the program, it will prompt the user to provide the name of the CSV file containing student data and a CSV file containing teacher data. Sample testing files named "students.csv" and "teachers.csv" with randomly generated student and teacher data is included in the repository.

## Module 3 Concepts Used
- **Other programming language (python)**: The program utilizes python to create a distribution graph to show how evenly the students were divided between the two classes based on gender. As can be seen in the graph, there is either the same amount of females in each class, or they only differ by one. The same is true for males. 
- **Other programming language (PHP)**: PHP is used to ____________________________________________________ 
- **Other nonprogramming language (HTML)**: 
- **Other nonprogramming language (CSS)**:
- **Command line argument(s)**: 

## Known Bugs
No known bugs have been reported in the current version of the program.

## Future Work
Future goals of this project include editing the algorithm to work for any number of classes per grade. Another goal is implementing relationships between students that would require them or prevent them from being in class with other specific students who they either get along with or don't get along with.

## Expected Grade
- **Main Program Complexity and Usability**: 40 pts
  This program is interactive with validation, uses all concepts from module 3, and exhibits a higher complexity level than a guided project. It's read and write capabilities also increase complexity.
- **Concept: Other Programming Language(s)**: 40 pts
  Apart from C++, python and PHP are also used in a way that make sense for the program and the languages abilities.
- **Concept: Other Non-programming Language(s)**: 20 pts
  HTML and CSS are both used to properly output a working website.
- **Command Line Argument(s)**: 4 pts
  In C++ we call the command line to run a python script to graph the data that was read in in the C++ file. In results we call the command line to create an executable for main.cpp and run it.
- **Style and Documentation**: 0 pts
  The program is well-documented with comments, and all classes are neatly separated into header and implementation files.
- **Video**: 0 pts
  The video presentation includes multiple demonstrations and showcases input validation.
- **Lifespan of Project**: 0 pts
  The first repository commits were made a week days before the due date (on 10/22), with commits spanning across five separate days.
