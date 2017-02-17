#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "Base.h"
#include <vector>

class Command: public Base{
    protected:

        char* cmd; //array of command you want to implement 

    public:
    
        // constructor
        Command(char* command);
        Command();

        //exec that executes leaf/compostite node in the tree
        bool exec(string cmd);
        
        //gets the string/char* of the cmd
        string get_string();

};


#endif
