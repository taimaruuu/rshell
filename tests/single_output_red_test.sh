#!/bin/sh

ls > ls_file.txt
echo this should appear in the file now > output_file.txt
echo hello world > helloWorld.txt
date > date.txt
pwd > pwd.txt
rm output_file.txt
rm hellWorld.txt
rm date.txt
rm pwd.txt
ls > finaloutput.txt
pwd > finaloutput.txt
echo all done > finaloutput.txt
