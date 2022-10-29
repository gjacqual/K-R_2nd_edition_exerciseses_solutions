/*
 * K&R ex4-4
 *
 * clang -Wall -Wextra -Werror -o my_calculator my_calculator.c -lm
 * 
 * run: ./my_calculator
 * 
 * USAGE:
 * 
 * P - print all stack
 * T - print top
 * C - clear stack
 * D - duplicate element
 * S - swap the top two elements
 * 
 *
 * Exercise 4-4 Add commands to print the top element of the stack without 
 * popping, to duplicate it, and to swap the top two elements. Add a command to 
 * clear the stack.
 *
 * Max Filin 2022
 */

#include <stdio.h>
#include <stdlib.h> /* для объявления atof()*/
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define MAXOP	100 /* максимальный размер операнда или знака */
#define NUMBER	'0' /* сигнал, что обнаружено число */
#define BUFSIZE	100

#define MAXVAL	100 /* максимальная глубина стека val */

int		sp = 0;			/* следующая свободная позиция в стеке */
double	val[MAXVAL];	/* стек операндов */
char	buf[BUFSIZE]; /* буфера для ungetch */
int		bufp = 0;

int		getop(char s[]);
void	push(double);
double	pop(void);
int		getch(void);
void	ungetch(int);
bool	isint(double d);
void	print_top(void);
void	print_stack(void);
void	clear_stack(void);
void	doublicate_element(double f);
void	swap_elements(void);

/* Калькулятор с обратной польской записью */
int	main(void)
{
	int		type, command_flag;
	double	op2, op;
	char	s[MAXOP];

	command_flag = 0;
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
			case '%':
				op2 = pop();
				op = pop();
				if (op2 != 0.0)
					push(fmod(op, op2));
				else
					printf("error: zero devisor\n");
				break;
			case 'T':
				command_flag = 1;
				print_top();
				break;
			case 'C':
				command_flag = 1;
				clear_stack();
				break;
			case 'D':
				command_flag = 1;
				doublicate_element(val[0]);
				break;
			case 'S':
				command_flag = 1;
				swap_elements();
				break;
			case 'P':
				command_flag = 1;
				print_stack();
				break;
			case '\n':
				if (!command_flag)
					printf("\t%.8g\n", pop());
				else 
					command_flag = 0;
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		} 
	}
	
	return (0);
}

void swap_elements(void)
{
	double temp;

	temp = val[0];
	val[0] = val[1];
	val[1] = temp;
}

void doublicate_element(double f)
{
	int temp_sp = sp;
	if (temp_sp < MAXVAL)
		val[++sp] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

void print_stack(void)
{
	for (int i = 0; i < 10; i++)
		printf("%g\t", val[i]);
	printf("\n");
	// printf("sp: %d\n", sp);
}

void clear_stack(void)
{
	int temp_sp;

	temp_sp = sp + 1;
	while(temp_sp >= 0)
		val[temp_sp--] = 0.0;
	sp = 0;
}

void print_top(void)
{
	printf("\t%.8g\n", val[0]);
}

bool isint(double d) 
{
	return d == (int64_t)d;
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
	int i, c, temp_c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
	{
		// printf("getop: not a number\n");
		return c; /* не число */
	}
	i = 0;
	if (c == '-')
	{
		temp_c  = c;
		if (!isdigit(s[++i] = c = getch())) /* для обработки отрицательных чисел */
		{
			if (c != EOF)
				ungetch(c);
			return temp_c;
		}
	}
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
