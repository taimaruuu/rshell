#ifndef _INPUT_H_
#define _INPUT_H_

#include "Connector.h"

class Input: public Connector {
  public:

    Input(Base* rhs, Base* lhs);

    bool exec(int in, int out);
};
#endif
