#include "Pipe.h"
using namespace std;

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>
#include <string>

Pipe::Pipe(Base* lhs, Base* rhs): Connector(lhs,rhs) {}


//redirects input from the standard in to the input given on the command line
bool Pipe::exec(int in, int out) {
    int pfd[2];
    int ret_pipe = pipe(pfd);
    int dstdin = dup(0);
    int dstdout = dup(1);
    bool success = false;

    if (ret_pipe == -1) {
      perror("pipe error");
      return false;
    }

    close(1);
    dup2(pfd[1], STDOUT_FILENO);
    lhs->exec(0,1);
    close(pfd[1]);

    dup2(dstdout, STDOUT_FILENO);
    // close(dstdout);

    dup2(pfd[0], STDIN_FILENO);
    close(pfd[0]);

    if (rhs->exec(0,1 )) {
      success = true;
    }

    dup2(dstdin, STDIN_FILENO);

    close(dstdin);
    close(dstdout);

    return success;

  //   int pipefds[2];
  //   if(pipe(pipefds) < 0) {
  //       perror("pipe");
  //       return false;
  //   }
  //   if(lhs->exec(in, pipefds[1]) == false) {
	// close(pipefds[1]);
  //       return false;
  //   }
  //   close(pipefds[1]);
  //
  //   if(rhs->exec(pipefds[0], out) == false) {
	// close(pipefds[0]);
	// return false;
  //   }
  //   close(pipefds[0]);
  //   return true;

}
