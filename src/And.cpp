include "And.h"

And::And(Base* lhs, Base* rhs): Connector(lhs,rhs) {}

// wouldn't "rhs/lhs->exec(cmd)" end up doing the same command?
// Executes right command only if the left command successfully executes.
bool And::exec(string cmd) {
    if(lhs->exec(cmd)) {
        if(rhs->exec(cmd)) {
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

