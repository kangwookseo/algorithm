#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int x=0, y=0;
	int result = 0;

	scanf("%d %d", &x, &y);

	result = x - y;
	printf("%d", result);

}