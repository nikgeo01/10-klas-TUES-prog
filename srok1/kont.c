#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

unsigned int count_pattern(uint16_t data)
{

	unsigned int count = 0;
	uint16_t num = 2;
	while (num != 0)
	{
		if(3 & data == num)
		{
			count++;
		}
		num = num >> 1;
	}
	return count;
}

int main()
{
	printf("%u\n", count_pattern(10));

	return 0;
}
