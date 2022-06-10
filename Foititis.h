#ifndef PROJECT3_FOITITIS_H
#define PROJECT3_FOITITIS_H

#include <string>
#include <vector>
#include "Course.h"
#include <iostream>

using std::string;
using namespace std;

class Foititis {
private:
    char *a_m;
    string onoma;
    unsigned int eksamino;
    vector<Course> dilCourses;
    vector<Course> CompCoursesGrade;

public:
    //δήλωση όλων των constructors
    Foititis();
    Foititis(char *a_m, string onoma);
    Foititis(char *a_m, string onoma, unsigned int eksamino);

    //copy constructor
    Foititis(const Foititis &foit);

    //όλες οι set
    void set_a_m(char *);
    void set_onoma(string);
    void set_eksamino(unsigned int);

    //όλες οι get
    char *get_a_m();
    string get_onoma();
    unsigned int get_eksamino();

    //print function
    void Print();

    //η συνάρτηση που γράφει σε αρχείο
    void writeFoititis();

    //η συνάρτηση που κάνει το εξάμηνο +1
    void increaseEksamino(Foititis &foit);

    //destructor
    ~Foititis();

    //υπερφόρτωση τελεστών
    void operator+=(Course crs);

    bool operator== (Foititis &);
    bool operator!= (Foititis &) ;
    bool operator< (Foititis &) ;
    bool operator> (Foititis &) ;
    bool operator<= (Foititis &) ;
    bool operator>= (Foititis &) ;
    friend ostream& operator<< (ostream& os, const Foititis &dt)
    {
        //int i;
        os << dt.onoma << endl;
        cout << dt.dilCourses.size();
        /*for(i=0; i<dt.dilCourses.size(); i++)
        {
            os << dt.dilCourses[i]->get_course_verb() << " -> " << dt.dilCourses[i]->get_course_grade() << endl;
        }*/
        for (const Course& i : dt.dilCourses) {
            os << i.get_course_verb() << " -> " << i.get_course_grade() << endl;
        }
        os << "Average is -> " <<dt.calcCompCoursesGrade() << endl;
        os << endl;
        return os;
    }
    void AddDilCourses (Course course);
    void AddCompCoursesGrade(Course course);

    void printDilCourses();
    float calcCompCoursesGrade() const;
};

#endif //PROJECT3_FOITITIS_H