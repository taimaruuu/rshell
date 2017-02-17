include "And.h"

And::And(Base* lhs, Base* rhs): Connector(lhs,rhs) {}

// wouldn't "rhs/lhs->exec(cmd)" end up doing the same command?
// Executes left command only if the right command successfully executes.
bool And::exec(string cmd) {
    if(rhs->exec(cmd)) {
        if(lhs->exec(cmd)) {
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

