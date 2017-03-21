#include "Output_single.h"
using namespace std;

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>
#include <string>

Output_single::Output_single(Base* lhs, Base* rhs): Connector(lhs,rhs) {}


//redirects input from the standard in to the input given on the command line
bool Output_single::exec(int in, int out) {
    bool success = false;
    int pid = fork();
    string file = rhs->filename;
    FILE *test = fopen(file.c_str(), "w"); //w to empty file and recreate it
    out = fileno(test);

    if (pid == 0) {
        if(dup2(out,STDOUT_FILENO) == -1) {
          perror("dup2 single output failed");
          return false;
        }
        if(lhs->exec(3, 0)){
            success = true;
        }
        fclose(test);
        exit (0);
    }

  return success;
}