/*
 * K&R ex2-2
 * 
 * clang -Wall -Wextra -Werror -o htoi htoi.c
 * 
 * Exercise 2-2 Write a function htoi(), which converts a string of 
 * hexadecimal digits 
 * (including an optional 0x or 0X)into its equivalent integer value. 
 * The allowable digits are 0 through 9, a through f, and A through F.
 *
 * Max Filin 2022
 */

#include <stdio.h>

int htoi(char s[]);

int	main(void)
{
	int		number;
	char	s[] = "FFFAAA1";

	number = htoi(s);
	printf("Number: %d\n", number);
	return (0);
}

int	htoi(char s[])
{
	int i = 0;
	int number = 0; 

	while(s[i] != '\0')
	{
		number = number * 16 + s[i];
		i++;
	}
	return (number);
}
