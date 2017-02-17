#include <cstring>
#include <iostream>
#include <vector>
#include<boost/algorithm/string/trim.hpp>
#include <string.h>
#include <stdio.h>
using namespace std;


void removeSpaces(string &s){
   boost::trim(s);
}

void getConnectors(string &s){
  //for(int i = 0; i < s.size());
}

void removeComment(char* s){
  bool comment = false;
  //for(int i = 0; i < s.size() && !comment; i++){
    //if(s.at(i) == '#'){
      //s = s.substr(0, i);
      //comment = true;
   // }
 // }
}



int main(int argc, char**argv){

    vector<string> cmdsList;
    vector<string> connectorList;

    char input[1000] = "mkdir test_ || touch test_file #mkdir test_ && touch test_file && mkdir test_ && touch test_file || echo test";
    //string inputString = string(input);
    cout << strlen(input) << endl;
    char* input_ptr = input;
    //removeComment(input_ptr);
    //char *newString[1000] = inputString;
    cout << "input string: " << inputString << endl;

    char *token = strtok(input, " ");


    while (token != NULL) {
        string tokenString = string(token);
        removeSpaces(tokenString);
        if(!strcmp(tokenString.c_str(), "||")){
          cout << "OR: ";
          connectorList.push_back(tokenString);
        }
        else if(!strcmp(tokenString.c_str(), "&&")){
          cout << "And: ";
          connectorList.push_back(tokenString);
        }
        else if(!strcmp(tokenString.c_str(), ";")){
          cout << "Semi: ";
          connectorList.push_back(tokenString);
        }
        else{
          cout << "Else: ";
          cmdsList.push_back(tokenString);
        }
        cout << token << '\n';
        token = strtok( NULL, " ");

      }
    cout << "Vector Cmds output: " << endl;
    for(int i = 0; i < cmdsList.size(); i++){
      cout << cmdsList.at(i) << endl;
    }

    cout << "Vector Connectors output: " << endl;
    for(int i = 0; i < connectorList.size(); i++){
      cout << connectorList.at(i) << endl;
    }

    return 0;
  }
