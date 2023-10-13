// Scrambles the bytes from stdin by flipping each bit with frequency p.
// Prints the result to stdout.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char * argv[]) {

    double P = 0.0;
    uint16_t seed = 0;

    if (argc < 2 || argc > 3) {
    	printf("\x1b[1;31mError!\x1b[0m Incorrect number of arguments.\n");
	    printf("Usage: scramble p [seed]\n");
    	return 1;
    }

    char * endpt;
    P = strtod(argv[1], &endpt);

    if (P < 0.0 || P > 1.0 || endpt == argv[1]) {
    	printf("\x1b[1;31mError!\x1b[0m Incorrect value of p: %s\n", argv[3]);
	    printf("p should be between 0 and 1.0, inclusively.\n");
        return 1;
    }

    if (argc == 3) {
	    seed = strtol(argv[2], &endpt, 10); 
    }

    srand(seed);

    int16_t c = getchar();

    while (c != EOF) {
        uint8_t mask = 1,
                new_byte = 0;
        for (uint8_t i = 0; i < 7; i++) {
            if (1.0*rand()/RAND_MAX < P) {
                // Replaced with noise
                new_byte += (rand()%2) * mask;
            } else {
                // Correct transmission
                new_byte += c & mask;
            }
            mask <<= 1;
        }
        putchar(new_byte);
        c = getchar();
    }

    return 0;
}
