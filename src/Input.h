#ifndef _INPUT_H_
#define _INPUT_H_

class Input : public Connector {
  public:
    Input(Base* rhs, Base* lhs);
    virtual bool exec(int in, int out);
};
#endif
