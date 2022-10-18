/*
 * K&R ex3-2
 *
 * clang -Wall -Wextra -Werror -o escape escape.c
 * 
 * run: ./make_tabs | ./escape
 *
 * Exercise 3-2  Write a function escape(s,t) that converts characters like 
 * newline and tab into visible escape sequences like \n and \t as it copies 
 * the string t to s . Use a switch . Write a function for the other direction 
 * as well, converting escape sequences into the real characters
 *
 * Max Filin 2022
 */

#include <stdio.h>

void escape(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (t[i] != '\0')
	{
		switch (t[i])
		{
		case '\t':
			s[j] = '\\';
			j++;
			s[j] = 't';
			j++;
			i++;
			break;
		case '\n':
			s[j] = '\\';
			j++;
			s[j] = 'n';
			j++;
			i++;
			break;
		
		default:
			s[j] = t[i];
			i++;
			j++;
			break;
		}
	}
}

void de_escape(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (t[i] != '\0')
	{
		switch (t[i])
		{
		case '\\':
			i++;
			if (t[i] == 't')
				s[j] = '\t';
			if (t[i] == 'n')
				s[j] = '\n'; 
			i++;
			j++;
			break;
		default:
			s[j] = t[i];
			i++;
			j++;
			break;
		}
	}
	s[j] = '\0';
}


int main()
{
	
	char str1[256];
	char str2[256];
	char str3[256];
	
	int c, sp, i;

	sp = 0;
	i = 0;
	while ((c = getchar()) != EOF)
	{	
		str1[i] = c;
		i++;
	}
	
	printf("Start: string1: %s\nstring2: %s\n\n", str1, str2);
	escape(str2, str1);
	printf("escape() result: string1: %s\nstring2: %s\n\n", str1, str2);

	printf("Start2: string2: %s\nstring3: %s\n\n", str2, str3);
	de_escape(str3, str2);
	printf("de_escape() result: string2: %s\nstring3: %s\n", str2, str3);
	
	return (0);

}


