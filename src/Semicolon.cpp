#include "Semicolon.h"

Semicolon::Semicolon(Base* lhs, Base* rhs): Connector(lhs, rhs) {}

//execute lhs then rhs regardless of wheter the command runs or not
bool Semicolon::exec( ){
    lhs->exec();
    if(rhs->exec()) {
        return true;
    }
    else {
        return false;
    }
}
