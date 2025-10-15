#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

#include <string>


class Student : public Person {
private:
int yearLevel;
std::string major;
public:
Student();
Student(const std::string& name, int id, int yearLevel, const std::string& major);
~Student();


// setters / getters
void setYearLevel(int y);
int getYearLevel() const;


void setMajor(const std::string& m);
std::string getMajor() const;


void display() const override;
};


#endif
