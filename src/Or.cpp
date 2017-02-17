#include "Or.h"

Or::Or(Base* lhs, Base* rhs): Connector(lhs,rhs) {}

//Executes left command only if the right command fails.
bool Or::exec(string cmd) {
    if(rhs->exec(cmd)) {
        return false;
    }
    else {
        if(lhs->exec(cmd)) {
            return true;
        }
        else {
            return false;
        }
    }
}
