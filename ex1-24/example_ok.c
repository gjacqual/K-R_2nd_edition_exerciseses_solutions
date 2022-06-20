#include <stdio.h>
#define MAXLINE 1000
#define COMMENT	"/* test comment */"

int knr_getline(char line[], int maxline);
void detab(char tab_line[], char detab_line[]); /* void detab(char tab_line[], char detab_line[]); */
int main()
{
	char line[MAXLINE], format_line[MAXLINE], detab_line[MAXLINE];
	
	printf(" Example /*comment here */\n Comment was before\n");
	printf(COMMENT);
	int len = 0;
	while ((len = knr_getline(line, MAXLINE)) > 0)
	{
		detab(line, detab_line);
		printf("%s{", format_line);
		putchar('{');
		putchar(']');
		putchar('(');
		printf("adsfasdfasdf(");
		printf("asdfasdf(");
		printf("[[[");
	/*	print single } element */
	/*	print single { element */
	/*	print single ) element */
	/*	print single ( element */
	/*	print single ] element */
	/*	print single [ element */
		printf("/* ( */");
	}
	return (0);
}
