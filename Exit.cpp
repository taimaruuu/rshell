#include "Exit.h"
#include <stdlib.h>

Exit::Exit() {}

bool Exit::exec() {
    return exit(0);
}
