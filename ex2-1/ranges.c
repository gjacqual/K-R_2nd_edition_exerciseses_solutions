/*
 * K&R ex2-1
 * Created on Sat Jun 25 2022
 *
 * clang -Wall -Wextra -Werror -o ranges ranges.c -lm
 * 
 * Max Filin 2022
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

char	calc_char_min(void);
short	calc_short_min(void);
short	calc_short_max(short number);

int main(void)
{
	short				min_short;
	unsigned int		min_uint, max_uint;
	int					min_sint, max_sint;
	unsigned short		min_ushort, max_ushort;
	unsigned char		min_uchar, max_uchar;
	char				min_schar, max_schar;
	unsigned long int	min_ulong, max_ulong;
	long int			min_slong, max_slong;
	float 				min_float, max_float, mantissa;
	int 				i;

	printf("Ranges of char, short, int, long\n");
	printf("char  		-> min: %i,			max:%i\n", CHAR_MIN, CHAR_MAX);
	printf("unsigned char	-> min: %d,			max:%d\n", 0, UCHAR_MAX);
	printf("short 		-> min: %i,			max:%i\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short	-> min: %i,			max:%i\n", 0, USHRT_MAX);
	printf("int   		-> min: %i,		max:%i\n", INT_MIN, INT_MAX);
	printf("unsigned int	-> min: %i,			max:%u\n", 0, UINT_MAX);
	printf("long  		-> min: %ld,	max:%ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long	-> min: %i,			max:%lu\n", 0, ULONG_MAX);
	printf("-------------------Floats------------------------\n");
	printf("float		-> min: %e,		max:%e\n", FLT_MIN, FLT_MAX);
	printf("double		-> min: %e,		max:%e\n", DBL_MIN, DBL_MAX);
	printf("long double	-> min: %Le,		max:%Le\n", LDBL_MIN, LDBL_MAX);

	printf("-------------------CALCULATE------------------------\n");
	min_uchar = max_uchar = 0;
	--max_uchar;
	max_schar = min_schar = calc_char_min();
	--max_schar;
	printf("char		-> min: %d,			max:%d\n", min_schar, max_schar);
	printf("unsigned char	-> min: %d,			max:%d\n", min_uchar, max_uchar);
	min_short = 0;
	min_short = calc_short_min();
	printf("short		-> min: %d,			max:%d\n", min_short, calc_short_max(min_short));
	min_ushort = max_ushort = 0;
	--max_ushort;
	printf("unsigned short	-> min: %u,			max:%u\n", min_ushort, max_ushort);

	min_uint = max_uint = 0;
	--max_uint;
	min_sint = max_sint = max_uint / 2;
	++min_sint;
	printf("int   		-> min: %i,		max:%i\n", min_sint, max_sint);
	printf("unsigned int	-> min: %u,			max:%u\n", min_uint, max_uint);
	min_ulong = max_ulong = 0;
	--max_ulong;
	min_slong = max_slong = max_ulong / 2;
	++min_slong;
	printf("long  		-> min: %ld,	max:%ld\n", min_slong, max_slong);
	printf("unsigned long	-> min: %lu,			max:%lu\n", min_ulong, max_ulong);
	min_float = pow(2, -126);
	mantissa = 1;
	i = 1;
	while (i < 24)
	{
		mantissa += pow(2, -i);
		++i;
	}	
	max_float = mantissa * pow(2, 127);
	printf("float 		-> min: %e, 		max:%e\n", min_float, max_float);
	// Изучить вещественные числа в Си и определение их границ;
	
	// printf("double		-> min: %lf,		max:%e\n", DBL_MIN, DBL_MAX);
	// printf("long double	-> min: %Le,		max:%Le\n", LDBL_MIN, LDBL_MAX);
	return (0);
}

short	calc_short_min(void)
{
	short shrt = 1;

	while (shrt > shrt - 1)
	{
		if (shrt < 0)
			break ;
		++shrt;
	}

	return (shrt);
}

char	calc_char_min(void)
{
	char char1 = 1;

	while (char1 > char1 - 1)
	{
		if (char1 < 0)
			break ;
		++char1;
	}

	return (char1);
}

short	calc_short_max(short number)
{
	--number;
	return (number);
}
