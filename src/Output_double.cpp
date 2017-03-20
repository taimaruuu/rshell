#include "Output_double.h"
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

Output_double::Output_double(Base* lhs, Base* rhs): Connector(lhs,rhs) {}


//redirects input from the standard in to the input given on the command line
bool Output_double::exec(int in, int out) {
    bool success = false;
    int pid = fork();
    string file = rhs->filename;
    FILE *test = fopen(file.c_str(), "a"); //a to append to file or to make it
    out = fileno(test);

    if (pid == 0) {
        if(dup2(out,STDOUT_FILENO) == -1) {
          perror("dup2 double ouptput failed");
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
