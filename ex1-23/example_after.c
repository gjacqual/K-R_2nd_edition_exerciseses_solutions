

#include <stdio.h>

#define MAXLINE 1000
#define LINE_COLS 40
#define TABSIZE 4
#define SPACE 	' '
#define TAB		'\t'
#define COMMENT	"/* test comment */"

int knr_getline(char line[], int maxline);
void string_format(char to[], char from[], int n);
void detab(char tab_line[], char detab_line[]); 
int main()
{
	char line[MAXLINE], format_line[MAXLINE], detab_line[MAXLINE];
	
	printf(" Example /*comment here */\n Comment was before\n");
	printf(COMMENT);
	int len = 0;
	while ((len = knr_getline(line, MAXLINE)) > 0)
	{
		detab(line, detab_line);
		string_format(format_line, detab_line, LINE_COLS);
		printf("%s", format_line);
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

void string_format(char to[], char from[], int n)
{
	int i, j;
	int cur_pos;
		i = j = 0;
		cur_pos = 0;
		while ((to[j] = from[i]) != '\0')
		{			
			if (cur_pos == n)
			{
				while (from[i] != SPACE)
				{
					i--;
					j--;
				}
				if (from[i] == SPACE)
				{
					to[j] = '\n';
					cur_pos = 0;
				}
			}
			++cur_pos;
			++i;
			++j;
		}
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
