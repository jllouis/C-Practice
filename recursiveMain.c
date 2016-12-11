// recursiveMain.c
// Writing a program that converts some binary binary string I saw on the internet to its ASCII equiv by calling main recursively for some reason.

#include <stdlib.h> // for strtol
#include <stdio.h> // for io functions
#include <string.h> // strncpy

// should receive binary sequence via command line args
int main(int argc, char **argv)
{
    if(argv[1][0] == '\000') // if reach end of string, reached based case
        return 0;

    unsigned strl = strlen(argv[1]); // how many bits do we have left?

        char input[8]; // to store input which is to be printed - could probably do without this
        strncpy(input, argv[1], 8); // copy only the 8 bits that corresponds to the char to be printed

        char *end; // to make strtol happy
        putc(strtol(input, &end, 2), stdout);

        argv[1] += 8;
        char *newargv[2] = {"recursiveMain", argv[1]}; // new argv for main call; bin sequence w/o already printed chars

        main(1, newargv); // all right, good luck! :)

    return 0;
}
