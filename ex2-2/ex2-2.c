/*
 * K&R ex2-2
 * 
 * clang -Wall -Wextra -Werror -o ex2-2 ex2-2.c
 * 
 * Exercise 2-2 Write a loop equivalent to the for loop 
 * above without using && or || 
 * 
 * Max Filin 2022
 */

#include <stdio.h>

 #define MAXLINE 100

 int knr_getline(char line[], int maxline);

 /* вывод самой длинной строки в потоке */
 int main()
 {
	int len;	
	char line[MAXLINE];	

	len = 0;
	len = knr_getline(line, MAXLINE);
	if (len > 0) /* была не пустая строка */
		printf("String: %s", line);
	return (0);
 }

 int knr_getline(char s[], int lim)
 {
	int c, i;
/* Exercise Target -  Write a loop equivalent to the for loop
 above without using && or ||*/
	i = 0;
	while (1)
	{
		if (i == lim - 1)
			break ;
		if ((c = getchar()) == '\n')
			break ;
		if (c == EOF)
			break ;
		s[i] = c;
		++i;
	}
/* end */
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return (i);
 }