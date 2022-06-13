#ifndef PROJECT3_EXCEPTION_H
#define PROJECT3_EXCEPTION_H
#include <string>

using std::string;
using namespace std;

class Exception : public std::exception {
private:


public:
    int ex_code;
    string ex_descr;
    //δήλωση όλων των constructors
    Exception();
    Exception(int ex_code, string ex_descr);

    //όλες οι set
    void set_ex_code(int) ;
    void set_ex_descr(string) ;

    //όλες οι get
    int get_ex_code();
    string get_ex_descr();

    const char* what() const throw ()
    {
        string result = to_string(this -> ex_code) + " " + this->ex_descr;

        return
    }

};

#endif //PROJECT3_EXCEPTION_H