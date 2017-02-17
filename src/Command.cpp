#ifndef __COMMAND_CPP__
#define __COMMAND_CPP__

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#include "Command.h"

    // constructor
    Command::Command(char* command) {
        this->cmd = command;
    }

    Command::Command() {}

    //exec that executes leaf/compostite node in the tree
    bool Command::exec() {
        //set the args at 0 (so the first one) = to this->command
        char *args[420];
        args[419] = NULL;
        args[0] = this->cmd;

        //return value to see if the function executed or not
        bool ret_status = true;

        pid_t pid = fork(); //creates child process using fork()

        if(pid == -1) { //forking failed use perror
            perror("fork failed");
        }
        if (pid == 0) { // pid == 0 is child process
          if(execvp(args[0], args) == -1){
            ret_status = false;
            perror("execvp failed");
            exit(1);
          }
        }
        if(pid > 0){ // pid > 0 is parent process
          int status;     // used for exit status value of child
          int option = 0;  // not needed
          if (waitpid(pid, &status, option) == -1){
            perror("wait failed");
          }
          if(WEXITSTATUS(status) != 0) {
            ret_status = false;
          }
        }

        return ret_status;
    }

    //gets the string/char* of the cmd
    string Command::get_string() {
        return cmd;
    }



#endif
