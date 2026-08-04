#include <stdio.h>

int main()
{
    int choice;
    int a, b, i, n;

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Addition\n");
        printf("2. Even Numbers (For Loop)\n");
        printf("3. Countdown (While Loop)\n");
        printf("4. Star Pattern (Nested Loop)\n");
        printf("5. Check Positive or Negative\n");
        printf("6. Break and Continue Demo\n");
        printf("7. Exit\n");
        printf("==========================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                printf("Enter two numbers: ");
                scanf("%d%d", &a, &b);

                printf("Sum = %d\n", a + b);

                if(a > b)
                    printf("%d is greater.\n", a);
                else
                    printf("%d is greater or equal.\n", b);

                break;

            case 2:

                printf("Enter limit: ");
                scanf("%d", &n);

                printf("Even Numbers:\n");

                for(i = 2; i <= n; i += 2)
                {
                    printf("%d ", i);
                }

                printf("\n");

                break;

            case 3:

                printf("Enter starting number: ");
                scanf("%d", &n);

                while(n >= 1)
                {
                    printf("%d ", n);
                    n--;
                }

                printf("\n");

                break;

            case 4:

                printf("Enter rows: ");
                scanf("%d", &n);

                for(i = 1; i <= n; i++)
                {
                    for(int j = 1; j <= n; j++)
                    {
                        printf("* ");
                    }

                    printf("\n");
                }

                break;

            case 5:

                printf("Enter number: ");
                scanf("%d", &a);

                if(a > 0)
                    printf("Positive Number\n");
                else if(a < 0)
                    printf("Negative Number\n");
                else
                    printf("Zero\n");

                break;

            case 6:

                printf("Break and Continue Demo:\n");

                for(i = 1; i <= 10; i++)
                {
                    if(i == 3)
                        continue;

                    if(i == 8)
                        break;

                    printf("%d ", i);
                }

                printf("\n");

                break;

            case 7:

                printf("Thank You!\n");

                break;

            default:

                printf("Invalid Choice!\n");
        }

    }
    while(choice != 7);

    return 0;
}