#include <stdio.h>

int main()
{
	int c;
	c = (getchar() != EOF);
	printf("EOF value on my system: %d\n", c);
	return 0;
}