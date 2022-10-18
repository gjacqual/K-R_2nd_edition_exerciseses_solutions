/*
 * K&R ex3-3
 *
 * clang -Wall -Wextra -Werror -o expand expand.c
 * 
 * run: ./expand
 *
 * Exercise 3-3 Write a function expand(s1,s2) that expands shorthand notations 
 * like a-z in the string s1 into the equivalent complete list abc...xyz in s2 . 
 * Allow for letters of either case and digits, and be prepared to handle cases 
 * like a-b-c and a-z0-9 and -a-z . Arrange that a leading or trailing - is 
 * taken literally.
 *
 * Max Filin 2022
 */

#include <string.h>
#include <stdio.h>
#define BUF 256

void expand(char s1[], char s2[])
{
	int i, j;
	int start;
	int end;
	int current;
	int len;
	
	i = 0;
	j = 0;

	len = strlen(s1);

	for (; s1[i] != '\0'; i++ )
	{
		if (s1[i] == '-')
		{
			if (i == 0 )
			{
				s2[j] = s1[i];
				j++;
				continue;
			}
			else if (i != len - 1)
			{

				start = s1[i - 1];
				end = s1[i + 1];
				current = start;
				while (current != end)
				{
					s2[j] = current;
					j++;
					current++;
				}
			}
			s2[j] = end;
			if (i == len - 1)
			{
				j++;
				s2[j] = s1[i];
			}
		}
	}
	s2[++j] = '\0';
}


void clear_string(char str[])
{
	int i;
	for (i = 0; str[i]; i++)
		str[i] = '\0';
}

int main(void)
{
	char *str1[] = {"-a-c-", "a-z", "a-b-c", "R-Z", "a-z0-9", "-a-z", "a-t-", NULL};	
	char str2[BUF];
	int i;

	for (i = 0; str1[i]; i++)
	{
		printf("Before: s1 = %s, s2 = %s\n", str1[i], str2);
		expand(str1[i], str2);
		printf("After: s2 = %s\n\n", str2);
		clear_string(str2);
	}



}



