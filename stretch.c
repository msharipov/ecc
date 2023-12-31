#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>


uint8_t choose_byte(const uint8_t BYTES[], size_t LEN) {
    size_t counts[8] = {0};
    uint8_t original = 0;

    // Count up the occurences of each bit
    for (size_t byte = 0; byte < LEN; byte++) {
        uint8_t mask = 1;
        for (uint8_t bit = 0; bit < 8; bit++) {
            if (mask & BYTES[byte]) { counts[bit]++; }
            mask <<= 1;
        }
    }

    // Reconstructs the byte
    for (uint8_t bit = 0; bit < 8; bit++) {
        if (counts[bit] > LEN/2) {
            original += 1 << bit;
        }
    }

    return original;
}


void decode_bytes(size_t LEN) {
    uint8_t bytes[LEN];
    size_t counter = 0;

    int16_t c = getchar();
    while (c != EOF) {
        bytes[counter] = c; // only stores the lower 8 bits
        counter = (counter + 1)%LEN;

        // Check if bytes are filled out
        if (counter == 0) {
            putchar(choose_byte(bytes, LEN));
        }

        c = getchar();
    }
}


int main(int argc, char * argv[]) {

    size_t LEN = 1;
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

    if (decode) {
        decode_bytes(LEN);
        return 0;
    }

    int16_t c = getchar();
    while (c != EOF) {
        for (size_t i = 0; i < LEN; i++) {
            putchar(c);
        }
        c = getchar();
    }
    return 0;
}
