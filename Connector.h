#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

using namespace std;

class Connector: public Base{
  protected:
    Base* lhs; //lefthand operand
    Base* rhs; //righthand operand

  public:
    //virtual exec that executes leaf/compostite node in the tree
    void exec(string cmd = " ") = 0;

};


#endif
