#include <cstring>
#include <iostream>
#include <vector>
#include<boost/algorithm/string/trim.hpp>
#include <string.h>
#include <stdio.h>
using namespace std;

vector<string> cmdsList; //global vector for cmds
vector<string> connectorList; //global vector for connectors

// This Function trims all leading and trailing spaces
void removeSpaces(string &s){
   boost::trim(s);
}

//This function determines the smallest index from three integer parameters
int determineSmallest(int a, int b, int c){
  if( a <= b && a <= c){
    //cout << " A: " << a << endl;
    return a;
  }
  else if( b <= a && b <= c){
    //cout << " B: " << b << endl;

    return b;
  }
  else if( c <= a && c <= b){
    //cout << " C: " << c << endl;
    return c;
  }
  else
    return a;
}

//this function removes the comment from the input
void removeComment(string& s){
  bool comment = false;
  for(int i = 0; i < s.size() && !comment; i++){
    if(s.at(i) == '#'){
      s = s.substr(0, i);
      comment = true;
    }
  }
}

//this function populates both global vectors of cmds and connectors
void populateVectors(string &s){
  //for(int i = 0; i < s.size(); i++){
    int orLocation = s.find("||");
    int andLocation = s.find("&&");
    int semiLocation = s.find(";");
    if(orLocation == string::npos){
      orLocation = 99999999; // set to large number to ensure it wil never be the smallest
    }
    if(andLocation == string::npos){
      andLocation = 99999999; // set to large number to ensure it wil never be the smallest
    }
    if(semiLocation == string::npos){
      semiLocation = 99999999; // set to large number to ensure it wil never be the smallest
    }
    int closestLocation = determineSmallest(orLocation, andLocation, semiLocation);
    if(closestLocation == 99999999){
      if(s.size() != 0){
        cmdsList.push_back(s);
      }
      //cout << "no more" << endl;
      return;
    }
    string command = s.substr(0, closestLocation);
    if(s.at(closestLocation) == '|'){
      //cout << "Closest Operator: "  << s.at(closestLocation) << s.at(closestLocation +1) << " " << endl;
      connectorList.push_back("||");
      cmdsList.push_back(command);
      //cout << "Command: " << command << endl;
      s = s.substr(closestLocation + 1);
    }
    else if(s.at(closestLocation) == '&'){
      //cout << "Closest Operator: "  << s.at(closestLocation) << s.at(closestLocation +1) << " " << endl;
      connectorList.push_back("&&");
      cmdsList.push_back(command);
      //cout << "Command: " << command << endl;
      s = s.substr(closestLocation + 1);
    }
    else if(s.at(closestLocation) == ';'){
      //cout << "Closest Operator: "  << s.at(closestLocation) << " " << endl;
      connectorList.push_back(";");
      cmdsList.push_back(command);
      //cout << "Command: " << command << endl;
      s = s.substr(closestLocation + 1);
    }
    else{
      cmdsList.push_back(command);
      s = "";
    }

    //cout << "s: " << s << endl;

  populateVectors(s);
}
//cleans parsed commands in vector
void cleanCmds(vector<string> &v){
  for (int i = 0; i < v.size(); i++) {
    if(v.at(i).find('|') != string::npos || v.at(i).find('&') != string::npos){
      v.at(i) = v.at(i).substr(2);
    }
    removeSpaces(v.at(i));
  }
}

int main(int argc, char**argv){



    char input[1000] = "pwd";
    string inputString = string(input);
    removeComment(inputString);
    //char *newString[1000] = inputString;
    cout << "input string: " << inputString << endl;

    char *token = strtok(input, " ");

    cout << "GETCONNECTORS: ";
    populateVectors(inputString);
    cout << endl;
    // while (token != NULL) {
    //     string tokenString = string(token);
    //     removeSpaces(tokenString);
    //     if(!strcmp(tokenString.c_str(), "||")){
    //       cout << "OR: ";
    //       connectorList.push_back(tokenString);
    //     }
    //     else if(!strcmp(tokenString.c_str(), "&&")){
    //       cout << "And: ";
    //       connectorList.push_back(tokenString);
    //     }
    //     else if(!strcmp(tokenString.c_str(), ";")){
    //       cout << "Semi: ";
    //       connectorList.push_back(tokenString);
    //     }
    //     else{
    //       cout << "Else: ";
    //       cmdsList.push_back(tokenString);
    //     }
    //     cout << token << '\n';
    //     token = strtok( NULL, " ");
    //
    //   }
    cout << "Vector Cmds output FINAL: " << endl;
    cleanCmds(cmdsList);
    for(int i = 0; i < cmdsList.size(); i++){
      cout << cmdsList.at(i) << endl;
    }

    cout << "Vector Connectors output FINAL: " << endl;
    for(int i = 0; i < connectorList.size(); i++){
      cout << connectorList.at(i) << endl;
    }

    return 0;
  }
