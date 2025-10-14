# Inlab-Assignment-1

The German International University
Faculty of Informatics and Computer Science

Dr. Nada Sharaf

Programming III, Winter Semester 2025/2026

In-lab assignment 01

---

## General Description:

In this project, you are tasked with implementing a simple **Educational Learning Portal System** as a console application. The system simulates how students enroll in courses, view grades, and track their progress. The purpose of this assignment is to practice **Object-Oriented Programming (OOP)** concepts such as **classes, inheritance, encapsulation, constructors, destructors, dynamic memory allocation, and separation of interface/implementation using header and source files**.

This assignment focuses on the **structure of the system**. Full functionality (grading, detailed reports, and performance analytics) will be implemented in **In-lab assignment 02**.

---

## Milestone 01: Required Classes and Methods

### a) **Person Class**

Represents a general person in the system. This class will serve as the **base class** for students and instructors.

* **Attributes** (all private):

  * `string name`
  * `int id`

* **Methods**:

  * `display()`: Displays the person’s name and ID.

* **Subclasses** (inherit from `Person`):

  * **Student**: Adds `int yearLevel` and `string major`.
  * **Instructor**: Adds `string department` and `int experienceYears`.

---

### b) **Course Class**

Represents a course that can be taken by students and taught by instructors.

* **Attributes** (all private):

  * `string courseCode`
  * `string courseName`
  * `int maxStudents`
  * Dynamic array of `Student*` to store enrolled students

* **Methods**:

  * `addStudent(Student* s)`: Adds a student dynamically to the course if capacity allows.
  * `displayCourseInfo()`: Displays course name, code, and all enrolled students.

---

### c) **Portal Class**

Represents the main educational portal that manages students, instructors, and courses.

* **Methods**:

  * `initializePortal()`: Creates a list of courses, students, and instructors dynamically.
  * `enrollStudentInCourse(Student* s, Course* c)`: Enrolls a student in a specific course.
  * `displayPortalInfo()`: Displays all current courses, students, and their relationships.

---

### d) **ProgressReport Class**

Represents a simple progress report generated for a student.

* **Attributes** (all private):

  * `Student* student`
  * `int totalCourses`
  * `float averageGrade`

* **Methods**:

  * `displayReport()`: Displays the student’s name, total courses, and average grade.

---

## Deliverables

* A **header file** for each of the above classes.
* A single **source file (.cpp)** containing all the implementations, which is the main.cpp file included in the folder.
* A `main()` function that:

  * Initializes the portal.
  * Adds a few students and instructors dynamically.
  * Enrolls students in courses.
  * Displays the portal’s full information (students, instructors, and courses).

*Include your name on the empty yourInformation.txt file in the same format:*
`TutorialNumber_StudentID_StudentName` e.g: T2_16007163_Ahmed Mohamed

---

## Important Notes

* **Cheating = 0 in the assignment.**
* **AI-generated code = 0 in the project.**
* All attributes in classes must be **private** with **setters and getters**.
* Each class must have:

  * A **default constructor**
  * A **parameterized constructor**
  * A **destructor** (even if empty)
* Arrays and objects must be **dynamically allocated**.
* Additional functionality (grading, analytics, reports) will be introduced in **In-lab assignment 02**.

---

## Example Console Output (for In-lab assignment 1 testing)

```
Educational Portal initialized successfully.

Course: CS101 - Introduction to Programming
Max Students: 3
Currently Enrolled:
- Sara Ahmed (ID: 2201)
- Omar Nabil (ID: 2202)

Instructor Info:
Name: Dr. Lina Khaled
Department: Computer Science
Experience: 5 years

Student Info:
Name: Sara Ahmed
Year: 2
Major: Informatics

