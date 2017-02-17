#!/bin/sh

mkdir test_ && touch test_file
rm test_file && ls &&  echo "test_file should be gone now"
ls || ls || ls || ls || ls
echo && echo "-" && echo '1' && mkdir hello_world
echo hello world && ps || pwd
cat unrealfilename;echo testing cat on invalid file
ls; pwd; hostname || date
echo hello; echo world;

mkdir && echo "shouldn't make any directory"
mkdir test_2 && echo "should make test_2 directory"
echo 'this is a really long sentence'
echo "date is:" && date
echo "working directory is:"; pwd
echo "current processes are:"; ps; echo "-----------"; 
echo 'done testing multiple commands, goodbye now' && exit
