#include <stdio.h>
int main()
{

    int a, b, substraction;

    printf("Enter first number: ");
    scanf("%d\n", &a);

    printf("Enter second number: ");
    scanf("%d\n", &b);

    substraction = a - b;
    printf("substraction = %d\n", substraction);

    return 0;
}