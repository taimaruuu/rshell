#ifndef _AND_H_
#define _AND_H_

using namespace std;

class And: public Connector {
    public:

        And(Base* lhs, Base* rhs);

        bool exec(string cmd);
};

#endif
