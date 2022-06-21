#include <stdio.h>

float	fahr_celsius_convert(float fahr);

int	main(void)
{
	float	fahr;
	int		lower;
	int		upper;
	int		step;

	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;
	printf("Temperature table in Fahrenheiе and Celsius\n");
	while (fahr <= upper)
	{
		printf("%3.0f\t%6.1f\n", fahr, fahr_celsius_convert(fahr));
		fahr = fahr + step;
	}
	return (0);
}

float	fahr_celsius_convert(float fahr)
{	
	return ((5.0 / 9.0) * (fahr - 32.0));
}
