#ifndef _EXIT_H_
#define _EXIT_H_

#include "Exit.h"
#include "Command.cpp"

Exit::Exit() {}

bool Exit::exec() {
    exit(0);
}

string Exit::get_string() {
    return "Exit";
}


#endif
