rshell:
	-mkdir -p bin
	g++ -std=c+98 -Wall -Werror -ansi -pedantic -o bin/rshell src/*.cpp
