#ifndef _TEST_H_
#define _TEST_H_
#include "Base.h"

using namespace std;

class Test: public Base {
    protected:
        char* path;
        char* flag;
    public:
        //Constructors
        Test(char* flag, char* path);
        Test(char* path);

        //executes the test command, returns true/false
        bool exec( );
};

#endif

