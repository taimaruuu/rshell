#include "Semicolon.h"

Semicolon::Semicolon(Base* lhs, Base* rhs): Connector(lhs, rhs) {}

//execute lhs then rhs regardless of whether the command runs or not
bool Semicolon::exec(int in, int out ){
    lhs->exec(in, out);
    if(rhs->exec(in, out)) {
        return true;
    }
    else {
        return false;
    }
}
