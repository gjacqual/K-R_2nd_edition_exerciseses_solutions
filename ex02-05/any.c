/*
 * K&R ex2-5
 * 
 * clang -Wall -Wextra -Werror -o any any.c
 * 
 * Write the function any(s1,s2) , which returns the first location in the 
 * string s1 where any character from the string s2 occurs, or -1 if s1 
 * contains no characters from s2 . (The standard library function strpbrk does 
 * the same job but returns a pointer to the location.)
 * 
 * Max Filin 2022
 */
#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[])
{
	int	i, j;
	if (s1 == NULL || s2 == NULL)
		return -1;
	for (i = 0; s2[i] != '\0'; i++)
	{
		for (j = 0; s1[j] != '\0'; j++)
			if (s1[j] == s2[i])
				return j;
	}
	return -1;
}

int	main(void)
{	
	char string1[] = "0123456789abcdef";
	char string2[] = "f";
	char string3[] = "uc";
	char string4[] = "xs6";
	char string5[] = "wzup";
	char string_empty[] = "";
	char string6[0];

	char* string_null = NULL;
	char* string_null2 = NULL;

	/*test 1 */
	printf("1) My function any(): %d\n", any(string1, string2));
	printf("   strpbrk output: %c\n", strpbrk(string1, string2)[0]);

	/*test 2 */
	printf("2) My function any(): %d\n", any(string1, string3));
	printf("   strpbrk output: %c\n", strpbrk(string1, string3)[0]);

	/*test 3 */
	printf("3) My function any(): %d\n", any(string1, string4));
	printf("   strpbrk output: %c\n", strpbrk(string1, string4)[0]);

	/*test 4 */
	printf("4) My function any(): %d\n", any(string1, string5));
	printf("   strpbrk output: %s\n", strpbrk(string1, string5));

	/*test 5 */
	printf("5) My function any(): %d\n", any(string_empty, string5));
	printf("   strpbrk output: %s\n", strpbrk(string_empty, string5));

	/*test 6 */
	printf("6) My function any(): %d\n", any(string1, string_empty));
	printf("   strpbrk output: %s\n", strpbrk(string1, string_empty));

	/*test 7 */
	printf("7) My function any(): %d\n", any(string1, string6));
	printf("   strpbrk output: %s\n", strpbrk(string1, string6));

	/*test 8 */
	printf("8) My function any(): %d\n", any(string_null, string_null2));
	// printf("   strpbrk output: %s\n", strpbrk(string_null, string_null2));


	return (1);
}
