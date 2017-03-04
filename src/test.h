#ifndef _TEST_H_
#define _TEST_H_
#include "Base.h"

using namespace std;

class Test: public Base {
    protected:
        string path;
        string flag;
    public:
        //Constructors
        Test(string flag, string path);
        Test(string path);

        //executes the test command, returns true/false
        bool exec( );
};

#endif
