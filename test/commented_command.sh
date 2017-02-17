#!/bin/sh

ls #;echo a                                 #should only execute ls
ls #     ls; ls;                            #should only execute ls once
mkdir test_ # ; echo comments are working   #only makes new dir test_       
ls; mkdir; ls #echo 'made a new directory   #ls and mkdir only
mkdir || echo "couldn't make directory"     #one or other
echo this is a comment; echo test           #this is a comment test split up
echo 5 && echo 6 && echo 7 #5 6 7           #test && and multiple echo
pwd # pwd pwd pwd                           #only one pwd
                                            #tesing an empty line
date #hostname                              #only date
hostname; date && pwd                       #prints host, date and working dir
history && echo "this is the history log"   #prints history and echo fn
echo "done testing comments" #exit          #self explanatory
