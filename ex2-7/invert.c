/*
 * K&R ex2-7
 * 
 * clang -Wall -Wextra -Werror -o invert invert.c
 * 
 * Exercise 2-7  Write a function invert(x,p,n) that returns x with the n bits 
 * that begin at position p inverted (i.e., 1 changed into 0 and vice versa), 
 * leaving the others unchanged.
 * 
 * Max Filin 2022
 */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
	unsigned int mask = ~(~0 << n);
	unsigned int shift = p + 1 - n;
	return (x ^ (mask << shift));
}

void print_bits(unsigned int num)
{
	printf("Result:   ");
	for (int i = 7; i >= 0; --i)
	{
		printf("%d", (num >> i) & 1);
	}
	printf("\n");
}


int main(void)
{
	unsigned int x; //number x
	int p; // position
	int n; // rightmost n bits of y

	/*test 1 */
	x = 0b11111111;
	p = 4;
	n = 3;
	printf("Test 1: position: %d, bits: %d\n", p, n);
	printf("Position: 76543210\n");
	print_bits(x);
	print_bits(invert(x, p, n));

	/*test 2 */
	x = 0b00000000;
	p = 5;
	n = 4;
	printf("Test 2: position: %d, bits: %d\n", p, n);
	printf("Position: 76543210\n");
	print_bits(x);
	print_bits(invert(x, p, n));

	return (0);
}