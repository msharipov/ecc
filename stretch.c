#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]) {

    long LEN = 1;
    _Bool reverse = false;

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

    

    return 0;
}
