#include "Input.h"
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

Input::Input(Base* lhs, Base* rhs): Connector(lhs,rhs) {}


//redirects input from the standard in to the input given on the command line
bool Input::exec(int in, int out) {
    cout << "input going in: " << endl;
    string file = rhs->filename;

    in = open(file.c_str(), O_RDONLY, 0);
    int stdin_copy = dup(0);

    bool success = false;
    close(0);
    dup2(in, STDIN_FILENO);
    close(in);

    if(lhs->exec(1,0)){
      success = true;
    }
    
    dup2(stdin_copy, STDIN_FILENO);
    close(stdin_copy);

    // in = open(file.c_str(), O_RDONLY);
    // cout << "IN" << in << endl;
    // return lhs->exec(in,1);
    return success;
}
