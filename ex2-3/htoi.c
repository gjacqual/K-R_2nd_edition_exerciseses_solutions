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
#include <ctype.h>

int htoi(char s[]);

int	main(void)
{
	int		number;
	char	s[] = "0XFFFfff";

	number = htoi(s);
	printf("Number: %d\n", number);
	return (0);
}

int	htoi(char s[])
{
	int i;
	int j;
	int number = 0;
	char hex[] = "0123456789ABCDEF"; 

	i = 0;
	if (s[i] == '0' && toupper(s[i+1]) == 'X')
		i = 2;
	while(s[i] != '\0')
	{	
		j = 0;
		while(hex[j] != '\0')
		{
			if (hex[j] == toupper(s[i]))
				break ;
			if (j == 15 && toupper(s[i]) != 'F') 
			{
				printf("Error: incorect input!\n");
				return -1;
			}
			j++;
		}
		
		number = number * 16 + j;
		i++;
	}
	return (number);
}
