//course.cpp

#include "Course.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//default constructor για Μάθημα
Course::Course(){
    cout << "Γίνεται εκκίνηση του default constructor για το Μάθημα." << endl;
    cout << "********************************" << endl;
    this -> course_code = "";
    this -> course_verb = "";
    this -> course_sem = 0;
    this -> course_grade = 0.0;
}

//constructor με δύο παραμέτρους για Μάθημα
Course::Course(string course_code, string course_verb){
    cout << "Γίνεται εκκίνηση του constructor με 2 παραμέτρους για το Μάθημα." << endl;
    cout << "********************************" << endl;
    this -> course_code = course_code;
    this -> course_verb = course_verb;
    this -> course_sem = 0;
    this -> course_grade = 0.0;
}

//constructor τρεις παραμέτρους για το Μάθημα
Course::Course(string course_code, string course_verb, unsigned int course_sem){
    cout << "Γίνεται εκκίνηση του constructor με 3 παραμέτρους για το Μάθημα." << endl;
    cout << "********************************" << endl;
    this -> course_code = course_code;
    this -> course_verb = course_verb;
    this -> course_sem = course_sem;
    this -> course_grade = 0.0;
}

Course::Course(string course_code, string course_verb, unsigned int course_sem, float course_grade){
    cout << "Γίνεται εκκίνηση του constructor με 3 παραμέτρους για το Μάθημα." << endl;
    cout << "********************************" << endl;
    this -> course_code = course_code;
    this -> course_verb = course_verb;
    this -> course_sem = course_sem;
    this -> course_grade = course_grade;
}

//ακολουθεί η υλοποίηση του copy constructor
Course::Course(const Course &crs){
    cout << "Γίνεται εκκίνηση του Course copy constructor." << endl;
    this -> course_code = crs.course_code;
    this -> course_verb = crs.course_verb;
    this -> course_sem = crs.course_sem;
    this -> course_grade = crs.course_grade;
}

//υλοποίηση των set
void Course::set_course_code(string course_code) {
    this -> course_code = course_code;
}

void Course::set_course_verb(string course_verb) {
    this -> course_verb = course_verb;
}

void Course::set_course_sem(unsigned int course_sem) {
    this -> course_sem = course_sem;
}

void Course::set_course_grade(float course_grade) {
    this -> course_grade = course_grade;
}

//υλοποίηση των get
string Course::get_course_code() const{
    return this -> course_code;
}

string Course::get_course_verb() const{
    return this -> course_verb;
}

unsigned int Course::get_course_sem() const{
    return this -> course_sem;
}

float Course::get_course_grade() const{
    return this -> course_grade;
}

//υλοποίηση μεθόδου για εγγραφή σε αρχείο
void Course::writeCourse() const {
    ofstream fileCourse;
    //οτιδήποτε γράφουμε προστίθενται στο τέλος του αρχείου
    fileCourse.open("Mathimata.txt", ios::app);

    if(!fileCourse.is_open()) {
        cout << "\n Δυστυχώς κάτι πήγε λάθος... \n" << endl;
    }
    fileCourse << "Κωδικός Μαθήματος: " << this->course_code << " \n"
               << "Λεκτικό Μαθήματος: " << this->course_verb << " \n"
               << "Εξάμηνο Μαθήματος: " << this->course_sem << endl;

    fileCourse << "************************************" << endl << endl;

    cout << "Το αρχείο Μαθημάτων δημιουργήθηκε επιτυχώς." << endl;
    cout << "Μόλις έγινε εγγραφή νεόυ μαθήματος στο Αρχείο Μαθημάτων." << endl;
    fileCourse.close();
}

//print function
void Course::CoursePrint () const{
    cout << "********************************" << endl;
    cout << "Κωδικός Μαθήματος: " << this -> course_code << endl;
    cout << "Λεκτικό Μαθήματος: " << this -> course_verb << endl;
    cout << "Εξάμηνο Μαθήματος: " << this -> course_sem << endl;
    cout << "********************************" << endl;
}