#ifndef _AND_H_
#define _AND_H_

#include "Connector.h"

class And: public Connector{
    public:

        And(Base* lhs, Base* rhs);

        bool exec(int in, int out);
};

#endif
