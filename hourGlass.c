#include <stdio.h>
#include <math.h>

int main(void) {
   int array[6][6];
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            scanf("%d", &array[i][j]);

    //test print
    /* for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++)
            printf("%d", array[i][j]);
        fputc('\n', stdout);
    } */
    int maxSum = -INFINITY;
    //// Calculating maximum hourglass sum in array ////
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
        {
            int currentSum = array[i][j]     +
                             array[i][j+1]   +
                             array[i][j+2]   +
                             array[i+1][j+1] +
                             array[i+2][j]   +
                             array[i+2][j+1] +
                             array[i+2][j+2];

            if (currentSum > maxSum)
                maxSum = currentSum;
        }

    printf("%d", maxSum);
}