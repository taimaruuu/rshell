#ifndef _OR_H_
#define _OR_H_
#include "Connector.h"

class Or: public Connector {
    public:

        Or(Base* lhs, Base* rhs);

        bool exec( );
};

#endif
