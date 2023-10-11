CXXFLAGS ?= --std=c17 -Wall -Werror -pedantic -g -Wno-sign-compare -Wno-comment

scramble : scramble.c
	gcc ${CXXFLAGS} scramble.c -o scramble

stretch : stretch.c
	gcc ${CXXFLAGS} stretch.c -o stretch

clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump
