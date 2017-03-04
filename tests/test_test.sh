#!/bin/sh

echo "Making file called text"
touch text
echo "Testing no flag, -e, -f, d, on regular file"
echo "Expected outcome: (True), (True), (True), (False)"
test text
test -e text
test -f text
test -d text
echo "Testing no flag, -e, -f, d, on regular file with brackets"
echo "Expected outcome: (True), (True), (True), (False)"
[text]
[-e text]
[-f text]
[-d text]

echo "Making directory named direc"
mkdir direc
echo "Testing no flag, -e, -f, d, on directory"
echo "Expected outcome: (True), (True), (False), (True)"
test direc
test -e direc
test -f direc
test -d direc
echo "Testing no flag, -e, -f, d, on directory with brackets"
echo "Expected outcome: (True), (True), (False), (True)"
[direc]
[-e direc]
[-f direc]
[-d direc]
cd direc
echo "Making file to test longer paths"
touch text1
echo "Testing using brackets and -f flag"
cd ../
[-f direc/text1]
echo "Test invalid flag and then invalid path/file"
test -p text
[this/is/an/invaild/path]
