#include "Or.h"

Or::Or(Base* lhs, Base* rhs): Connector(lhs,rhs) {}

//Executes right command only if the left command fails.
bool Or::exec(int in, int out ){
    if(lhs->exec(in, out)) {
        return true;
    }
    else {
        if(rhs->exec(in, out)) {
            return true;
        }
        else {
            return false;
        }
    }
}
