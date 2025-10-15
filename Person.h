#ifndef PERSON_H
#define PERSON_H

//write the class code here
#include <string>
#include <iostream>


class Person {
private:
std::string name;
int id;
public:
// constructors / destructor
Person();
Person(const std::string& name, int id);
virtual ~Person();


// getters / setters
void setName(const std::string& name);
std::string getName() const;


void setId(int id);
int getId() const;


// display
virtual void display() const;
};
#endif
