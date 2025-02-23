all: main test

main: binary.h binary.cpp main.cpp
	g++ -g -std=c++03 -Wall -Werror main.cpp anagram.h anagram.cpp binary.h binary.cpp -g -o mp12

test: 
	g++ -g -std=c++03 -Wall -Werror Ganagram.o Ganagram.h Gbinary.o Gbinary.h anagram.h anagram.cpp binary.h binary.cpp check.h check.cpp test.cpp -o mp12_test
clean:
	rm mp12 mp12_test

