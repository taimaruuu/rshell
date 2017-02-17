#ifndef __BASE_H__
#define __BASE_H__

#include <string>
using namespace std;

class Base{
    public:

        //pure virtual exec that executes leaf/compostite node in the tree
        virtual bool exec() = 0;

        //pure virtual function to get the string that the user enters
        virtual string get_string() = 0;

};


#endif
