/*
 * K&R ex3-1
 * 
 * clang -Wall -Wextra -Werror -o binsearch binsearch.c
 * 
 * Exercise 3-1  Our binary search makes two tests inside the loop, when one 
 * would suffice (at the price of more tests outside). Write a version with only
 *  one test inside the loop and measure the difference in run-time.
 * 
 * Max Filin 2022
 */
#include <stdio.h>
#include <time.h>

#define AMOUNT 1000000

int binsearch(int x, int v[], int n)
{
	int low, hight, mid;

	low = 0;
	hight = n - 1;
	while (low <= hight)
	{
		mid = (low + hight) / 2;
		if (x < v[mid])
			hight = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else	/* найдено соответствие*/
			return mid;
	}
	return - 1; /* нет соответствия*/
}

int binsearch_mod(int x, int v[], int n)
{
	int low, hight, mid;
	low = 0;
	hight = n - 1;

	while (low < hight)
	{
		mid = (low + hight) / 2;
		if (x <= v[mid])
			hight = mid;
		else	
			low = mid + 1;
	}
	if (v[low] == x)
		return low;
	else 
		return - 1; 
}


int main()
{
	int x = 424241;
	// int v[] = {1, 3, 4, 30, 32, 33, 35, 40, 41, 42,100, 120, 1000, 3000, 10000, 200000, 1000000};
	int v[AMOUNT];
	int i;
	clock_t clock_before;
	clock_t clock_after;

	/* Create elements for search */
	
	for (i = 0; i < AMOUNT; i++)
		v[i] = i;
	int n = sizeof(v)/sizeof(int);
	printf("Длина: %d\n", n);
	printf("Original function\n");
	int result = 0;
	clock_before = clock();
	for (int i = 0; i < 100000; i++)
		result = binsearch(x, v, n);
	result = binsearch(x, v, n);
	clock_after = clock();
	printf("Позиция: %d, Время выполнения: Clock: %lu, cекунд:  %ld\n", result, (clock_after - clock_before), (clock_after - clock_before) / CLOCKS_PER_SEC);

	printf("Solution function\n");
	result = 0;
	clock_before = clock();
	for (int i = 0; i < 100000; i++)
		result = binsearch_mod(x, v, n);
	result = binsearch_mod(x, v, n);
	clock_after = clock();
	printf("Позиция: %d, Время выполнения: Clock: %lu, cекунд:  %ld\n", result, (clock_after - clock_before), (clock_after - clock_before) / CLOCKS_PER_SEC);

	/* time test */

	


	return (0);
}
