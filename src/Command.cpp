#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


#include "Command.h"

    // constructor

    Command::Command(vector<string> argsList): argsList(argsList) {}

    // int cmdLength(char* command){
    //   cout << strlen(command) << endl;
    //   return strlen(command);
    // }

    //exec that executes leaf/compostite node in the tree
    bool Command::exec(int in, int out) {

        if(argsList.at(0) == "exit"){
          exit(0);
        }
        //set the args at 0 (so the first one) = to this->command
        char *args[420];
        args[0] = (char*)argsList.at(0).c_str();

        //args[cmdLength(this->cmd) + 1] = "\0";
        vector<string> tempargs;
        string temp = " -";
        tempargs.push_back(temp);
        unsigned x;
        for(x = 1; x < argsList.size(); x++) {
          //cout << "temp: " << argsList.at(x) << endl;
          args[x] = (char*)argsList.at(x).c_str();
        }
        args[x] = 0;



        //return value to see if the function executed or not
        bool ret_status = true;

        pid_t pid = fork(); //creates child process using fork()

        if(pid == -1) { //forking failed use perror
            perror("fork failed");
        }
        if (pid == 0) { // pid == 0 is child process
          if(execvp(args[0], args) == -1) {
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
