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
  if(it != token.end()){
    it++;
  }

  vector<string> arglist;
  vector<string> cast(1);
  vector<string> tcast(1);
  bool commandOnly = true;
  bool flagPresent = false;


    while (it != token.end()) {

      if(it != token.end()){
        cast.at(0) = *it;
      }
      if(cast.at(0) == "-"){
        string tempFlag = cast.at(0);
        it++;
        cast.at(0) = *it;
        string gg = cast.at(0);
        tempFlag = tempFlag + gg;
        arglist.push_back(tempFlag);
        // return new Command(arglist);
        flagPresent = true;
      }
      if(cast.at(0) == "#"){
        break;
      }
      if (boost::next(it) != token.end()){
        tcast.at(0) = *boost::next(it);
      }
      if(tcast.at(0) == "&"){
        commandOnly = false;
        arglist.push_back(cast.at(0));
        //it;
        return new Command(arglist);
        // it++;
        // ret = new And(new Command(arglist),tokeParse(token,it));
      }
      if(tcast.at(0) == "|"){
        commandOnly = false;
        arglist.push_back(cast.at(0));

        //it;
        return new Command(arglist);
        // ret = new Or(new Command(arglist),tokeParse(token,it));
      }
      if(tcast.at(0) == ";"){


        commandOnly = false;
        arglist.push_back(cast.at(0));
        //it;
        return new Command(arglist);
      }
      // if(cast.at(0) == "[")
      if(flagPresent == false){

        arglist.push_back(cast.at(0));
      }

      if (it != token.end()) {
        it++;
      }


    }

    // if (commandOnly) {
    //   return new Command(arglist);
    // }
    cout << "IS THIS THE ERROR" << endl;

    return new Command(arglist);;
}


Base* parse(string &input){
  typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
  Base* head = 0;
  // boost::char_separator<char> sep("\"");
  vector<string> arglist;
  vector<string> cast(1);
  // Base *ret = 0;
  bool firstCommand = true;
  bool flagPresent = false;
  bool commandOnly = true;
  tokenizer token(input);
  tokenizer::iterator it = token.begin();

  // for (; it2 != token.end(); it2++) {
  //   cast.at(0) = *it2;
  //   cout << cast.at(0) << endl;
  // }

    int i = 0;
    while (it != token.end()) {
      if(it != token.end()){
        cast.at(0) = *it;
      }
      if(cast.at(0) == "-"){
        string tempFlag = cast.at(0);
        it++;
        cast.at(0) = *it;
        string gg = cast.at(0);
        tempFlag = tempFlag + gg;

        arglist.push_back(tempFlag);

        // return new Command(arglist);
        flagPresent = true;
      }

      if(cast.at(0) == "#"){
        break;
      }
      if(cast.at(0) == "&"){
        commandOnly = false;
        it++;
        if (firstCommand) {
          head = new Command(arglist);
          firstCommand = false;
        }
        Base* temp = new And(head, tokeParse(token,it));
        head = temp;
      }
      if(cast.at(0) == "|"){
        commandOnly = false;
        it++;
        if (firstCommand) {
          head = new Command(arglist);
          firstCommand = false;
        }
        Base* temp = new Or(head, tokeParse(token,it));
        head = temp;
      }
      if(cast.at(0) == ";"){
        commandOnly = false;
        // it++;
        if (firstCommand) {
          head = new Command(arglist);
          firstCommand = false;
        }
        if (boost::next(it) == token.end()) {
          return head;
        }
        else {
          Base* temp = new Semicolon(head, tokeParse(token,it));
          head = temp;
        }
      }
      if(flagPresent == false){
        arglist.push_back(cast.at(0));
      }
      if (it != token.end()) {
          it++;
      }

      i++;
    }

    if (commandOnly) {
      head = new Command(arglist);
    }
    return head;
}

bool preParse(string &input){
  int open = 0, close =0;

  for(unsigned i = 0; i < input.size(); i++){
    // removes ' and "
    if(input[i] == '\"' || input[i] == '\'' ){
      input.erase(input.begin()+i);
    }

    // checks parenthesis parity
    if (input[i] == '(') {
      open++;
    }
    if (input[i] == ')') {
      close++;
    }
  }
  if (close != open) {
    cout <<  "received unpaired parenthesis\n";
    return false;
  }
  return true;
}







#endif
