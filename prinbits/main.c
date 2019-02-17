#include <stdio.h>
#include <limits.h>
int main()
{
	int i = 31;
	int n = INT_MAX;;
	int temp;
	int h = 1;
	while(i--)
	{
		temp = n;
		printf("%d", (temp >> i) & 1);
	}
}
