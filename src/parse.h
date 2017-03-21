#ifndef __PARSE_H__
#define __PARSE_H__

#include <string>
#include "Or.h"
#include "And.h"
#include "Semicolon.h"
#include "test.h"
#include "Input.h"
#include "Output_single.h"
#include "Output_double.h"
#include "Pipe.h"

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
  vector<string> arglist;
  vector<string> cast(1);
  vector<string> castNext(1);
  string filename;

  if(it != token.end()){
    cast.at(0) = *it;
    // cout << "CAST TOKE" << cast.at(0) << endl;
    if(cast.at(0) == "<"){
      // cout << "i'm also going in\n";
      it++;
      cast.at(0) = *it;
      arglist.push_back(cast.at(0));
      Base* temp = new Command(arglist);

      for( ; it != token.end(); it++ ){
        if(boost::next(it) == token.end()){
            //cout << "Enetred break" << endl;
            cast.at(0) = *it;
            filename += cast.at(0);
            break;
        }
        castNext.at(0) = *boost::next(it);
        cast.at(0) = *it;
        //cout << "cast0" << cast.at(0) << endl;

        filename += cast.at(0);
        //cout << "cast " << cast.at(0) << endl;
        if(castNext.at(0) == ">"){
          break;
        }
        if(castNext.at(0) == "<"){
          break;
        }
        if(castNext.at(0) == "|"){
          break;
        }
      }
      cast.at(0) = *it;
      //cout << "cast1" << cast.at(0) << endl;
      // cout << "Cast: " << cast.at(0) << endl;
      //cout << "file1 "<< filename << endl;
      temp->filename = filename;
      filename = "";
      // cout << "file69"<< temp->filename << endl;
      return temp;
    }
  }

  if(it != token.end()){
    cast.at(0) = *it;
    // cout << "CAST TOKE" << cast.at(0) << endl;
    if(cast.at(0) ==  ">"){
      // cout << "i'm also going in\n";
      it++;
      //cout << "Cast " << cast.at(0) << endl;`
      cast.at(0) = *it;
      //>> operator
      if (cast.at(0) == ">") {
        // cout << "going into second > check\n";
        it++;
        // cout << "is this the seg fault\n";
        cast.at(0) = *it;
        // cout << "or this\n";
        arglist.push_back(cast.at(0));
        Base* temp = new Command(arglist);
        for( ; it != token.end(); it++ ){
          if(boost::next(it) == token.end()){
              //cout << "Enetred break" << endl;
              cast.at(0) = *it;
              filename += cast.at(0);
              break;
          }
          castNext.at(0) = *boost::next(it);
          cast.at(0) = *it;
          //cout << "cast0" << cast.at(0) << endl;

          filename += cast.at(0);
          //cout << "cast " << cast.at(0) << endl;
          if(castNext.at(0) == ">"){
            break;
          }
          if(castNext.at(0) == "<"){
            break;
          }
          if(castNext.at(0) == "|"){
            break;
          }
        }
        // cout << "file1"<< cast.at(0) << endl;
        //cout << "file1"<< filename << endl;
        temp->filename = filename;
        filename = "";
        // cout << "file69"<< temp->filename << endl;
        return temp;

      }

      arglist.push_back(cast.at(0));
      Base* temp = new Command(arglist);

      for( ; it != token.end(); it++ ){
        if(boost::next(it) == token.end()){
            //cout << "Enetred break" << endl;
            cast.at(0) = *it;
            filename += cast.at(0);
            break;
        }
        castNext.at(0) = *boost::next(it);
        cast.at(0) = *it;
        //cout << "cast0" << cast.at(0) << endl;

        filename += cast.at(0);
        //cout << "cast " << cast.at(0) << endl;
        if(castNext.at(0) == ">"){
          break;
        }
        if(castNext.at(0) == "<"){
          break;
        }
        if(castNext.at(0) == "|"){
          break;
        }
      }
      // cout << "file1"<< cast.at(0) << endl;
      //cout << "file1"<< filename << endl;
      temp->filename = filename;
      filename = "";
      // cout << "file69"<< temp->filename << endl;
      return temp;
    }
  }
  if(it != token.end()){
    cast.at(0) = *it;
    // cout << "CAST TOKE" << cast.at(0) << endl;
    if(cast.at(0) == "|"){
      // cout << "i'm also going in\n";
      it++;
      cast.at(0) = *it;
      if(cast.at(0) == "tr"){
        for( ; it != token.end(); it++ ){
          if(boost::next(it) == token.end()){
              //cout << "Enetred break" << endl;
              cast.at(0) = *it;
              // cout << "CAAUDJKFHFF _END" << cast.at(0) << endl;
              filename += cast.at(0);
              //filename += " ";
              break;
          }
          castNext.at(0) = *boost::next(it);
          cast.at(0) = *it;
          //cout << "cast0" << cast.at(0) << endl;
          // cout << "CAAUDJKFHFF" << cast.at(0) << endl;
          filename += cast.at(0);
          if(castNext.at(0) != "-" && cast.at(0) != "-"){
            filename += " ";
          }
          //cout << "cast " << cast.at(0) << endl;
          if(castNext.at(0) == ">"){
            break;
          }
          if(castNext.at(0) == "<"){
            break;
          }
          if(castNext.at(0) == "|"){
            break;
          }
        }
        string tempList;
        for(unsigned i = 0; i < filename.size(); i++){
          if(filename.at(i) != ' '){
            tempList += filename.at(i);
          }
          else{
            arglist.push_back(tempList);
            tempList = "";
          }
        }
        // cout << "File NAME " << filename << endl;
        //arglist.push_back(filename);
        //trPresent = true;
      }
      else if(cast.at(0) == "tee"){
        arglist.push_back(cast.at(0));
        it++;
        for( ; it != token.end(); it++ ){
          if(boost::next(it) == token.end()){
              //cout << "Enetred break" << endl;
              cast.at(0) = *it;
              filename += cast.at(0);
              break;
          }
          castNext.at(0) = *boost::next(it);
          cast.at(0) = *it;
          //cout << "cast0" << cast.at(0) << endl;

          filename += cast.at(0);
          //cout << "cast " << cast.at(0) << endl;
          if(castNext.at(0) == ">"){
            break;
          }
          if(castNext.at(0) == "<"){
            break;
          }
          if(castNext.at(0) == "|"){
            break;
          }
        }
        arglist.push_back(filename);
      }
      else if(cast.at(0) == "grep"){
        arglist.push_back(cast.at(0));
        it++;
        for( ; it != token.end(); it++ ){
          if(boost::next(it) == token.end()){
              //cout << "Enetred break" << endl;
              cast.at(0) = *it;
              filename += cast.at(0);
              break;
          }
          castNext.at(0) = *boost::next(it);
          cast.at(0) = *it;
          //cout << "cast0" << cast.at(0) << endl;

          filename += cast.at(0);
          //cout << "cast " << cast.at(0) << endl;
          if(castNext.at(0) == ">"){
            break;
          }
          if(castNext.at(0) == "<"){
            break;
          }
          if(castNext.at(0) == "|"){
            break;
          }
        }
        arglist.push_back(filename);
      }
      else{
        for( ; it != token.end(); it++ ){
          if(boost::next(it) == token.end()){
              //cout << "Enetred break" << endl;
              cast.at(0) = *it;
              filename += cast.at(0);
              break;
          }
          castNext.at(0) = *boost::next(it);
          cast.at(0) = *it;
          //cout << "cast0" << cast.at(0) << endl;

          filename += cast.at(0);
          // filename += " ";
          //cout << "cast " << cast.at(0) << endl;
          if(castNext.at(0) == ">"){
            break;
          }
          if(castNext.at(0) == "<"){
            break;
          }
          if(castNext.at(0) == "|"){
            break;
          }
        }
        // cout << "WHAT IS THE FILENAME " << filename << endl;
        arglist.push_back(filename);
      }

      Base* temp = new Command(arglist);
      //cast.at(0) = *it;
        //cout << "cast1" << cast.at(0) << endl;
        // cout << "Cast: " << cast.at(0) << endl;
        //cout << "file1 "<< filename << endl;
      // temp->filename = filename;
      // filename = "";
      // cout << "file69"<< temp->filename << endl;
      return temp;
    }
  }



  if(it != token.end()){
    it++;
  }



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
      if(cast.at(0) == "<"){
          arglist.push_back(cast.at(0));
          return new Command(arglist);
        }
      //for test
      // if(cast.at(0) == "[" || cast.at(0) == "test"){
      if(cast.at(0) == "["){
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

  return new Command(arglist);
}

Base* parse(string &input){
  typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
  // boost::char_separator<char> sep("|&<>()[] ");
  Base* head = 0;
   string temp = "-";
   string tpath = "";

  vector<string> arglist;

  vector<string> cast(1);
  vector<string> tcast(1);
  vector<string> castNext(1);

  bool firstCommand = true;
  bool flagPresent = false;
  bool commandOnly = true;
  bool entersPrec = false;
  bool inputBool = false;
  bool pipeBool = false;
  bool singleOutput = false;
  bool trPresent = false;
  bool grepPresent = false;;
  string filename;
  //bool doubleOutput = false;
  tokenizer token(input);
  tokenizer::iterator it = token.begin();
  for (tokenizer::iterator it1 = token.begin(); it1 != token.end(); it1++) {
    cast.at(0) = *it1;
    // cout << cast.at(0) << endl;
  }

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
        if (boost::next(it) != token.end()){
          tcast.at(0) = *boost::next(it);
        }
        if(tcast.at(0) != "|"){
          if (firstCommand) {
            //it++;
            //cout << "bitch i'm going in\n";
            head = new Command(arglist);
            firstCommand = false;
          }
          //it = boost::next(it);
          Base* temp = new Pipe(head, tokeParse(token, it));
          //cout << "temp: \n";
          head = temp;
          pipeBool = true;

        }
        else{
          commandOnly = false;
          it++;

          if (firstCommand) {
            head = new Command(arglist);
            firstCommand = false;
          }
          Base* temp = new Or(head, tokeParse(token,it));
          head = temp;
        }
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
      if(cast.at(0) == "<"){
        // cout << "< i'm going in\n";
        if (firstCommand) {
          // cout << "bitch i'm going in\n";
          head = new Command(arglist);
          firstCommand = false;
        }
        Base* temp = new Input(head, tokeParse(token,it));
        // cout << "temp: \n";
        head = temp;
        inputBool = true;
      }
      if(cast.at(0) == ">"){
        inputBool = true;
        //cout << "> i'm going in\n";
        if (boost::next(it) != token.end()){
          tcast.at(0) = *boost::next(it);
        }

        if (tcast.at(0) == ">") {
          if (firstCommand) {
            //it++;
            //cout << "bitch i'm going in\n";
            head = new Command(arglist);
            firstCommand = false;
          }
          //it = boost::next(it);
          Base* temp = new Output_double(head, tokeParse(token, it));
          //cout << "temp: \n";
          head = temp;
          inputBool = true;
        }
        else{
          if (firstCommand) {
            //cout << "bitch i'm going in\n";
            head = new Command(arglist);
            firstCommand = false;
          }
          Base* temp = new Output_single(head, tokeParse(token,it));
          //cout << "temp: \n";
          head = temp;
          inputBool = true;
        }



      }
      if(cast.at(0) == "tr"){
        for( ; it != token.end(); it++ ){
          if(boost::next(it) == token.end()){
              //cout << "Enetred break" << endl;
              cast.at(0) = *it;
              // cout << "CAAUDJKFHFF _END" << cast.at(0) << endl;
              filename += cast.at(0);
              //filename += " ";
              break;
          }
          castNext.at(0) = *boost::next(it);
          cast.at(0) = *it;
          //cout << "cast0" << cast.at(0) << endl;
          cout << "CAAUDJKFHFF" << cast.at(0) << endl;
          filename += cast.at(0);
          if(castNext.at(0) != "-" && cast.at(0) != "-"){
            filename += " ";
          }
          //cout << "cast " << cast.at(0) << endl;
          if(castNext.at(0) == ">"){
            break;
          }
          if(castNext.at(0) == "<"){
            break;
          }
          if(castNext.at(0) == "|"){
            break;
          }
        }
        string tempList;
        for(unsigned i = 0; i < filename.size(); i++){
          if(filename.at(i) != ' '){
            tempList += filename.at(i);
          }
          else{
            arglist.push_back(tempList);
            tempList = "";
          }
        }
        // cout << "File NAME " << filename << endl;
        //arglist.push_back(filename);
        trPresent = true;
      }
      if(cast.at(0) == "grep"){
        arglist.push_back(cast.at(0));
        it++;
        for( ; it != token.end(); it++ ){
          if(boost::next(it) == token.end()){
              //cout << "Enetred break" << endl;
              cast.at(0) = *it;
              filename += cast.at(0);
              break;
          }
          castNext.at(0) = *boost::next(it);
          cast.at(0) = *it;
          //cout << "cast0" << cast.at(0) << endl;

          filename += cast.at(0);
          filename += " ";
          //cout << "cast " << cast.at(0) << endl;
          if(castNext.at(0) == ">"){
            break;
          }
          if(castNext.at(0) == "<"){
            break;
          }
          if(castNext.at(0) == "|"){
            break;
          }
        }
        // cout << "FILENAME " << filename << endl;
        string tempList;
        for(unsigned i = 0; i < filename.size(); i++){
          if(filename.at(i) != ' '){
            tempList += filename.at(i);
          }
          else{
            arglist.push_back(tempList);
            tempList = "";
          }
        }
        arglist.push_back(tempList);
        grepPresent = true;
      }

      if(flagPresent == false){
        if(trPresent == false){
          if(grepPresent == false){
          arglist.push_back(cast.at(0));
          }
        }
      }

      // if(cast.at(0) == "test" || cast.at(0) == "["){
      if(cast.at(0) == "["){
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
      if (it != token.end() ) {
          it++;
      }
    }


    if (commandOnly && !entersPrec && !inputBool && !singleOutput && !pipeBool)  {

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
    //cout <<  "received unpaired parenthesis\n";
    return false;
  }
  return true;
}

#endif
