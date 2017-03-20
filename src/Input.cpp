#include "Connector.h"
#include "Input.h"

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
    string file = rhs->argsList.at(0);
    in = open(file.c_str(),O_RDONLY);

    return lhs->exec(in,1);
}
