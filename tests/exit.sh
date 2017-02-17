#!/bin/sh

exit
echo testing exit && exit
mkdir test_ || touch test_file; exit
#this line is only a comment; exit
echo "the line above shouldn't have done anything"
echo ------------------------------------------- || exit
echo 1 2 3 4 5 6 8 9; exit
mkdir || ls || exit || echo this line has a lot of pipes
exit || echo "should've exited"
                                            #empty line exit and comment test
echo hello; echo world && echo goodbye now; exit
echo 'here is some useful info:'; pwd; date; localhost; exit
touch exit     #should only make a new file called exit and not actually exit
exit
