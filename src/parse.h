#ifndef __PARSE_H__
#define __PARSE_H__

#include <string>
#include "Or.h"
#include "And.h"
#include "Semicolon.h"

#include<boost/tokenizer.hpp>



typedef boost::tokenizer<boost::char_separator<char> > tokenizer;


Base* tokeParse(tokenizer &token, tokenizer::iterator &it){
  //typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
  it++;
  vector<string> arglist;
  vector<string> cast(1);
  Base *ret = 0;
  bool commandOnly = true;
    int i = 0;
    while (it != token.end()) {
      if(it != token.end()){
        cast.at(0) = *it;
      }
      if(cast.at(0) == "#"){
        break;
      }
      if(cast.at(0) == "&"){
        commandOnly = false;
        it++;
        ret = new And(new Command(arglist),tokeParse(token,it));
      }
      if(cast.at(0) == "|"){
        commandOnly = false;
        it++;
        ret = new Or(new Command(arglist),tokeParse(token,it));
      }
      if(cast.at(0) == ";"){

        commandOnly = false;
        return new Semicolon(new Command(arglist),tokeParse(token,it));
      }
      arglist.push_back(cast.at(0));
      if (it != token.end()) {
        it++;
      }
      i++;

    }

    if (commandOnly) {
      return new Command(arglist);
    }
    return ret;
}


Base* parse(string &input){
  typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
  vector<string> arglist;
  vector<string> cast(1);
  Base *ret = 0;
  bool commandOnly = true;
  tokenizer token(input);
  tokenizer::iterator it = token.begin();
    int i = 0;
    while (it != token.end()) {
      if(it != token.end()){
        cast.at(0) = *it;
      }
      if(cast.at(0) == "#"){
        break;
      }
      if(cast.at(0) == "&"){
        commandOnly = false;
        it++;
        return new And(new Command(arglist),tokeParse(token,it));
      }
      if(cast.at(0) == "|"){
        commandOnly = false;
        it++;
        return new Or(new Command(arglist),tokeParse(token,it));
      }
      if(cast.at(0) == ";"){
        commandOnly = false;
        return new Semicolon(new Command(arglist),tokeParse(token,it));
      }
      arglist.push_back(cast.at(0));
      it++;
      i++;
    }

    if (commandOnly) {
      return new Command(arglist);
    }
    return ret;
}






#endif
