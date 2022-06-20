/*
 * K&R ex1-21
 * Created on Mon Jun 20 2022
 *
 * clang -Wall -Wextra -Werror -o entab entab.c
 * Usage: ./entab < text_before.txt > text_after.txt
 *
 * Max Filin
 * max@maxfilin.ru
 */

#include <stdio.h>

#define TABSIZE 4
#define MAXLINE 1000
#define SPACE 	' '
#define TAB		'\t'

int knr_getline(char line[], int maxline);
void entab(char line[], char entab_line[]);


 int main()
 {
	char line[MAXLINE], detab_line[MAXLINE];
	int len = 0;

	while ((len = knr_getline(line, MAXLINE)) > 0)
	{
		entab(line, detab_line);
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

 void entab(char line[], char entab_line[])
 {
	int tabstop;
	int i, j, sp_count, tb_count;

	tabstop = TABSIZE;
	i = j = sp_count = tb_count = 0;
	while ((entab_line[j] = line[i]) != '\0')
	{
		if (entab_line[j] == SPACE)
			++sp_count;
		else if (entab_line[j] != SPACE)
			sp_count = 0;
		if (sp_count == tabstop)
		{
			j -= 3;
			entab_line[j] = TAB;
			j++;
			sp_count = 0;		
		}
		else
			++j;
		++i;
	}
 }
