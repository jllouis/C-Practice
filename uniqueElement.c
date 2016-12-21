/* Takes two arrays containing identical elements except 1,
 * Returns the element which unique to one of the two arrays */

#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (a > b) ? a : b

int compare_ints(const void * a, const void * b)
{
    const int *ia = (const int*)a;
    const int *ib = (const int*)b;
    return *ia - *ib;
}

void customSort(int *a1, int *a2, unsigned size1, unsigned size2)
{
    int length = max(size1, size2);

//    for (int i = 0; i < length -1; ++i)
//        printf("%d ", a1[i]);
//    puts("");

//    printf("Sorting... \n");
    qsort(a1, length - 2, sizeof(int), compare_ints);

    for (int i = 0; i < length -1; ++i)
        printf("%d ", a1[i]);
    puts("\n");

//    for (int i = 0; i < length; ++i)
//        printf("%d ", a2[i]);
//    puts("");

//    printf("Sorting... \n");
    qsort(a2, length - 1, sizeof(int), compare_ints);

    for (int i = 0; i < length; ++i)
        printf("%d ", a2[i]);
    puts("\n");
}

int uniqueNumber(int * a1, int * a2, unsigned size1, unsigned size2)
{
//    puts("In uniqueNumber:\n");
    int length = max(size1, size2);

    customSort(a1, a2, size1, size2); // sorts each array in size*log(size) time

    //traverses array looking for mismatching element and returns it
    for(int i = 0; i < length; ++i)
        if (a1[i] != a2[i])
            return a2[i];
}


int main(void)
{
    int array1[] = { 78, 11, 143, 84, 77, 1, 26, 35};
    int array2[] = { 11, 84, 35, 1, 77, 78, 26, 21, 143};

    //getting number of elements in array, assuming they're full
    int sizeA1 = sizeof(array1) / sizeof(array1[0]);
    int sizeA2 = sizeof(array2) / sizeof(array2[0]);


  printf("The unique number is: %i\n", uniqueNumber(array1, array2, sizeA1, sizeA2));

    return 0;
}