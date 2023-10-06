// Scrambles the file by flipping each bit with frequency p.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

    double P = 0.0;
    long seed = 0;

    if (argc < 3 || argc > 5) {
    	printf("\x1b[1;31mError!\x1b[0m Incorrect number of arguments.\n");
	    printf("Usage: scramble INPUT_FILE OUTPUT_FILE [p] [seed]\n");
    	return 1;
    }

    char * endpt;
    if (argc >= 4) {
	    P = strtod(argv[3], &endpt);
    }

    if (P < 0.0 || P > 0.5 || endpt == argv[3]) {
    	printf("\x1b[1;31mError!\x1b[0m Incorrect value of p: %s\n", argv[3]);
	    printf("p should be between 0 and 0.5, inclusively.\n");
        return 1;
    }

    if (argc == 5) {
	    seed = strtol(argv[4], &endpt, 10); 
    }
    
    FILE * infile = fopen(argv[1], "r");
    if (!infile) {
        printf("\x1b[1;31mError!\x1b[0m Cannot open %s\n", argv[1]);
        return 1;
    }

    FILE * outfile = fopen(argv[2], "w");
    if (!outfile) {
        printf("\x1b[1;31mError!\x1b[0m Cannot open %s\n", argv[2]);
        return 1;
    }

    srand(seed);

    int c = fgetc(infile);

    while (!feof(infile)) {
        int mask = 1;
        for (int i = 0; i < 7; i++) {
            if (1.0*rand()/RAND_MAX < P) { c ^= mask; }
            mask <<= 1;
        }
        fwrite(&c, 1, 1, outfile);
        c = fgetc(infile);
    }

    fclose(infile);
    fclose(outfile);
    return 0;
}
