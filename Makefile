rshell:
	-mkdir -p bin
	g++ -std=c+98vim -Wall -Werror -ansi -pedantic -o bin/rshell src/*.cpp
