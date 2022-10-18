/*
 * K&R ex3-5
 *
 * clang -Wall -Wextra -Werror -o itob itob.c
 * 
 * run: ./itoa_mod
 *
 * Exercise 3-5 Write the function itob(n,s,b) that converts the integer n into 
 * a base b character representation in the string s. 
 * In particular, itob(n,s,16) formats n as a hexadecimal integer in s.
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

void itob(int n, char s[], int b)
{
	int i, sign;
	char symbols[] = "0123456789ABCDEF";


	if (s == NULL || b < 2)
	{
		printf("Error: Incorect arguments\n");
		return ;
	}
	sign = n;
	i = 0;
	do 						/*  генерируем цифры в обратном порядке */
	{
		s[i++] = symbols[abs(n % b)]; /* извлекаем цифру */
	} while ((n /= b));  /* удаляем цифру */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}


int main(void)
{
	char str[BUF];
	int number = 255;
	int base;
	int i;

	for (i = 0; i < 17; i++)
	{
	
	base = i;
	printf("Test %d: %d, Base = %d\n", i, number, base);
	itob(number, str, base);
	printf("Result: %d ===> %s\n",number, str);
	
	itob(INT_MIN, str, base);
	printf("Result INT_MIN:%d ===> %s\n", INT_MIN,  str);
	printf("------------------------------------------------------------------\n");
	}

	return (0);
}

