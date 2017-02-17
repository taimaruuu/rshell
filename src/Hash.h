#ifndef _HASH_H_
#define _HASH_H_
//include files

using namespace std;

class Hash: public Connector {
    public:

        Hash(Base* lhs, Base* rhs);

        bool exec(string cmd);
};

#endif
