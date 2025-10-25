
//define class course here

#ifndef COURSE_H
#define COURSE_H
#include "Student.h"
#include "Person.h"
#include <string>

class Course {
private:
    string courseCode;
    string courseName;
    int maxStudents;
    Student** enrolledStudents; // dynamic array of Student*
    int currentCount;

public:
    Course();
    Course(const string& code, const string& name, int maxStudents);
    ~Course();

    void setCourseCode(const string& code);
    string getCourseCode() const;

    void setCourseName(const string& name);
    string getCourseName() const;

    void setMaxStudents(int m);
    int getMaxStudents() const;

    bool addStudent(Student* s); // returns true if added
    void displayCourseInfo() const;

    int getCurrentCount() const;
};

#endif // COURSE_H

