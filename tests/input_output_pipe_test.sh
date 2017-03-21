#!/bin/sh

ls > output.txt
echo overwriting the old file > output.txt
wc < output.txt >> output.txt
echo counting our tests now >> output.txt
ls -la | grep test | wc >> output.txt
cat < output.txt | tr a-z A-Z >> output.txt
