#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
    int A, B;
    int result = 0;

    scanf("%d %d", &A, &B);
    result = A + B;

    printf("%d", result);

    return 0;
}