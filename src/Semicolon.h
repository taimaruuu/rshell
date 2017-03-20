#ifndef _SEMICOLON_H_
#define _SEMICOLON_H_

#include "Connector.h"

class Semicolon: public Connector {
    public:

        Semicolon(Base* lhs, Base* rhs);

        bool exec(int in, int out );
};

#endif
