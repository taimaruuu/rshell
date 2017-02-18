#ifndef __EXIT_CPP__
#define __EXIT_CPP__

#include "Exit.h"
#include <stdlib.h>

Exit::Exit() {}

bool Exit::exec() {
    exit(0);
}

string Exit::get_string() {
    return "Exit";
}


#endif
