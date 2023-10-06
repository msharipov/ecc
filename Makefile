CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic -g --std=c++17 -Wno-sign-compare -Wno-comment

scramble : scramble.c
	${CXX} ${CXXFLAGS} scramble.c -o scramble

clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump
