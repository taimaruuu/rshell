#ifndef _EXIT_H_
#define _EXIT_H_

#include "Exit.h"
#include "Command.cpp"

Exit::Exit() {}

void Exit::exec(string cmd) {
    exit(0);
}

string Exit::get_string() {
    return "Exit";
}
