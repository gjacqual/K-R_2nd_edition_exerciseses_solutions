/*
 * K&R ex3-6
 *
 * clang -Wall -Wextra -Werror -o itoa_mod2 itoa_mod2.c
 * 
 * run: ./itoa_mod
 *
 * Exercise 3-6 Write a version of itoa that accepts three arguments instead 
 * of two. The third argument is a minimum field width; the converted number 
 * must be padded with blanks on the left if necessary to make it wide enough.
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


int int_len(int n)
{
 	int num_len;
	int sign;
	double num = n;

	num_len = 0;
	if ((sign = num) < 0) 
		num = -num;			
	if (sign < 0)
		num_len++;
	while (num > 0)
	{
		num /= 10;
		num_len++;
	}
	
	return num_len;
}

void itoa_mod(int n, char s[], int min_width)
{
	int i, sign, numb_len, width;

	sign = n;
	i = 0;
	numb_len = int_len(n);
	do 						/*  генерируем цифры в обратном порядке */
	{
		s[i++] = abs(n % 10) + '0'; /* извлекаем цифру */
	} while ((n /= 10));  /* удаляем цифру */
	if (sign < 0)
		s[i++] = '-';
	
	width = min_width - numb_len;
	while (width > 0)
	{
		s[i++] = ' ';
		width--;
	}
	s[i] = '\0';
	reverse(s);
}


int main(void)
{
	char str[BUF];
	int min_width = 10;

	itoa_mod(-123, str, min_width);
	printf("Result: %d ===> |%s|\n", -123, str);

	itoa_mod(123, str, min_width);
	printf("Result:  %d ===> |%s|\n", 123, str);

	itoa_mod(INT_MIN, str, min_width);
	printf("Result:  %d ===> |%s|\n", INT_MIN, str);

	itoa_mod(INT_MAX, str, min_width);
	printf("Result:   %d ===> |%s|\n", INT_MAX, str);


	return (0);
}