// Scrambles the file by flipping each bit with frequency p.
#include <stdio.h>

int main(int argc, char * argv[]) {

    double P = 0.1;
    
    FILE * infile = fopen(argv[1], "r"),
         * outfile = fopen("out.txt", "w");

    if (!infile) {
        printf("\x1b[1;31mError!\x1b[0m Cannot open %s\n", argv[1]);
        return 1;
    }

    if (!outfile) {
        printf("\x1b[1;31mError!\x1b[0m Cannot open out.txt\n");
        return 1;
    }

    int c = fgetc(infile);

    while (!feof(infile)) {
        fwrite(&c, 1, 1, outfile);
        c = fgetc(infile);
    }

    fclose(infile);
    fclose(outfile);
    return 0;
}