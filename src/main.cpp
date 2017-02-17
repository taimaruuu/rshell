#include <unistd.h>
#include <iostream>

using namespace std;
int main(int argc, char**argv) {
  //loop for the shell
  //only exits with exit command
  for (; ; ) {

    char *userName = getlogin();            //Grab the user's name
    if(!userName) {
        perror("getlogin() error");         //Just in case you can't find it
    }

    char hostName[1000];
    gethostname(hostName, sizeof hostName); //Grab the machine name

    //Prints the bash $
    cout << userName << "@" <<  hostName << "$ ";                          
    //End of login info
    return 0;
  }

}
