#include <unistd.h>
#include <iostream>
#include "Command.h"
#include "Base.h"

using namespace std;
int main(int argc, char**argv) {
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
    char command[] = "date";
    Command *test = new Command(command);
    cout << test->get_string() << endl;
    test->exec();
    return 0;

  }

}
