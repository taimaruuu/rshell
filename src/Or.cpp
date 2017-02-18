#include "Or.h"

Or::Or(Base* lhs, Base* rhs): Connector(lhs,rhs) {}

//Executes right command only if the left command fails.
bool Or::exec( ){
    if(lhs->exec( )) {
        return true;
    }
    else {
        if(rhs->exec( )) {
            return true;
        }
        else {
            return false;
        }
    }
}
