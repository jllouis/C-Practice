/* Write a program that initializes a two-dimensional 3×5 array-of- double and uses a VLA-
based function to copy it to a second two-dimensional array. Also provide a VLA-based
function to display the contents of the two arrays. The two functions should be capable,
in general, of processing arbitrary N×M arrays. (If you don’t have access to a VLA-capable
compiler, use the traditional C approach of functions that can process an N×5 array). */
#include <stdio.h>

void VLA_copy(int, int, double ar[*][*]);
void print_VLA(int, int, double ar[*][*]);

int main(void)
{
  double array[3][5] = {{0.0,1.0,2.0,3.0,4.0}, {6.0,7.0,8.0,9.0,10.0}, {11.0,12.0,13.0,14.0,15.0}};

  VLA_copy(3,5,array);

  return 0;
}

void VLA_copy(int n, int m, double ar[n][m])
{
  double target[n][m];

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      target[i][j] = ar[i][j];

  printf("Printing the target array\n");
  print_VLA(3,5,target);
}

void print_VLA(int n, int m, double ar[n][m])
{
  for(int i = 0; i < n; ++i)     
    {                                                                  
      for(int j = 0; j < m; ++j)
	printf("%.1lf, ", ar[i][j]);

      printf("\n");
    }
}
