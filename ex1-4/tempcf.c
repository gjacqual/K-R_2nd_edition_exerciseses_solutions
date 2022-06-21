#include <stdio.h>

int main() {

float fahr, celsius;
int lower, upper, step;

lower = 0;
upper = 140;
step = 10; 

celsius = lower;

printf("Таблица температур по Цельсию и Фаренгейту\n\n");

        while (celsius <= upper) {
                fahr = (9.0/5.0 * celsius) + 32.0;
                printf("%6.1f\t%3.0f\n", celsius, fahr);
                celsius = celsius + step;
        }   
}

