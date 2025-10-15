#ifndef PORTAL_H
#define PORTAL_H

#include "Course.h"
#include "Instructor.h"

//define class portal here
#include "Student.h"
#include "ProgressReport.h"


class Portal {
private:
Course** courses;
int coursesCount;
int coursesCapacity;


Student** students;
int studentsCount;
int studentsCapacity;


Instructor** instructors;
int instructorsCount;
int instructorsCapacity;
public:
Portal();
~Portal();


// initialization
void initializePortal();


// dynamic add
void addCourse(Course* c);
void addStudent(Student* s);
void addInstructor(Instructor* i);


bool enrollStudentInCourse(Student* s, Course* c);


void displayPortalInfo() const;
};






#endif
