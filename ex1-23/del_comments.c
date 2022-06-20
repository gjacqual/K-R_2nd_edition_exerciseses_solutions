/*
 * K&R ex1-23
 *
 * Created on Mon Jun 20 2022
 * 
 * clang -Wall -Wextra -Werror -o delcomments del_comments.c
 * Usage: ./delcomments < example.c > example_after.c
 * 
 * Max Filin
 * max@maxfilin.ru
 */

#include <stdio.h>

#define MAXLINE 20000
#define SPACE 	' '
#define TAB		'\t'
#define NEWLINE	'\n'

void del_comments(char to[], char from[]);
int gettext(char s[], int lim);

int main()
{
	char line[MAXLINE], format_line[MAXLINE];
	
	int len = 0;
	while ((len = gettext(line, MAXLINE)) > 0)
	{
		del_comments(format_line, line);
		printf("%s", format_line);
		// printf("%i", comment_flag);
	}
	return (0);
}

int gettext(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim && (c = getchar()) != EOF; ++i)
		s[i] = c;
	s[i] = '\0';
	return (i);
}

void del_comments(char to[], char from[])
{
	int i, j, comment_flag, quote_flag;

	i = j = comment_flag = quote_flag = 0;
	while ((to[j] = from[i]) != '\0')
	{			
		if (to[j] == '"')
		{
			if (quote_flag == 0)
				quote_flag = 1;
			else
				quote_flag = 0;
			++j;
		}
		else if (comment_flag == 0 && quote_flag == 0 && to[j] == '/' && from[i + 1] == '*')
		{
			comment_flag = 1;
			++i;
		}
		else if (comment_flag == 1 && quote_flag == 0 && to[j] == '*' && from[i + 1] == '/')
		{
			comment_flag = 0;
			++i;
		}
		else if (comment_flag == 0)
			++j;
		++i;
	}
}