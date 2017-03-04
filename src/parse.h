#ifndef __PARSE_H__
#define __PARSE_H__

#include <string>
#include "Or.h"
#include "And.h"
#include "Semicolon.h"
#include "Test.h"

#include<boost/tokenizer.hpp>

typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
Base* precedenceParse(tokenizer &token, tokenizer::iterator &it);
Base* tokeParse(tokenizer &token, tokenizer::iterator &it);
Base* parse(string &input);

Base* precedenceParse(tokenizer &token, tokenizer::iterator &it){
  it++;
  //typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
  Base* head = 0;
  string temp = "-";
  string tpath = "";

  vector<string> arglist;
  vector<string> cast(1);

  bool firstCommand = true;
  bool flagPresent = false;
  bool commandOnly = true;
  while (it != token.end()) {
      if(it != token.end()){
        cast.at(0) = *it;
        // cout << "CAST PRECEDEC" << cast.at(0) << endl;
      }



      if(cast.at(0) == "("){
        Base* precedence = precedenceParse(token, it);
        head = precedence;
      }

      if(cast.at(0) == ")"){
        // cout << "ENTERS CLOSE" << endl;
        // for (unsigned i = 0; i < arglist.size(); i++) {
        //   cout << arglist.at(i) << endl;
        // }
        return new Command(arglist);
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
          // cout << "precedence iter\n";
          it++;
      }
    }
    if (commandOnly) {
      head = new Command(arglist);
    }
    return head;
  }

Base* tokeParse(tokenizer &token, tokenizer::iterator &it){
  if(it != token.end()){
    it++;
  }

  vector<string> arglist;
  vector<string> cast(1);
  vector<string> tcast(1);
  bool commandOnly = true;
  bool flagPresent = false;
  string temp = "";
  string tpath = "";


  while (it != token.end()) {

      if(it != token.end()){
        cast.at(0) = *it;
        // cout << "CAST TOKE" << cast.at(0) << endl;

      }

      if(cast.at(0) == ")"){
        return new Command(arglist);
      }

      if(cast.at(0) == "("){
        Base* precedence = precedenceParse(token, it);
        return precedence;
      }
      if(cast.at(0) == "-"){
        string tempFlag = cast.at(0);
        it++;
        cast.at(0) = *it;
        string gg = cast.at(0);
        tempFlag = tempFlag + gg;
        arglist.push_back(tempFlag);
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
        return new Command(arglist);
      }
      if(tcast.at(0) == "|"){
        commandOnly = false;
        arglist.push_back(cast.at(0));

        return new Command(arglist);

      }
      if(tcast.at(0) == ";"){


        commandOnly = false;
        arglist.push_back(cast.at(0));
        //it;
        return new Command(arglist);
      }
      // if(cast.at(0) == "[")
      //for test
      if(cast.at(0) == "[" || cast.at(0) == "test"){
     	//arglist.push_back(cast.at(0));
     	it++;
     	cast.at(0) = *it;
     	//look for flag
     	if(cast.at(0).at(0) == '-'){
     	    it++;
     	    temp += *it;
     	    //get whole file path if exists
     	    it++;
     	    while(it != token.end()) {
     		if(*it != "]" && *it != "#" && *it != "&" && *it != "|" && *it != ";" && *it != " ") {
     		    tpath += *it;
     	        }
     		else {
     		    //return new Test(temp, tpath);
     		    break;
     		}
     		    it++;
     	    }
     	    return new Test(temp, tpath);
     	}
     	else{
     	    while(it != token.end()) {
     		if(*it != "]" && *it != "#" && *it != "&" && *it != "|" && *it != ";" && *it != " ") {
     		    tpath += *it;
     	        }

     		else {
     		    //return new Test(tpath);
     		    break;
     		}
     		    it++;
     	    }
     	    return new Test(tpath);
     	}
           }
      if(flagPresent == false){

        arglist.push_back(cast.at(0));
      }

      if (it != token.end()) {
        // cout << "toke iter\n";
        it++;
      }
    }

  return new Command(arglist);;
}

Base* parse(string &input){
  typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
  Base* head = 0;
   string temp = "-";
   string tpath = "";

  vector<string> arglist;
  vector<string> cast(1);
  bool firstCommand = true;
  bool flagPresent = false;
  bool commandOnly = true;
  bool entersPrec = false;
  tokenizer token(input);
  tokenizer::iterator it = token.begin();


  while (it != token.end()) {
      if(it != token.end()){
        cast.at(0) = *it;
        // cout << "CAST PARSE" << cast.at(0) << endl;

      }

      if(cast.at(0) == "("){
        firstCommand = false;
        Base* precedence = precedenceParse(token, it);
        head = precedence;
        entersPrec = true;
        // cast.at(0) = *it;
      }
      if(cast.at(0) == ")"){
        return new Command(arglist);
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
      if(cast.at(0) == "test" || cast.at(0) == "["){
        it++;
      	cast.at(0) = *it;
      	//look for flag
      	if(cast.at(0).at(0) == '-'){
  	      it++;
    	    temp += *it;
          it++;
  	    //get whole file path if exists
  	    while(it != token.end()) {
      		tpath += *it;
      		it++;
  	    }
	      return new Test(temp, tpath);
      }
      else{
        while(it != token.end()) {
          tpath += *it;
          it++;
        }
        return new Test(tpath);
      }
      }
      // if(cast.at(0) == "test" || cast.at(0) == "["){
      //
      //   if (firstCommand) {
      //     head = new Command(arglist);
      //     firstCommand = false;
      //   }
      //   Base* temp = new And(head, tokeParse(token,it));
      //   head = temp;
      // }
      //
      // if (cast.at(0) == "]" && it != token.end()) {
      //   it++;
      // }

      // cout << "Does this iterate?1" << endl;
      if (it != token.end() ) {
        // cout << "Does this iterate?" << endl;
          it++;
      }
    }
    if (commandOnly && !entersPrec) {
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
