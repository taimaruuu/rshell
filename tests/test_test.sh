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

echo "Making directory named test_dir"
mkdir test_dir
echo "Testing no flag, -e, -f, d, on directory"
echo "Expected outcome: (False), (False), (False), (True)"
test test_dir
test -e test_dir
test -f test_dir
test -d test_dir
echo "Testing no flag, -e, -f, d, on directory with brackets"
echo "Expected outcome: (False), (False), (False), (True)"
[test_dir]
[-e test_dir]
[-f test_dir]
[-d test_dir]
cd test_dir
echo "Making file to test longer paths"
touch text1
echo "Testing using brackets and -f flag"
cd ../
[-f test_dir/text1]
echo "Test invalid flag and then invalid path/file"
test -p text
[this/is/an/invaild/path]
