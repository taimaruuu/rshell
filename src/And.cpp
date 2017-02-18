#include "And.h"

And::And(Base* lhs, Base* rhs): Connector(lhs,rhs) {}

// wouldn't "rhs/lhs->exec(cmd)" end up doing the same command?
// Executes left command only if the right command successfully executes.
bool And::exec() {
    if(rhs->exec()) {
        if(lhs->exec()) {
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
