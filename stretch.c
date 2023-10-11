#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char * argv[]) {

    long LEN = 1;
    bool decode = false;

    if (argc < 2 || argc > 3) {
    	printf("\x1b[1;31mError!\x1b[0m Incorrect number of arguments.\n");
	    printf("Usage: stretch LENGTH [--decode]\n");
    	return 1;
    }

    char * endpt;
    LEN = strtol(argv[1], &endpt, 10);

    if (LEN < 1 || endpt == argv[1]) {
    	printf("\x1b[1;31mError!\x1b[0m Incorrect value of length: %s\n", argv[1]);
	    printf("Length should be greater than 1.\n");
        return 1;
    }

    char DECODE_FLAG[] = "--decode";
    if (argc == 3) {
        if (!strcmp(argv[2], DECODE_FLAG)) {
            decode = true;
        } else {
            printf("\x1b[1;31mError!\x1b[0m Invalid argument: %s\n", argv[2]);
            printf("Usage: stretch LENGTH [--decode]\n");
            return 1;
        }
    }

    int c = getchar();

    if (decode) {
        // TODO : implement decoding
        return 0;
    }

    while (c != EOF) {
        for (int i = 0; i < LEN; i++) {
            putchar(c);
        }
        c = getchar();
    }

    return 0;
}
