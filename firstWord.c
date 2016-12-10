/*  Design and test a function that reads the first word from a line of input into an array and
discards the rest of the line. It should skip over leading whitespace. Define a word as a
sequence of characters with no blanks, tabs, or newlines in it. it
accepts a second parameter specifying the maximum number of characters that can be
read. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <inttypes.h>

void firstWord(char * line, uintmax_t max)
{
    uintmax_t count = 0;

    while(!isalpha(*line))
        ++line;

    while(!ispunct(*line) && isprint(*line) && !isblank(*line) && count < max) {
        count++;
        line++;
    }

    line -= count;
    for(uintmax_t i = 0; i < count; i++)
        putc(*(line+i), stdout);
    putc('\n', stdout);
    fflush(stdout);
}

int main(int argc, char *argv[])
{
    char * end;
    uintmax_t max = strtoumax(argv[1], &end ,10);

    if(argc > 1)
        for(int i = 2; i < argc; ++i)
            firstWord(argv[i], max);
    else {
        puts("Usage: fistWord [max num of chars to read] [\"string 1\" \"string 2\" ... ]");
        return 1;
    }

    return EXIT_SUCCESS;
}

