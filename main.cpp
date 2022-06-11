/*
	Άσκηση Εργαστηρίου 3
	Λεονώφ Γεώργιος
	Α.Μ.: 151029
	Π.Σ.: Τ.Ε.Ι. Αθήνας Ν2
	Ε-mail: cs151029@uniwa.gr
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>

#include "Foititis.h"
#include "Course.h"

using namespace std;

int main() {
    Course *testp;

    //foititis testF("151029", "George Leonof");
    //ή
    //Foititis testF((char *) "151029", "George Leonof");

    //testF.set_eksamino(14);

    //Foititis testF2(testF);

    //testF.Print();
    //cout << "Αυτό είναι ένα αντίγραφο του προηγούμενου αντικειμένου." << endl;
    //testF2.Print();

    Foititis testF3((char *) "161023", "Leuteris Eleutheriou", 8);
    Foititis testF4((char *) "cse5468795", "Nikos Nikolaou", 8);


    //testF3.writeFoititis();
    //testF3.Print();

    //testF4.writeFoititis();





    //testF3.increaseEksamino(testF3);
    //testF3.Print();
    //testF4.increaseEksamino(testF4);
    //testF4.Print();

    //testF3.writeFoititis();
    //testF4.writeFoititis();

    //testF4.~foititis();

    //δοκιμή της υπερφόρτωσης του += για ένα μάθημα
    Course course1("N35", "C++", 4);
    //course1.CoursePrint();

    Course course2("N36", "Java", 3, 5);
    Course course3("N45", "Assembly", 1, 5);
    Course course4("N56", "Algorithms", 2, 5);
    Course course5("P34", "Networks I", 3);
    Course course6("P35", "Networks II", 4);
    //float grade1=1.1;

    testp=&course2;


    testF4 += course2;
    testF4.AddDilCourses(course3);
    testF4.AddDilCourses(course4);

    //testF4 += testp;
    //testF4.printDilCourses();
    cout << testF4;

    //testF4 += course4;

    //testF4.Print();
    testF4.writeFoititis();
    /*
    testF4.writeFoititis();
    testF4.AddCompCoursesGrade(grade1);
    testF4.AddCompCoursesGrade(5.24);
    */

    course5.writeCourse();

    if (testF3 == testF4) {
        //cout << "Οι φοιτητές δεν έχουν ίδιο εξάμηνο σπουδών." << endl;
        cout << "Οι φοιτητές έχουν ίδιο εξάμηνο σπουδών." << endl;
    }
    else {
        //cout << "Οι φοιτητές έχουν ίδιο εξάμηνο σπουδών." << endl;
        cout << "Οι φοιτητές δεν έχουν ίδιο εξάμηνο σπουδών." << endl;
    }
}