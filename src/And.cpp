#include "And.h"
#include <iostream>

using namespace std;
And::And(Base* lhs, Base* rhs): Connector(lhs,rhs) {}

// Executes right command only if the left command successfully executes.
bool And::exec(int in, int out) {
    // cout << "and i'm going in\n";
    if(lhs->exec(in, out)) {
        if(rhs->exec(in, out)) {
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
