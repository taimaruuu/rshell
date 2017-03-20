#ifndef _OUTPUT_SINGLE_H_
#define _OUTPUT_SINGLE_H_

#include "Connector.h"

class Output_single: public Connector {
  public:

    Output_single(Base* rhs, Base* lhs);

    bool exec(int in, int out);
};
#endif
