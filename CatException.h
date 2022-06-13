#ifndef PROJECT3_CATEXCEPTION_H
#define PROJECT3_CATEXCEPTION_H
#include <string>
#include <cstring>

using std::string;
using namespace std;

class CatException : public std::exception {
private:
    char * message;

public:

    CatException(char * messg): message(messg) {};
    const char* what() const throw ()
    {
        return this -> message;
    }

};

#endif //PROJECT3_CATEXCEPTION_H