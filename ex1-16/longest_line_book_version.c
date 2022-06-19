#include <stdio.h>

 #define MAXLINE 1000

 int knr_getline(char line[], int maxline);
 void copy (char to[], char from[]);

 /* вывод самой длинной строки в потоке */
 int main()
 {
	int len;	/* длина текущей строки */
	int max;	/* текущая максимальня длина */
	char line[MAXLINE];	/* текущая введенная строка */
	char longest[MAXLINE]; /* the longest line entered */

	max = 0;
	while ((len = knr_getline(line, MAXLINE)) > 0)
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	if (max > 0) /* была не пустая строка */
		printf("Longest string is: %s", longest);
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