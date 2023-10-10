// Scrambles the bytes from stdin by flipping each bit with frequency p.
// Prints the result to stdout.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

    double P = 0.0;
    long seed = 0;

    if (argc < 2 || argc > 3) {
    	printf("\x1b[1;31mError!\x1b[0m Incorrect number of arguments.\n");
	    printf("Usage: scramble p [seed]\n");
    	return 1;
    }

    char * endpt;
    P = strtod(argv[1], &endpt);

    if (P < 0.0 || P > 0.5 || endpt == argv[1]) {
    	printf("\x1b[1;31mError!\x1b[0m Incorrect value of p: %s\n", argv[3]);
	    printf("p should be between 0 and 0.5, inclusively.\n");
        return 1;
    }

    if (argc == 3) {
	    seed = strtol(argv[2], &endpt, 10); 
    }

    srand(seed);

    int c = getchar();

    while (c != EOF) {
        int mask = 1;
        for (int i = 0; i < 7; i++) {
            if (1.0*rand()/RAND_MAX < P) { c ^= mask; }
            mask <<= 1;
        }
        putchar(c);
        c = getchar();
    }

    return 0;
}
