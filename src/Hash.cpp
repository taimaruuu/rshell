#include "Hash.h"
//iclunde right files here

Hash::Hash(Base* lhs, Base* rhs): Connector(lhs,rhs) {}

//everything to the right of the hash is a comment
bool Hash::exec(string cmd) {
    if(lhs->exec(cmd)) {
        return true;
    }
    else {
        return false;
    }
}
