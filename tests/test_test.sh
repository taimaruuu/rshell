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

echo "Making directory named sample_dir"
mkdir sample_dir
echo "Testing no flag, -e, -f, d, on directory"
echo "Expected outcome: (False), (False), (False), (True)"
test sample_dir
test -e sample_dir
test -f sample_dir
test -d sample_dir
echo "Testing no flag, -e, -f, d, on directory with brackets"
echo "Expected outcome: (False), (False), (False), (True)"
[sample_dir]
[-e sample_dir]
[-f sample_dir]
[-d sample_dir]
cd sample_dir
echo "Making file to test longer paths"
touch text1
echo "Testing using brackets and -f flag"
cd ../
[-f sample_dir/text1]
echo "Test invalid flag and then invalid path/file"
test -p text
[this/is/an/invaild/path]
