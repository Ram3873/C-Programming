#include <stdio.h>
int main()
{
    int marks[5];
    marks[0] = 90;
    marks[1] = 78;
    marks[2] = 67;
    marks[3] = 45;
    marks[4] = 24;
    for (int i = 0; i < 5; i++)
    {
        printf("%d:\n", marks[i]);
    }
    return 0;
}