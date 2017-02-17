#ifndef __EXIT_H__
#define __EXIT_H__

#include "Command.h"

class Exit: public Command {
    public:

        //constructor
        Exit();

        //execute function
        bool exec();

        string get_string();

}
