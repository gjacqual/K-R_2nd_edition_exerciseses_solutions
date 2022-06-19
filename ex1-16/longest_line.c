#include <stdio.h>

 #define MAXLINE 30

 int knr_getline(char line[], int maxline);
 void copy (char to[], char from[]);

 /* вывод самой длинной строки в потоке */
 int main()
 {
	int len, max, temp_len;
	char line[MAXLINE], longest[MAXLINE];
	
	len = max = 0;
	while ((temp_len = knr_getline(line, MAXLINE)) > 0)
	{
		len = len + temp_len;
		if (temp_len != MAXLINE - 1)
		{
			if (len > max)
			{
				max = len;
				copy(longest, line);
			}
			len = 0;
		}
	}
	if (max > 0)
		printf("Longest string length is: %i\n",  max);
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