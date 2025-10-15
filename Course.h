#ifndef COURSE_H
#define COURSE_H

#include "Student.h"
#include <string>
//define class course here
class Course {
private:
std::string courseCode;
std::string courseName;
int maxStudents;
Student** enrolledStudents; // dynamic array
int currentCount;
public:
Course();
Course(const std::string& code, const std::string& name, int maxStudents);
~Course();


// setters / getters
void setCourseCode(const std::string& code);
std::string getCourseCode() const;


void setCourseName(const std::string& name);
std::string getCourseName() const;


void setMaxStudents(int m);
int getMaxStudents() const;


int getCurrentCount() const;


// functionality
bool addStudent(Student* s); // returns true if added
void displayCourseInfo() const;
};


#endif
