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
float	calc_float_max(void);
void	print_limits(void);
double	calc_double_float_max(void);
long double	calc_long_double_float_max(void);

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
	float 				min_float, max_float;
	double				min_double, max_double;
	long double			min_ldouble, max_ldouble;

	/* Print form standatr lib limits */
	print_limits();

	/* Print the limits calculated in the code */
	printf("------------------------------CALCULATE----------------------------\n");
	printf("------------------------------Int----------------------------------\n");
	
	/* Char */
	min_uchar = max_uchar = 0;
	--max_uchar;
	max_schar = min_schar = calc_char_min();
	--max_schar;
	printf("char		-> min: %d,			max:%d\n", min_schar, max_schar);
	printf("unsigned char	-> min: %d,			max:%d\n", min_uchar, max_uchar);
	
	/* Short */
	min_short = 0;
	min_short = calc_short_min();
	printf("short		-> min: %d,			max:%d\n", min_short, calc_short_max(min_short));
	min_ushort = max_ushort = 0;
	--max_ushort;
	printf("unsigned short	-> min: %u,			max:%u\n", min_ushort, max_ushort);
	
	/* Int */
	min_uint = max_uint = 0;
	--max_uint;
	min_sint = max_sint = max_uint / 2;
	++min_sint;
	printf("int   		-> min: %i,		max:%i\n", min_sint, max_sint);
	printf("unsigned int	-> min: %u,			max:%u\n", min_uint, max_uint);
	
	/* Long */
	min_ulong = max_ulong = 0;
	--max_ulong;
	min_slong = max_slong = max_ulong / 2;
	++min_slong;
	printf("long  		-> min: %ld,	max:%ld\n", min_slong, max_slong);
	printf("unsigned long	-> min: %lu,			max:%lu\n", min_ulong, max_ulong);
	
/*
	Type			Storage size				Value range
	float			4 byte	(32 bits)			1.2E-38 to 3.4E+38
	double			8 byte	(64 bits)			2.3E-308 to 1.7E+308
	long double		10 byte	(80 bits)			3.4E-4932 to 1.1E+4932
*/
	
	printf("------------------------------Floats-------------------------------\n");
	
	/* Float */
	min_float = pow(2, -126);
	max_float = calc_float_max();
	printf("float 		-> min: %f, 		max:%f\n", min_float, max_float);

	/* Double */
	min_double = pow(2, -1022);
	max_double = calc_double_float_max();

	printf("double		-> min: %e,		max:%e\n", min_double, max_double);
	
	/* Long double */
	min_ldouble = powl(2, -16382); // powl - version pow for long double
	max_ldouble = calc_long_double_float_max();
	printf("long double	-> min: %Le,		max:%Le\n", min_ldouble, max_ldouble);
	return (0);
}

void	print_limits(void)
{
	printf("------------------------------Int----------------------------\n");
	printf("Ranges of char, short, int, long\n");
	printf("char  		-> min: %i,			max:%i\n", CHAR_MIN, CHAR_MAX);
	printf("unsigned char	-> min: %d,			max:%d\n", 0, UCHAR_MAX);
	printf("short 		-> min: %i,			max:%i\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short	-> min: %i,			max:%i\n", 0, USHRT_MAX);
	printf("int   		-> min: %i,		max:%i\n", INT_MIN, INT_MAX);
	printf("unsigned int	-> min: %i,			max:%u\n", 0, UINT_MAX);
	printf("long  		-> min: %ld,	max:%ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long	-> min: %i,			max:%lu\n", 0, ULONG_MAX);
	printf("------------------------------Floats--------------------------\n");
	printf("float		-> min: %f,		max:%f\n", FLT_MIN, FLT_MAX);
	printf("double		-> min: %e,		max:%e\n", DBL_MIN, DBL_MAX);
	printf("long double	-> min: %Le,		max:%Le\n\n\n", LDBL_MIN, LDBL_MAX);
}

float	calc_float_max(void)
{
	int		i;
	float	mantissa;

	mantissa = 1;
	i = 1;
	while (i < 24)
	{
		mantissa += pow(2, -i);
		++i;
	}	
	return (mantissa * pow(2, 127));
}

double	calc_double_float_max(void)
{
	int		i;
	double	mantissa;

	mantissa = 1;
	i = 1;
	while (i < 52)
	{
		mantissa += pow(2, -i);
		++i;
	}	
	return (mantissa * pow(2, 1023));
}

long double	calc_long_double_float_max(void)
{
	int		i;
	long double	mantissa;

	mantissa = 1;
	i = 1;
	while (i < 63)
	{
		mantissa += pow(2, -i);
		++i;
	}	
	return (mantissa * powl(2, 16383));
}

short	calc_short_min(void)
{
	short	shrt = 1;

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


