#include <stdio.h>
int main()
{
    float a, b;
    char op;
    printf("Enter first number: ");
    scanf("%f", &a);

    printf("Enter an operator(+,-,*,/): ");
scanf(" %c",&op);
                      
                    printf("Enter second number: ");
                    scanf(" %f ", &b);
  switch (op){
    case '+':
        printf("result = %.2f\n", a + b);
        break;
    case '-':
        printf("result = %.2f\n", a - b);
        break;
    case '*':
        printf("result = %.2f\n", a * b);
        break;
    case '/':
        if (b != 0)
            printf("Result = %.2f\n", a / b);
        else
            printf("Division by zero is not possible");

        break;
    default:
        printf("invalid operator!\n");
        return 0;


  }
}
