#ifndef __COMMAND_CPP__
#define __COMMAND_CPP__

#include "Command.h"

    // constructor
    Command::Command(char* command) {
        this->cmd = command;
    }

    Command::Command() {}

    //exec that executes leaf/compostite node in the tree
    bool Command::exec(string cmd) {
        //set the args at 0 (so the first one) = to this->command
        args[0] = this->command;
        
        bool ret_status; //return value to see if the function executed or not

        pid_t pid = fork(); //creates child process using fork()

        if(pid == -1) { //forking failed use perror
            perror("fork");
        }
        else if (pid == 0) { // pid == 0 is child process

        }


    }
        
    //gets the string/char* of the cmd
    string Command::get_string() {
        return cmd;
    }


#endif
