#ifndef __COMMAND_H__
#define __COMMAND_H__


class Command: public Base{
  protected:
    vector<string> cmds; //vector of commands you want to implement 

  public:
    //exec that executes leaf/compostite node in the tree
     void exec(string cmd = " ");

};


#endif
