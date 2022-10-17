/*
 * K&R ex2-10
 * 
 * clang -Wall -Wextra -Werror -o lower_mod lower_mod.c
 * 
 * Exercise 2-10  Rewrite the function lower, which converts upper case letters 
 * to lower case, with a conditional expression instead of if-else .
 * 
 * Max Filin 2022
 */

#include <stdio.h>

int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int lower_before(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

int main(void)
{
	char text[] = "TEXt STrInG";

	printf("Before: %s\n", text);
	for (int i = 0; text[i] != '\0'; i++)
	{
		text[i] = lower(text[i]);
	}
	printf("After : %s\n", text);

	return (0);
}
