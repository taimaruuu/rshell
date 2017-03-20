#ifndef _OUTPUT_DOUBLE_H_
#define _OUTPUT_DOUBLE_H_

#include "Connector.h"

class Output_double: public Connector {
  public:

    Output_double(Base* rhs, Base* lhs);

    bool exec(int in, int out);
};
#endif
