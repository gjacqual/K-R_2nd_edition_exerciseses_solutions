#include <stdio.h>

#define MAXLINE 1000

int knr_getline(char line[], int maxline);
void reverse(char s[], int len);
void copy (char to[], char from[]);

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
		reverse(line, len);
		if (len > 0)
			printf("%s\n", line);
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

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

void reverse(char s[], int len)
{
	int i;
	char s_tmp[MAXLINE];
	copy(s_tmp, s);
	i = 0;
	len--;
	while(s[len] > 0)
	{
		s[len] = s_tmp[i];
		--len;
		++i;
	}
}