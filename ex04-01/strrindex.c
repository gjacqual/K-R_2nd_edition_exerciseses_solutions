/*
 * K&R ex4-1
 *
 * clang -Wall -Wextra -Werror -o strrindex strrindex.c
 * 
 * run: ./strrindex
 *
 * Exercise 4-1 Write the function strrindex(s,t) , which returns the position
 * of the rightmost occurrence of t in s , or -1 if there is none.
 *
 * Max Filin 2022
 */

#include <string.h>
#include <stdio.h>
#include <unistd.h>

int strrindex(char s[], char t[])
{
	int i, j, k;
	int len;

	len = strlen(s);
	
	for (i = len - 1; i >= 0; i--)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;		
	}
	return -1;
}	

int main(void)
{
	char s[] = "This test is test string in the test text";
	char t[] = "test";
	int index;

	char no_t[] = "terk";

	index = strrindex(s, t);
	printf("Result: %s ===> %d\n",t, index);

	for (; s[index] != ' '; index++ )
		write(1, &s[index], 1);
	printf("\n");

	index = strrindex(s, no_t);
	printf("Result: %s ===> %d\n",no_t, index);


	return (0);
}
