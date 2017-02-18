#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "Base.h"
#include <vector>

class Command: public Base{
    protected:

        vector<string> argsList; //array of command you want to implement

    public:

        // constructor
        Command(vector<string> argsList);
        Command();

        //exec that executes leaf/compostite node in the tree
        bool exec( );

};


#endif
