// Programming Exercise 10:2
#include <stdio.h>

void copy_arr(double [], const double [], int);
void copy_ptr(double *, const double *, int);
void copy_ptrs(double *, const double *, double *);
void print_arr(const double *, const double *);

int main(void)
{
  double source[5] = { 0.1, 2.2, 4.3, 6.4, 8.5};
  double target1[5];
  double target2[5];
  double target3[5];

  copy_arr(target1, source, 5);
  copy_ptr(target2, source, 5);

  copy_ptrs(target3, source, source + 5);

  print_arr(target1, target1 + 5);
  print_arr(target2, target2 + 5);
  print_arr(target3, target3 + 5);

  return 0;
}

void copy_arr(double target[], const double source[], int num)
{
  for (int i = 0; i < num; ++i)
    target[i] = source[i];
}

void copy_ptr(double *target, const double *source, int num)
{
  for (int i = 0; i < num; ++i)
    *(target+i) = *(source+i);
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
