#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "Test.h"
#include <iostream>
#include <string>
using namespace std;

Test::Test(string flag, string path) {
    this->flag = flag;
    this->path = path;
}

//if no flag is defined, assume flag is -e
Test::Test(string path) {
    this->flag = "-e";
    this->path = path;
}


bool Test::exec() {
    struct stat buf;
    int statvalue = stat(this->path.c_str(), &buf);
    //if stat value is -1, cannot be -e,-f,-d this must be false
    //cout << flag << ", " << path << endl;
    if(statvalue == -1) {
	cout << "(False)" << endl;
        return false;
    }
    //since path HAS TO BE a regular file OR a valid directory, if flag is -e ret. true
    if(this->flag == "-e") {
        cout << "(True)" << endl;
        return true;
    }
    else if(this->flag == "-f") {
        //if is a regular file, ret. true, else ret. false
        if(S_ISREG(buf.st_mode)) {
            cout << "(True)" << endl;
            return true;
        }
        else {
	    //cout << "test -f\n";
            cout << "(False)" << endl;
            return false;
        }
    }
    else if(this->flag == "-d") {
        //if is a directory, ret. true, else ret. false
        if(S_ISDIR(buf.st_mode)) {
            cout << "(True)" << endl;
            return true;
        }
        else {
            cout << "(False)" << endl;
	    //cout << "test -d\n";
            return false;
        }
    }
    //if it reaches this point, the flag was invalid
    else {
        cout << "Error: invalid flag" << endl;
        return false;
    }
}
