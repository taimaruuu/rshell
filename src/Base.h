#ifndef __BASE_H__
#define __BASE_H__

#include <string>
#include <vector>
using namespace std;

class Base{


    public:

        //pure virtual exec that executes leaf/compostite node in the tree
        virtual bool exec(int in, int out) = 0;
        string filename;

};


#endif
