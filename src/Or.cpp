#include "Or.h"

Or::Or(Base* lhs, Base* rhs): Connector(lhs,rhs) {}

//Executes left command only if the right command fails.
bool Or::exec( ){
    if(rhs->exec( )) {
        return false;
    }
    else {
        if(lhs->exec( )) {
            return true;
        }
        else {
            return false;
        }
    }
}
