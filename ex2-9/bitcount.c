/*
 * K&R ex2-9
 * 
 * clang -Wall -Wextra -Werror -o bitcount bitcount.c
 * 
 * Exercise 2-9  In a two's complement number system, x &= (x-1) deletes 
 * the rightmost 1-bit in x . Explain why. Use this observation to write 
 * a faster version of bitcount.
 * 
 * Max Filin 2022
 */

/*
* 1001 1000 x
* -
* 0000 0001 1
* =
* 1001 0111 x-1
* &
* 1001 1000 x
* =
* 1001 0000 x&= x-1
*/

#include <stdio.h>

int bitcount(unsigned x)
{
	int b;

	for (b = 0; x!= 0;  x &= (x - 1))
		++b;
	return b;
}

int main(void)
{
	unsigned x = 0b10011001; //153 in decimal

	printf("%d\n", bitcount(x));
	return (0);
}