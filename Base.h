#ifndef __BASE_H__
#define __BASE_H__

using namespace std;

class Base{
public:
  //virtual exec that executes leaf/compostite node in the tree
  virtual bool exec(string cmd = " ") = 0;

}


#endif
