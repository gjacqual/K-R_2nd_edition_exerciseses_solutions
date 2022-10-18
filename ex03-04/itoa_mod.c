/*
 * K&R ex3-4
 *
 * clang -Wall -Wextra -Werror -o itoa_mod itoa_mod.c
 * 
 * run: ./itoa_mod
 *
 * Exercise 3-4 In a two's complement number representation, our version of itoa
 * does not handle the largest negative number, that is, the value of n equal 
 * to -(2 to the power (wordsize - 1)) . Explain why not. Modify it to print 
 * that value correctly regardless of the machine on which it runs.
 *
 * Max Filin 2022
 */

#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define BUF 256


void reverse(char s[])
{
	int c, i , j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa_mod(int n, char s[])
{
	int i, sign;

	// if ((sign = n) < 0) 	/* записываем знак */
	// 	n = -n;				/* делаем число положительным */

	sign = n;
	i = 0;
	do 						/*  генерируем цифры в обратном порядке */
	{
		s[i++] = abs(n % 10) + '0'; /* извлекаем цифру */
	} while ((n /= 10));  /* удаляем цифру */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}


int main(void)
{
	char str[BUF];
	int number = 1234567890;

	itoa_mod(number, str);
	printf("Result: %d ===> %s\n",number, str);

	printf("INT_MIN: %d\n", INT_MIN);
	itoa_mod(INT_MIN, str);
	printf("Result:%d ===> %s\n", INT_MIN,  str);

	return (0);
}