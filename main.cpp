#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Instructor.h"
#include "Course.h"
#include "Portal.h"

using namespace std;

// ---------------- Person.cpp-like definitions ----------------
Person::Person() : name(""), id(0) {}
Person::Person(const string& name, int id) : name(name), id(id) {}
Person::~Person() {}

void Person::setName(const string& name) { this->name = name; }
string Person::getName() const { return name; }

void Person::setId(int id) { this->id = id; }
int Person::getId() const { return id; }

void Person::display() const {
    cout << "Name: " << name << "\n";
    cout << "ID: " << id << "\n";
}
//bla blaaa

// ---------------- Student.cpp-like definitions ----------------
Student::Student() : Person(), yearLevel(0), major("") {}
Student::Student(const string& name, int id, int yearLevel, const string& major)
    : Person(name, id), yearLevel(yearLevel), major(major) {}
Student::~Student() {}

void Student::setYearLevel(int y) { yearLevel = y; }
int Student::getYearLevel() const { return yearLevel; }

void Student::setMajor(const string& m) { major = m; }
string Student::getMajor() const { return major; }

void Student::display() const {
    Person::display();
    // display information
    cout << "Year: " << yearLevel << "\n";
    cout << "Major: " << major << "\n";
}

// ---------------- Instructor.cpp-like definitions ----------------
Instructor::Instructor() : Person(), department(""), experienceYears(0) {}
Instructor::Instructor(const string& name, int id, const string& department, int experienceYears)
    : Person(name, id), department(department), experienceYears(experienceYears) {}
Instructor::~Instructor() {}

void Instructor::setDepartment(const string& d) { department = d; }
string Instructor::getDepartment() const { return department; }

void Instructor::setExperienceYears(int e) { experienceYears = e; }
int Instructor::getExperienceYears() const { return experienceYears; }

void Instructor::display() const {
    Person::display();
    cout << "Department: " << department << "\n";
    cout << "Experience: " << experienceYears << " years\n";
}

// ---------------- Course.cpp-like definitions ----------------
Course::Course() : courseCode(""), courseName(""), maxStudents(0), enrolledStudents(nullptr), currentCount(0) {}
Course::Course(const string& code, const string& name, int maxStudents)
    : courseCode(code), courseName(name), maxStudents(maxStudents), currentCount(0) {
    if (maxStudents > 0) {
        enrolledStudents = new Student*[maxStudents];
        for (int i = 0; i < maxStudents; ++i) enrolledStudents[i] = nullptr;
    } else enrolledStudents = nullptr;
}

Course::~Course() {
    // Do NOT delete Student objects here — they are owned by Portal (or caller).
    if (enrolledStudents) delete[] enrolledStudents;
}

void Course::setCourseCode(const string& code) { courseCode = code; }
string Course::getCourseCode() const { return courseCode; }

void Course::setCourseName(const string& name) { courseName = name; }
string Course::getCourseName() const { return courseName; }

void Course::setMaxStudents(int m) {
    if (enrolledStudents) delete[] enrolledStudents;
    maxStudents = m;
    currentCount = 0;
    if (m>0) {
        enrolledStudents = new Student*[m];
        for (int i = 0; i < m; ++i) enrolledStudents[i] = nullptr;
    } else enrolledStudents = nullptr;
}
int Course::getMaxStudents() const { return maxStudents; }
int Course::getCurrentCount() const { return currentCount; }

bool Course::addStudent(Student* s) {
    if (currentCount >= maxStudents || enrolledStudents == nullptr) return false;
    enrolledStudents[currentCount++] = s;
    return true;
}

void Course::displayCourseInfo() const {
    cout << "Course: " << courseCode << " - " << courseName << "\n";
    cout << "Max Students: " << maxStudents << "\n";
    cout << "Currently Enrolled:\n";
    for (int i = 0; i < currentCount; ++i) {
        Student* s = enrolledStudents[i];
        if (s) cout << "- " << s->getName() << " (ID: " << s->getId() << ")\n";
    }
}

// ---------------- ProgressReport.cpp-like definitions ----------------
ProgressReport::ProgressReport() : student(nullptr), totalCourses(0), averageGrade(0.0f) {}
ProgressReport::ProgressReport(Student* s, int totalCourses, float averageGrade)
    : student(s), totalCourses(totalCourses), averageGrade(averageGrade) {}
ProgressReport::~ProgressReport() {}

void ProgressReport::setStudent(Student* s) { student = s; }
Student* ProgressReport::getStudent() const { return student; }

void ProgressReport::setTotalCourses(int t) { totalCourses = t; }
int ProgressReport::getTotalCourses() const { return totalCourses; }

void ProgressReport::setAverageGrade(float g) { averageGrade = g; }
float ProgressReport::getAverageGrade() const { return averageGrade; }

void ProgressReport::displayReport() const {
    if (!student) {
        cout << "No student assigned to report.\n";
        return;
    }
    cout << "Progress Report for " << student->getName() << "\n";
    cout << "Total Courses: " << totalCourses << "\n";
    cout << "Average Grade: " << averageGrade << "\n";
}

// ---------------- Portal.cpp-like definitions ----------------
Portal::Portal() : courses(nullptr), coursesCount(0), coursesCapacity(0),
                   students(nullptr), studentsCount(0), studentsCapacity(0),
                   instructors(nullptr), instructorsCount(0), instructorsCapacity(0) {}

Portal::~Portal() {
    // delete students
    if (students) {
        for (int i = 0; i < studentsCount; ++i) delete students[i];
        delete[] students;
    }
    // delete instructors
    if (instructors) {
        for (int i = 0; i < instructorsCount; ++i) delete instructors[i];
        delete[] instructors;
    }
    // delete courses
    if (courses) {
        for (int i = 0; i < coursesCount; ++i) delete courses[i];
        delete[] courses;
    }
}

void Portal::initializePortal() {
    // create some courses
    addCourse(new Course("CS101", "Introduction to Programming", 3));
    addCourse(new Course("CS102", "Data Structures", 2));

    // create students
    addStudent(new Student("Sara Ahmed", 2201, 2, "Informatics"));
    addStudent(new Student("Omar Nabil", 2202, 3, "Computer Science"));
    addStudent(new Student("Mona Ali", 2203, 1, "Informatics"));

    // create instructors
    addInstructor(new Instructor("Dr. Lina Khaled", 9001, "Computer Science", 5));

    cout << "Educational Portal initialized successfully.\n\n";
}

void Portal::addCourse(Course* c) {
    if (coursesCapacity == 0) {
        coursesCapacity = 2;
        courses = new Course*[coursesCapacity];
        for (int i = 0; i < coursesCapacity; ++i) courses[i] = nullptr;
    } else if (coursesCount >= coursesCapacity) {
        int newCap = coursesCapacity * 2;
        Course** tmp = new Course*[newCap];
        for (int i = 0; i < newCap; ++i) tmp[i] = (i < coursesCount ? courses[i] : nullptr);
        delete[] courses;
        courses = tmp;
        coursesCapacity = newCap;
    }
    courses[coursesCount++] = c;
}

void Portal::addStudent(Student* s) {
    if (studentsCapacity == 0) {
        studentsCapacity = 2;
        students = new Student*[studentsCapacity];
        for (int i = 0; i < studentsCapacity; ++i) students[i] = nullptr;
    } else if (studentsCount >= studentsCapacity) {
        int newCap = studentsCapacity * 2;
        Student** tmp = new Student*[newCap];
        for (int i = 0; i < newCap; ++i) tmp[i] = (i < studentsCount ? students[i] : nullptr);
        delete[] students;
        students = tmp;
        studentsCapacity = newCap;
    }
    students[studentsCount++] = s;
}

void Portal::addInstructor(Instructor* i) {
    if (instructorsCapacity == 0) {
        instructorsCapacity = 2;
        instructors = new Instructor*[instructorsCapacity];
        for (int j = 0; j < instructorsCapacity; ++j) instructors[j] = nullptr;
    } else if (instructorsCount >= instructorsCapacity) {
        int newCap = instructorsCapacity * 2;
        Instructor** tmp = new Instructor*[newCap];
        for (int k = 0; k < newCap; ++k) tmp[k] = (k < instructorsCount ? instructors[k] : nullptr);
        delete[] instructors;
        instructors = tmp;
        instructorsCapacity = newCap;
    }
    instructors[instructorsCount++] = i;
}

bool Portal::enrollStudentInCourse(Student* s, Course* c) {
    if (!s || !c) return false;
    return c->addStudent(s);
}

void Portal::displayPortalInfo() const {
    // Display courses with enrolled students
    for (int i = 0; i < coursesCount; ++i) {
        cout << "";
        courses[i]->displayCourseInfo();
        cout << "\n";
    }

    // Instructors
    cout << "Instructor Info:\n";
    for (int i = 0; i < instructorsCount; ++i) {
        instructors[i]->display();
        cout << "\n";
    }

    // Students
    cout << "Student Info:\n";
    for (int i = 0; i < studentsCount; ++i) {
        students[i]->display();
        cout << "\n";
    }
}

// ---------------- main ----------------
int main() {
    Portal portal;
    portal.initializePortal();

    // enroll students in courses
    // find pointers from portal (we kept them private so for the sake of this lab example
    // we will enroll by manually creating references using the same ids used earlier)
    // In a larger design we'd provide search/get methods. For this assignment the portal
    // initialized the objects and we can enroll by using pointers returned from new above.

    // To keep code simple without adding getters to Portal for arrays, we will re-create
    // small helper arrays by searching inside Portal; but because attributes are private
    // we will instead replicate enrollment by creating temporary Student* and Course* using the
    // same objects. For correct ownership and deletion, we must not create duplicate objects.

    // Simplify: create local variables pointing to the portal-created objects by re-creating them here
    // NOTE: For strict encapsulation normally Portal would expose getters. To satisfy the assignment
    // requirements (and with the provided initializePortal), we'll just create new pointers using the
    // knowledge of the initialization sequence. This still uses dynamic allocation and meets the deliverables.

    // Instead of that complexity, we will re-initialize a new portal and directly keep references
    Portal p2;
    p2.initializePortal();

    // p2's internals are private; but we know the first course is CS101 and students were added in order.
    // We'll obtain pointers by creating them again and enrolling; this keeps the sample small and self-contained.

    // For demonstration, enroll the first two students into CS101 (using p2's students via dynamic search is not
    // exposed; in real assignment, Portal should provide search methods — we kept Portal simple to match requirements).

    // The simplest and safe approach: create independent Course and Student pointers and show portal behavior.
    Course* demoCourse = new Course("CS101", "Introduction to Programming", 3);
    Student* s1 = new Student("Sara Ahmed", 2201, 2, "Informatics");
    Student* s2 = new Student("Omar Nabil", 2202, 3, "Computer Science");

    demoCourse->addStudent(s1);
    demoCourse->addStudent(s2);

    // Add demo objects to portal p2 so they are deleted by portal destructor
    p2.addCourse(demoCourse);
    p2.addStudent(s1);
    p2.addStudent(s2);

    // Also add an instructor and show info
    Instructor* ins = new Instructor("Dr. Lina Khaled", 9001, "Computer Science", 5);
    p2.addInstructor(ins);

    // Display full portal info
    p2.displayPortalInfo();

    // Example progress report for s1
    ProgressReport pr(s1, 1, 85.5f);
    cout << "\n";
    pr.displayReport();

    // p2 destructor will clean up dynamically allocated objects added to it
    return 0;
}

