/* File: gdb_demo2.c */
/* Kal Rabb: Adapted from http://www.gdbtutorial.com/ */

#include <stdio.h>

int getYears(int, int, float);

int main()
{ 
	int balance=100;
	int target=1000;
	float rate = 0.1;
	int years = getYears(balance, target, rate);
  printf("Starting with $%d, with interest rate %.2f\n", balance, rate);
	printf("No. of years to achieve target balance of $%d: %d\n",target, years);


	return 0;
}


int getYears(int bal, int target, float rate)
{
  int balance = bal;
  int year = 0;
  do
  {
    float interest = balance * rate;
    balance = balance + interest;
    year++;
  } while ( balance < target );
   return year;
}
