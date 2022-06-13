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
#include "CatException.h"
#include <stdexcept>


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
    Course course2;
    Course course3;
    Course course4;
    Course course5;
    Course course6;
    course6.writeCourse();
    //course1.CoursePrint();
    try {
        course2 = Course("N36", "Java", 3, 5);
        course3 = Course("N45", "Assembly", 1, 5);
        course4 = Course("N56", "Algorithms", 2, 5);
        course5 = Course("P34", "Networks I", 3, 1);
        course6 = Course("P35", "Networks II", 4, 4.5);

        testF4 += course2;
        testF4 += course3;
        testF4 += course4;
        testF4 += course5;
        testF4 += course6;
    }
    catch (const invalid_argument& e)
    {
        cout << "O giorgos paly his bird!!!" << endl;
    }
    catch (CatException &e) {
        cout << e.what()<< endl;
    }
    //float grade1=1.1;

    testp=&course2;



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