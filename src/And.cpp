#include "And.h"

And::And(Base* lhs, Base* rhs): Connector(lhs,rhs) {}

// Executes right command only if the left command successfully executes.
bool And::exec() {
    if(lhs->exec()) {
        if(rhs->exec()) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}
