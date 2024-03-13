#include <stdio.h>


int check (int a, int b)
{
	int c = a & b;
	if(c & a != a) return 1; else return 0;

}
int main()
{

	unsigned int a = 6;
	unsigned int b = 7;
	printf ("%d", check(a, b));

return 0;
}
