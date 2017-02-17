#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

using namespace std;

class Connector: public Base{
    protected:

        Base* lhs; //lefthand operand
        Base* rhs; //righthand operand

    public:

        //virtual exec that executes leaf/compostite node in the tree
        bool exec(string cmd);
    
        //function to get string from user
        string get_string();

        //constructors for connector class
        Connector(Base* lhs, Base* rhs);
};


#endif
