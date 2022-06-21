#include <stdio.h>

int main(){

int c, countsp, counttab, countstr;

countsp = 0;
counttab = 0;
countstr = 0;

while ((c = getchar()) != EOF)
{
	if (c == '\n')
		++countstr;
	if (c == '\t')
		++counttab;
	if (c == ' ')
		++countsp;
}
printf("Пробелов: %d, Табов: %d, Строк:  %d\n", countsp, counttab, countstr);

}
