#include <stdio.h>

#define TABSIZE 4
#define MAXLINE 1000

int knr_getline(char line[], int maxline);

 /* print all input lines that are longer than 80 characters */
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

 }

 int tabpos()