CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic -g --std=c++17 -Wno-sign-compare -Wno-comment

scramble : scramble.c
	${CXX} ${CXXFLAGS} scramble.c -o scramble

stretch : stretch.c
	${CXX} ${CXXFLAGS} stretch.c -o stretch

clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump
