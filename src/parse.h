#ifndef __PARSE_H__
#define __PARSE_H__

#include <string>
#include "Or.h"
#include "And.h"

#include<boost/tokenizer.hpp>

typedef boost::tokenizer<boost::char_separator<char> > tokenizer;



Base* tokeParse(tokenizer &token, tokenizer::iterator &it){
  vector<string> arglist;
  vector<string> cast(1);
  Base *ret = 0;
  bool commandOnly = true;
    int i = 0;
    while (it != token.end()) {
      cast.at(0) = *it;
      if(cast.at(0) == "#"){
        break;
      }
      if(cast.at(0) == "&"){
        commandOnly = false;
        ret = new And(new Command(arglist),tokeParse(token,it));
      }
      if(cast.at(0) == "|"){
        commandOnly = false;
        ret = new Or(new Command(arglist),tokeParse(token,it));
      }
      if(cast.at(0) == ";"){
        commandOnly = false;
        ret = new Command(arglist);
      }
      arglist.push_back(cast.at(0));
      cout << "argslist: " << arglist.at(i) << " ";
      it++;
      i++;
    }

    if (commandOnly) {
      ret = new Command(arglist);
    }
    return ret;
}


Base* parse(string &input){
  vector<string> arglist;
  vector<string> cast(1);
  Base *ret = 0;
  bool commandOnly = true;
  tokenizer token(input);
  tokenizer::iterator it = token.begin();
    int i = 0;
    while (it != token.end()) {
      cast.at(0) = *it;
      if(cast.at(0) == "#"){
        break;
      }
      if(cast.at(0) == "&"){
        commandOnly = false;
        ret = new And(new Command(arglist),tokeParse(token,it));
      }
      if(cast.at(0) == "|"){
        commandOnly = false;
        ret = new Or(new Command(arglist),tokeParse(token,it));
      }
      if(cast.at(0) == ";"){
        commandOnly = false;
        ret = new Command(arglist);
      }
      arglist.push_back(cast.at(0));
      cout << "argslist: " << arglist.at(i) << " ";
      it++;
      i++;
    }

    if (commandOnly) {
      ret = new Command(arglist);
    }
    return ret;
}






#endif
