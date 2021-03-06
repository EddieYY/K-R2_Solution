/*
 * 2-7
 * Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted 
 * (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
 *
 */

#include <stdio.h>
#include <stdbool.h>
unsigned invert(unsigned x, int p, int n);




/*int main(void)
{
	printf("%d\n", invert(90, 4, 3));
  	return 0;
}



unsigned invert(unsigned x, int p, int n)
{
	unsigned mask =(~(~0<<n))<< (p-n);
	return (x&mask) | (~x &~mask);
}
*/
bool getBit(int n, int index);
int main(void)
{
	int num = 90, index;

    	printf("Input\n");
	for (int i = 7; i >= 0; i--) 
		printf("%d", getBit(num,i));
    	printf("\n");

	printf("%d\n", invert(90, 4, 3));
	for (int i = 7; i >= 0; i--) 
		printf("%d", getBit(invert(90, 4, 3), i));

	return 0;
}

bool getBit(int n, int index) {
	return ((n & (1 << index)) > 0);
}

unsigned invert(unsigned x, int p, int n)
{
	/*
		Example from right to left with x = 01011010 (90 in decimal), p = 4, n = 3
			mask (has the position of bits to be inverted):
			00001111 ^ 00000001 = 00001110
			return:
			01011010 & 11110001 = 01010000 
			10100101 & 00001110 = 00000100 
			01010000 | 00000100 = 01010100
	*/
	unsigned mask = (~(~0 << p)) ^ ~(~0 << (p-n));
	return ((x & ~mask) | (~x & mask));
}

