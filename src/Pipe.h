#ifndef _PIPE_H_
#define _PIPE_H_

#include "Connector.h"

class Pipe: public Connector {
  public:

    Pipe(Base* rhs, Base* lhs);

    bool exec(int in, int out);
};
#endif
