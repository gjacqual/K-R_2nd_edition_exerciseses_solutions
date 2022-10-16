/*
 * K&R ex2-4
 * 
 * clang -Wall -Wextra -Werror -o squeeze squeeze.c
 * 
 * Write an alternate version of squeeze(s1,s2) that deletes each character in the string s1 that matches any character in the string s2 
 * Max Filin 2022
 */

#include <stdio.h>

void	squeeze(char s1[], char s2[])
{
	int	i, j, k;
	for (k = 0; s2[k] != '\0'; k++)
	{
		for (i = j = 0; s1[i] != '\0'; i++)
			if (s1[i] != s2[k])
				s1[j++] = s1[i];
		s1[j] = '\0';
	}

}


int	main(void)
{	
	char string1[] = "test string";
	char string2[] = "ters ";

	printf("%s\n", string1);
	squeeze(string1, string2);
	printf("%s\n", string1);

	return (1);
}
