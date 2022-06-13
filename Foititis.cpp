#include "Foititis.h"
#include "CatException.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//default constructor
Foititis::Foititis(){
    cout << "Γίνεται εκκίνηση του default constructor." << endl;
    cout << "********************************" << endl;
    this -> a_m = NULL;
    //ή
    //this -> a_m = '\0';
    this -> onoma = "";
    this -> eksamino = 0;
    //this -> dil_courses = NULL;
    //this -> epi_courses = NULL;
}

//constructor με δύο παραμέτρους
Foititis::Foititis(char *a_m, string onoma){
    cout << "Γίνεται εκκίνηση του constructor με 2 παραμέτρους." << endl;
    cout << "********************************" << endl;
    this -> a_m = a_m;
    this -> onoma = onoma;
    this -> eksamino = 1;
}

//constructor με τρεις παραμέτρους
Foititis::Foititis(char *a_m, string onoma, unsigned int eksamino){
    cout << "Γίνεται εκκίνηση του constructor με 3 παραμέτρους." << endl;
    cout << "********************************" << endl;
    this -> a_m = a_m;
    this -> onoma = onoma;
    this -> eksamino = eksamino;
}

//ακολουθεί η υλοποίηση του copy constructor
Foititis::Foititis(const Foititis &foit)
{
    cout << "Γίνεται εκκίνηση του Foititis copy constructor." << endl;
    int size = strlen(foit.a_m);
    this -> a_m = new char[size];
    memcpy(this -> a_m, foit.a_m, strlen(foit.a_m));
    this -> onoma = foit.onoma;
    this -> eksamino = foit.eksamino;
}

//υλοποίηση των set
void Foititis::set_a_m(char *a_m){
    this -> a_m = a_m;
}

void Foititis::set_onoma(string onoma){
    this -> onoma = onoma;
}

void Foititis::set_eksamino(unsigned int eksamino){
    this -> eksamino = eksamino;
}

//υλοποίηση των get
char *Foititis::get_a_m(){
    return a_m;
}

string Foititis::get_onoma(){
    return onoma;
}

unsigned int Foititis::get_eksamino(){
    return eksamino;
}

//print function
void Foititis::Print () {
    cout << "*******************************************************" << endl;
    cout << "Αριθμός μητρώου: " << this -> a_m << endl;
    cout << "Ονοματεπώνυμο: " << this -> onoma << endl;
    cout << "Εξάμηνο: " << this -> eksamino << endl;
    cout << "Τα δηλωμένα μαθήματα του Φοιτητή: " << endl;
    this -> printDilCourses();
    cout << "*******************************************************" << endl;
}

//υλοποίηση μεθόδου για εγγραφή σε αρχείο
void Foititis::writeFoititis() {
    ofstream fileFoititis;
    //οτιδήποτε γράφουμε προστίθενται στο τέλος του αρχείου
    fileFoititis.open("Foititologio.txt", ios::app);

    if (!fileFoititis.is_open()) {
        cout << "\n Δυστυχώς κάτι πήγε λάθος... \n" << endl;
    }

    fileFoititis << this->a_m << " " << this->onoma << " " << this->eksamino << endl;
    /*
    for(int i=0; i < this -> dilCourses.size();i++)
    {
        Course cor = this -> dilCourses[i];
        fileFoititis << "\t" << cor.get_course_code() << " " << cor.get_course_sem() << " " << cor.get_course_verb() << " " << (float)cor.get_course_grade() << endl;
    }
    fileFoititis << "************************************" << endl << endl;
    */
    cout << "Το αρχείο Φοιτητολογίου δημιουργήθηκε επιτυχώς." << endl;
    cout << "Μόλις έγινε εγγραφή νεόυ φοιτητή στο Φοιτητολόγιο." << endl;

    fileFoititis.close();
}

//υλοποίηση μεθόδου που κάνει το εξάμηνο +1
void Foititis::increaseEksamino(Foititis &foit) {
    this -> eksamino = foit.eksamino + 1;
    cout << "Το εξάμηνο του φοιτητή αυξήθηκε κατά ένα." << endl;
}

Foititis::~Foititis() {
    cout << "Εκκίνηση του Destructor." << endl;
}

void Foititis::operator+=(Course crs){
    if(dilCourses.size() > 3){
        throw CatException("Αυτό πήγε λάθος");
    }
    this ->AddDilCourses(crs);
}

bool Foititis::operator== (Foititis &F) {
    if (this->eksamino != F.eksamino) {
        return false;
    }
    return true;
}

bool Foititis::operator!= (Foititis &F)  {
    if (this->eksamino == F.eksamino) {
        return 0;
    }
    return 1;
}

bool Foititis::operator< (Foititis &F) {
    unsigned int e1 = this->eksamino;
    unsigned int e2 = F.eksamino;
    return (e1 < e2) ? true :false;
}

bool Foititis::operator> (Foititis &F) {
    unsigned int e1 = this->eksamino;
    unsigned int e2 = F.eksamino;
    return (e1 > e2) ? true :false;
}

bool Foititis::operator<= (Foititis &F) {
    unsigned int e1 = this->eksamino;
    unsigned int e2 = F.eksamino;
    return (e1 <= e2) ? true :false;
}

bool Foititis::operator>= (Foititis &F) {
    unsigned int e1 = this->eksamino;
    unsigned int e2 = F.eksamino;
    return (e1 >= e2) ? true :false;
}

void Foititis::AddDilCourses(Course course) {
    this -> dilCourses.size();

    if(course.get_course_code() != "") {
        this -> dilCourses.push_back(course);
        //this -> CompCoursesGrade.push_back(course);
        if( course.get_course_grade() >= 5.0)
        {
            this -> AddCompCoursesGrade(course);
            //this -> CompCoursesGrade.push_back(course);
        }
    }

}

void Foititis::AddCompCoursesGrade(Course course){
    this -> CompCoursesGrade.push_back(course);
}

void Foititis::printDilCourses() {
    unsigned int size = this -> dilCourses.size();
    cout << "********************************" << endl;
    cout << "Mαθήματα: " << endl;
    /*for(int i=0 ; i<size ; i++){
        ////////////////////////////////////
        this -> dilCourses[i]->CoursePrint();
        ///////////////////////////////////
    }*/
    for (const Course& i : this -> dilCourses) {
        i.CoursePrint();
    }
}

float Foititis::calcCompletedCoursesGrade() const{
    unsigned int size = this -> CompCoursesGrade.size();
    float sum=0.00;
    float average_grade = 0.00;
    //cout << "********************************" << endl;
    if(size != 0) {
        /*for (int i = 0; i < size; i++) {
            sum = sum + this->CompCoursesGrade[i].get_course_grade();
        }*/

        for (const Course& i : this -> CompCoursesGrade) {
            sum = sum + i.get_course_grade();
        }
        average_grade = sum / size;
    }
    return average_grade;
}