#include <stdio.h>

int main() {
	int c, sp;

	sp = 0;
	while ((c = getchar()) != EOF)
	{
		if (c != ' ')
		{
			putchar(c);
			sp = 0;
		}
		else if (sp == 0)
		{
			putchar(c);
			sp = 1;
		}
	}
	printf("\n");
	return 0;
}
