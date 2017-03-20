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
#include "parse.h"
#include "Connector.h"
#include "And.h"
#include "Or.h"
#include "Semicolon.h"


using namespace std;

int main(int argc, char**argv) {
  vector<string> cmdsList;
  vector<string> connectorList;


  char *userName = getlogin();         //User's name
  if(!userName){
      perror("getlogin()");            //Throws error if cannot find it.
    }
  char hostName[1000];
  gethostname(hostName, sizeof hostName); //Machine name

  //loop for the shell
  //exits with exit command
  for (; ; ) {
    vector<string> argsList;
    //Prints the bash $
    cout << userName << "@" <<  hostName << "$ ";
    //End of login info

    //Comman testing
    // char command[] = "date";
    // Command *test = new Command(command);
    // cout << test->get_string() << endl;
    // test->exec(int in, int out);

    string userInput;
    getline(cin, userInput);
    if(userInput.at(0) != '#'){
    if (preParse(userInput)) {
      Base* toExec = parse(userInput);
      //removeComment(userInput);

      // converts user input to cstring
      char *cstr = new char[userInput.length() + 1];
      strcpy(cstr, userInput.c_str());

      if(userInput == "exit"){  //if user enters exit as first command
        exit(0);
        // execute the break command
        //break;                  //break the for loop to exit rShell
      }
      if(userInput.at(0) == '#'){

      }

      if (userInput.size() == 0) {

      }

      //exec base*

      //toExec->exec(in, out);

      //Command *userCommand = new Command(cstr);
      //userCommand->exec(int in, int outargsList);

      //populateVectors(userInput, cmdsList, connectorList);
      //cout << cmdsList.size() << endl;
      //cleanCmds(cmdsList);

      // for(int i = 0; i < cmdsList.size(); i++){
      //   cout << cmdsList.at(i) << endl;
      // }
    }
      cmdsList.clear();
    }

  }
  return 0;

}
