/* Write a program that prompts the user to enter three sets of five double numbers each.
(You may assume the user responds correctly and doesn’t enter non-numeric data.) The
program should accomplish all of the following:
a. Store the information in a 3×5 array.
b. Compute the average of each set of five values.
c. Compute the average of all the values.
d. Determine the largest value of the 15 values.
e. Report the results.
Each major task should be handled by a separate function using the traditional C
approach to handling arrays. Accomplish task “b” by using a function that computes
and returns the average of a one-dimensional array; use a loop to call this function three
times. The other tasks should take the entire array as an argument, and the functions
performing tasks “c” and “d” should return the answer to the calling program. */

#include <stdio.h>

void input(int, int, double [*][*]);
double average(int, const double [*]);
//int largest(int, int, const double ar[*][*]);
//void print_results(...); *** Not needed, not implemented

int main(void)
{
  double inputArray[3][5];

  input(3, 5, inputArray);
  printf("%s %lf\n","The average of array 1 is: ", average(5, &inputArray[0][0]));
  printf("%s %lf\n","The average of array 2 is: ", average(5, &inputArray[1][0])); 
  printf("%s %lf\n","The average of array 3 is: ", average(5, &inputArray[2][0])); 
  //largest(3, 5, inputArray);

  return 0;
}

void input (int n, int m, double ar[n][m])
{
  for (int i = 0; i < n; ++i)
    {
      printf("%s: ", "Enter set of five doubles");
      for(int j = 0; j < m; ++j)
	{
	  scanf("%lf", &ar[i][j]);
	  getchar();
	}
    }
}

double average(int n, const double ar[n])
{
  double sum = 0;

    for (int i = 0; i < n; ++i)
	//printf("Adding %lf to sum\n", ar[i]);
	sum += ar[i];
      
  return sum/n;
}
