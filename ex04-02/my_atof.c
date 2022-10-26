/*
 * K&R ex4-2
 *
 * clang -Wall -Wextra -Werror -o my_atof my_atof.c
 * 
 * run: ./my_atof
 *
 * Exercise 4-2 Extend atof to handle scientific notation of the form 123.45e-6 
 * where a floating-point number may be followed by e or E and an optionally signed exponent.
 *
 * Max Filin 2022
 */

#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

/* atof преобразование строки s в число типа double */

int my_getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}


double	my_atof(char s[])
{
	double val, power;
	int i, sign, exp, exp_sign;

	exp = 0;
	for(i = 0; isspace(s[i]); i++) /* пропуск пробелов */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if (s[i] == 'e' || s[i] == 'E')
	{
		i++;
		exp_sign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			i++;
		for(exp = 0; isdigit(s[i]); i++)
			exp = 10 * exp + (s[i] - '0');
		if (exp_sign < 0)
		{
			while (exp > 0) 
			{
				power *= 10;
				exp--;
			}
		}
		else 
		{
			while (exp > 0) 
			{
				power /= 10;
				exp--;
			}
		}
	}
	return sign * val / power;

}


int main(void)
{
	double sum, my_atof(char []);
	char line[MAXLINE];
	int my_getline(char line[], int max);

	sum = 0;
	while (my_getline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += my_atof(line));
	return (0);
}
