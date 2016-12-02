//#include <stdlib.h>
#include <stdio.h>
//#include <string.h>
#include <stdbool.h>

void convert(unsigned); // converts unsigned integer to binary
//void print_bool_array(_Bool[]); // prints binary array

int main(void)
{
    unsigned input;
    scanf("%u", &input);
    convert(input);
    return 0;
}

//void print_bool_array(_Bool array[20])
//{
//    for (int i = 19; i >= 0;)
//        printf("%d", (*(array+i)) ? 1 : 0);
//    fputc('\n', stdout);
//
//    return;
//}

void convert(unsigned u)
{
    _Bool binary_rep[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int index = 19;
    unsigned consecutive = 0, max = 0;

    for (;  u != 0; u /= 2)
        binary_rep[index--] = u % 2;

    index = 19;
    for (_Bool continuous = false; index >= 0; --index) {
        if (binary_rep[index] && !continuous) {
            continuous = true;
            consecutive = 1;
        }
        else if (binary_rep[index])
            consecutive++;
        else
            continuous = false;

        if (consecutive > max)
            max = consecutive;
    }

    printf("%u\n", max);



//    for (int i = 0; i < 20;)
//        printf("%d", (binary_rep[i++]) ? 1 : 0);
//    fputc('\n', stdout);

}
