/*
 * K&R ex1-24
 *
 * Created on Mon Jun 20 2022
 * 
 * clang -Wall -Wextra -Werror -o c_syntax c_syntax.c
 * Usage: ./c_syntax < example.c > example_after.c
 * 
 * Max Filin
 * max@maxfilin.ru
 */

#include <stdio.h>

#define MAXLINE 		100
#define SINGLE_QUOTE 	'\''
#define DOUBLE_QUOTE 	'"'

void	c_syntax(char line[]);
int		knr_getline(char s[], int lim);
void	print_result(void);

int g_brackets = 0;		/* it is {} symbols */
int g_parentheses = 0;	/* it is () symbols */
int g_braces = 0;		/* it is [] symbols */
int squote = 0;
int dquote = 0;
int g_comment_flag = 0;

int main(void)
{
	char line[MAXLINE];
	
	int len = 0;
	while ((len = knr_getline(line, MAXLINE)) > 0)
	{
		c_syntax(line);
	}
	print_result();
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

void print_result(void)
{
	if (squote != 0)
		printf("%i \033[1;31munbalanced single quote found in the program\033[0m\n", squote);
	if (dquote != 0)
		printf("%i \033[1;31munbalanced double quote found in the program\033[0m\n", g_brackets);
	if (g_brackets > 0)
		printf("%i \033[1;31munbalanced '{' open bracket found in the program\033[0m\n", g_brackets);
	else if (g_brackets < 0)
		printf("%i \033[1;31munbalanced '}' close bracket found in the program\033[0m\n", -g_brackets);
	if (g_parentheses > 0)
		printf("%i \033[1;31munbalanced '(' open parenthesis found in the program\033[0m\n", g_parentheses);
	else if (g_parentheses < 0)
		printf("%i \033[1;31munbalanced ')' close parenthesis found in the program\033[0m\n", -g_parentheses);
	if (g_braces > 0)
		printf("%i \033[1;31munbalanced '[' open brace found in the program\033[0m\n", g_braces);
	else if (g_braces < 0)
		printf("%i \033[1;31munbalanced ']' close brace found in the program\033[0m\n", -g_braces);
	if (!squote && !dquote && !g_brackets && !g_parentheses && !g_braces)
		printf("\033[1;32mNo errors\033[0m\n");
}

/* brackets handler */
void brackets_handler(char symb)
{
	if (symb == '{'  && !dquote && !squote && !g_comment_flag)
		g_brackets++;
	if (symb == '}' && !dquote && !squote && !g_comment_flag) 
		g_brackets--;
}

/* parentheses handler */
void parentheses_handler(char symb)
{
	if (symb == '('  && !dquote && !squote && !g_comment_flag)
		g_parentheses++;
	if (symb == ')' && !dquote && !squote && !g_comment_flag) 
		g_parentheses--;
}

/* braces handler */
void braces_handler(char symb)
{
	if (symb == '['  && !dquote && !squote && !g_comment_flag)
		g_braces++;
	if (symb == ']' && !dquote && !squote && !g_comment_flag) 
		g_braces--;
}

void c_syntax(char line[])
{
	int i, symb;

	i = 0;
	while ((symb = line[i]) != '\0')
	{			
		if (!g_comment_flag && !squote && !dquote \
		&& symb == '/' && line[i + 1] == '*')
			g_comment_flag = 1;
		if (g_comment_flag && !squote && !dquote \
		&& symb == '*' && line[i + 1] == '/')
			g_comment_flag = 0;
		if (symb == SINGLE_QUOTE && squote == 0)
			++squote;
		else if (symb == SINGLE_QUOTE && squote > 0)
			--squote;
		if (symb == DOUBLE_QUOTE && dquote == 0)
			++dquote;
		else if (symb == DOUBLE_QUOTE && dquote > 0)
			--dquote;
		braces_handler(symb);	
		brackets_handler(symb);
		parentheses_handler(symb);
		++i;
	}
}