#include <stdio.h>

#define MAXLINE 1000

int knr_getline(char line[], int maxline);
void copy (char to[], char from[]);
int clear_spaces(char str[], int len);

 /* print all input lines that are longer than 80 characters */
 int main()
 {
	int len, max;
	char line[MAXLINE];
	
	len = max = 0;
	while ((len = knr_getline(line, MAXLINE)) > 0)
	{
		if (line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
			len = len -1;
		}
		len = clear_spaces(line, len);
		if (len > 0)
			printf("%s(length: %i)\n", line, len);
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

int clear_spaces(char str[], int len)
 {
	while (str[--len] > 0 && (str[len] == ' ' || str[len] == '\t'))
		;
	str[len + 1] = '\0';
	return len + 1;
 }