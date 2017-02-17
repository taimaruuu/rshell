#include "Semicolon.h"

Semicolon::Semicolon(Base* lhs, Base* rhs): Connector(lhs, rhs) {}

//execute lhs then rhs regardless of wheter the command runs or not
bool Semicolon::exec(string cmd) {
    lhs->exec(cmd);
    if(rhs->exec(cmd)) {
        return true;
    }
    else {
        return false;
    }
}
