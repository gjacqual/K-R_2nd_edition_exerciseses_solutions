/*
 * K&R ex4-3
 *
 * clang -Wall -Wextra -Werror -o my_calculator my_calculator.c
 * 
 * run: ./my_calculator
 *
 * Exercise 4-3 Given the basic framework, it's straightforward to extend the 
 * calculator. Add the modulus ( % ) operator and provisions for negative 
 * numbers.
 *
 * Max Filin 2022
 */

#include <stdio.h>
#include <stdlib.h> /* для объявления atof()*/
#include <ctype.h>

#define MAXOP	100 /* максимальный размер операнда или знака */
#define NUMBER	'0' /* сигнал, что обнаружено число */
#define BUFSIZE	100

#define MAXVAL	100 /* максимальная глубина стека val */

int sp = 0;			/* следующая свободная позиция в стеке */
double val[MAXVAL];	/* стек операндов */
char buf[BUFSIZE]; /* буфера для ungetch */
int bufp = 0;

int getop(char s[]);
void push(double);
double pop(void);
int 	getch(void);
void	ungetch(int);

/* Калькулятор с обратной польской записью */
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch(type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero devisor\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknofn command %s\n", s);
				break;
		} 
	}
	return (0);
}

/* push: помещает число f в стек операндов */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: извлекает и позвращает верхнее число из стека */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/*getop: извлекает следующий операнд или знак операции */
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; /* не число */
	i = 0;
	if (isdigit(c)) /* накопление целой части */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') /* накопление дробной части */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}