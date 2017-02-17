#include "Or.h"

Or::Or(Base* lhs, Base* rhs): Connector(lhs,rhs) {}

//Executes right command only if the left command fails.
bool Or::exec(string cmd) {
    if(lhs->exec(cmd)) {
        return false;
    }
    else {
        if(rhs->exec(cmd)) {
            return true;
        }
        else {
            return false;
        }
    }
}
