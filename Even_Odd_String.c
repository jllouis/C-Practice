#include <stdio.h>
#include <string.h>

/* NOTE!: strcat() DIDN'T WORK! Why?*/

int main(void) {
    unsigned int size;
    scanf("%u", &size);
    char string[size][10000], oddstring[size][5001];

    for (unsigned int k = 0; k < size; ++k)
        scanf("%s", &string[k]);

    for (unsigned int k = 0; k < size; ++k) {
        for (unsigned int length = strlen(string[k]), i = 0, j = 0; i < length; i++) {
            if (i % 2 == 0) {
                fputc(string[k][i], stdout);
                fflush(stdout);
            }
            else
                oddstring[k][j++] = string[k][i];

        }
        printf(" ");

        for (unsigned int l = 0, length = strlen(oddstring[k]); l < length; ++l) {
            fputc(oddstring[k][l], stdout);
            fflush(stdout);
        }
        printf("\n");
    }
    return 0;
}
