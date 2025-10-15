#ifndef PROGRESSREPORT_H
#define PROGRESSREPORT_H


#include "Student.h"


class ProgressReport {
private:
Student* student;
int totalCourses;
float averageGrade;
public:
ProgressReport();
ProgressReport(Student* s, int totalCourses, float averageGrade);
~ProgressReport();


void setStudent(Student* s);
Student* getStudent() const;


void setTotalCourses(int t);
int getTotalCourses() const;


void setAverageGrade(float g);
float getAverageGrade() const;


void displayReport() const;
};


#endif // PROGRESSREPORT_H
