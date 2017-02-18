#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__
#include "Base.h"
class Connector: public Base{
    protected:

        Base* lhs; //lefthand operand
        Base* rhs; //righthand operand

    public:

        //virtual exec that executes leaf/compostite node in the tree
        virtual bool exec( ) = 0;


        //constructors for connector class
        Connector(Base* lhs, Base* rhs);
};

#endif
