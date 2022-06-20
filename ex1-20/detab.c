#include <stdio.h>

#define TABSIZE 8
#define MAXLINE 1000
#define SPACE 	' '
#define TAB		'\t'

int knr_getline(char line[], int maxline);
 void detab(char tab_line[], char detab_line[]);

 /* print all input lines that are longer than 80 characters */
 /* clang -Wall -Wextra -Werror -o detab detab.c */
 /* Usage: ./detab < text_with_tabs.txt > text_detab.txt */
 int main()
 {
	char line[MAXLINE], detab_line[MAXLINE];
	int len = 0;

	while ((len = knr_getline(line, MAXLINE)) > 0)
	{
		detab(line, detab_line);
		printf("%s", detab_line);
	}
	return (0);
 }


 int knr_getline(char s[], int lim)
 {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return (i);
 }

 void detab(char tab_line[], char detab_line[])
 {
	int i, j, n;

	i = 0;
	j = 0;
	while ((detab_line[j] = tab_line[i]) != '\0')
	{
		if (detab_line[j] == TAB)
			{
				n = 0;	
				while (n < TABSIZE)
				{
					detab_line[j] = SPACE;
					++n;
					++j;
				}
			}
		else
			++j;
		++i;
	}
 }
