#include <stdio.h>

void copy_ptrs(double *, const double *, double *);
void print_arr(const double *, const double *);

int main(void)
{
  double array[2][5] = {
    {0,1,2,3,4},
    {5,6,7,8,9}
  };
  
  double target[2][5];
  
  copy_ptrs(&target[0][0], &array[0][0], &(array[0][0]) + 5);
  copy_ptrs(&target[1][0], &array[1][0], &(array[1][0]) + 5);
  print_arr(&target[0][0], &(target[0][0]) + 5);
  print_arr(&target[1][0], &(target[1][0]) + 5);

  return 0;
}

void copy_ptrs(double *target, const double *source, double *end)
{
  for (; source < end; ++target, ++source)
    *target = *source;
}

void print_arr(const double *start, const  double *end)
{
  while ( start < end)
    printf("%.1lf, ", *start++);
  printf("\n");
}
