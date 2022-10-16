/*
 * K&R ex2-6
 * 
 * clang -Wall -Wextra -Werror -o setbits setbits.c
 * 
 * Exercise 2-6 Write a function setbits(x,p,n,y) that returns x with the 
 * n bits that begin at position p set to the rightmost n bits of y, 
 * leaving the other bits unchanged.
 * 
 * Max Filin 2022
 */

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n)
{
	unsigned int mask = ~(~0 << n);
	unsigned int shift = p + 1 - n;
	return (x >> shift) & mask;
}


int setbits(unsigned int x, int p, int n, unsigned int y)
{
	unsigned int mask = ~(~0 << n);
	unsigned int shift = p + 1 - n;
	return (x & ~(mask << shift)) | ((y & mask) << shift);
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
	unsigned int y; // number y

	/*test getbits() */
	x = 0b11111000;
	p = 4;
	n = 3;
	printf("Test 0: getbits position: %d, bits: %d\n", p, n);
	printf("Position: 76543210\n");
	print_bits(x);
	print_bits(getbits(x,p,n));
	/*test 1 */
	
	x = 0b11110000;
	y = 0b11111111;
	p = 2;
	n = 3;
	printf("\nTest 1: position: %d, bits: %d\n", p, n);
	printf("Position: 76543210\n");
	print_bits(x);
	print_bits(y);
	print_bits(setbits(x,p,n,y));

	/*test 2 */
	x = 0b00000000;
	y = 0b11111111;
	p = 5;
	n = 4;
	printf("\nTest 2: position: %d, bits: %d\n", p, n);
	printf("Position: 76543210\n");
	print_bits(x);
	print_bits(y);
	print_bits(setbits(x,p,n,y));

	/*test 3 */
	x = 0b11010100;
	y = 0b11111111;
	p = 0;
	n = 1;
	printf("\nTest 3: position: %d, bits: %d\n", p, n);
	printf("Position: 76543210\n");
	print_bits(x);
	print_bits(y);
	print_bits(setbits(x,p,n,y));

	return (0);
}
