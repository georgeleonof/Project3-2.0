#ifndef PROJECT3_COURSE_H
#define PROJECT3_COURSE_H
#include <string>

using std::string;

class Course {
private:
    string course_code;
    string course_verb;
    unsigned int course_sem;
    float course_grade;

public:
    //δήλωση όλων των constructors
    Course();
    Course(string course_code, string course_verb);
    Course(string course_code, string course_verb, unsigned int course_sem);
    Course(string course_code, string course_verb, unsigned int course_sem, float course_grade);

    //copy constructor
    Course(const Course &crs);

    //όλες οι set
    void set_course_code(string) ;
    void set_course_verb(string) ;
    void set_course_sem(unsigned int) ;
    void set_course_grade(float) ;

    //όλες οι get
    string get_course_code() const;
    string get_course_verb() const;
    unsigned int get_course_sem() const;
    float get_course_grade() const;

    void CoursePrint() const;

    void writeCourse() const;
};

#endif //PROJECT3_COURSE_H