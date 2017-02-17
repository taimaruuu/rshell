#ifndef _SEMICOLON_H_
#define _SEMICOLON_H_

using namespace std;

class Semicolon: public Connector {
    public:

        Semicolon(Base* lhs, Base* rhs);

        bool exec(string cmd);
};

#endif
