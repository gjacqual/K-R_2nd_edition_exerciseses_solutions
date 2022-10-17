/*
 * K&R ex2-8
 * 
 * clang -Wall -Wextra -Werror -o rightrot rightrot.c
 * 
 * Exercise 2-8  Write a function rightrot(x,n) that returns the value of 
 * the integer x rotated to the right by n bit positions.
 * 
 * Max Filin 2022
 */

#include <stdio.h>

unsigned rightrot(unsigned x, int n)
{
	unsigned int mask = ~(~0 << n);

	n %= 8; 
	
	return (x >> n) | (x & mask) << (8 - n);
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
	int n; // rightmost n bits of y

	/*test 1 */
	x = 0b10111110;
	n = 3;
	printf("Test 1: bits: %d\n", n);
	printf("Position: 76543210\n");
	print_bits(x);
	print_bits(rightrot(x, n));

	/*test 2 */
	x = 0b10000001;
	n = 1;
	printf("Test 2: bits: %d\n", n);
	printf("Position: 76543210\n");
	print_bits(x);
	print_bits(rightrot(x, n));

	/*test 3 */
	x = 0b11001001;
	n = 2;
	printf("Test 3: bits: %d\n", n);
	printf("Position: 76543210\n");
	print_bits(x);
	print_bits(rightrot(x, n));

	/*test 4 */
	x = 0b11001001;
	n = 10;
	printf("Test 4: bits: %d\n", n);
	printf("Position: 76543210\n");
	print_bits(x);
	print_bits(rightrot(x, n));

	/*test 5 */
	x = 0b11001001;
	n = 0;
	printf("Test 5: bits: %d\n", n);
	printf("Position: 76543210\n");
	print_bits(x);
	print_bits(rightrot(x, n));

	return (0);
}