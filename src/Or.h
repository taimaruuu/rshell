#ifndef _OR_H_
#define _OR_H_

using namespace std;

class Or: public Connector {
    public:

        Or(Base* lhs, Base* rhs);

        bool exec(string cmd);

};

#endif
