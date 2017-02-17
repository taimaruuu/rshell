#include <unistd.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include<boost/algorithm/string/trim.hpp>
#include <string.h>
#include <stdio.h>
#include "Command.h"
#include "Base.h"


using namespace std;



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
void populateVectors(string &s, vector<string> &cmdsList, vector<string> &connectorList){
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

  populateVectors(s, cmdsList, connectorList);
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



int main(int argc, char**argv) {
  vector<string> cmdsList;
  vector<string> connectorList;


  //loop for the shell
  //exits with exit command
  for (; ; ) {

    char *userName = getlogin();            //User's name
    if(!userName){
        perror("getlogin()");               //Throws error if cannot find it.
      }
    char hostName[1000];
    gethostname(hostName, sizeof hostName); //Machine name

    //Prints the bash $
    cout << userName << "@" <<  hostName << "$ ";
    //End of login info

    //Comman testing
    // char command[] = "date";
    // Command *test = new Command(command);
    // cout << test->get_string() << endl;
    // test->exec();

    string userInput;
    getline(cin, userInput);
    removeComment(userInput);

    if(userInput == "exit"){
      //TODO: exit shit
    }

    populateVectors(userInput, cmdsList, connectorList);
    cout << cmdsList.size() << endl;
    cleanCmds(cmdsList);

    for(int i = 0; i < cmdsList.size(); i++){
      cout << cmdsList.at(i) << endl;
    }






    return 0;

  }

}
