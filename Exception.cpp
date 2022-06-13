//Exception.cpp

#include "Exception.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>

using namespace std;

Exception::Exception() {
    this -> ex_code = 0;
    this ->ex_descr = "";
}

Exception::Exception(int ex_code, string ex_descr) {
    this -> ex_code = ex_code;
    this ->ex_descr = ex_descr;
}

//υλοποίηση των set
void Exception::set_ex_code(int ex_code) {
    this -> ex_code = ex_code;
}

void Exception::set_ex_descr(string ex_descr) {
    this -> ex_descr = ex_descr;
}



//υλοποίηση των get
int Exception::get_ex_code() {
    return this -> ex_code;
}

string Exception::get_ex_descr() {
    return this -> ex_descr;
}

