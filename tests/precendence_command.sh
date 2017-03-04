#!/bin/sh

(echo a && echo b) || (echo c && echo c)
(echo a || echo b) && (echo c || echo d)
(echo a) && (echo b)
(echo a) || echo b
pwd && (date || cal)
hostname #(comments)
echo "hello" && (echo "world" || echo "bye)
(echo hello world)
