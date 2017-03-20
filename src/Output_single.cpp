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
    cout << "output going in: " << endl;
    string file = rhs->filename;

    FILE *test = fopen(file.c_str(), "w"); //w to empty file and recreate it, a to append
    out = fileno(test);
    int pid;

    bool success = false;

    pid=fork();

    if (pid == 0) {
        dup2(out,STDOUT_FILENO); //1 for output redirect, 0 for input redirect
        if(lhs->exec(3, 0)){
            success = true;
        }
        fclose(test);
        exit (0);
    }

  return success;
}
