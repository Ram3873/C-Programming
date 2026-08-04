#include <stdio.h>
int main()
{
    int marks[5] = {90, 83, 72, 36, 85};
    for (int i = 0; i < 5; i++)
    {
        printf("student %d ke marks: %d\n", i + 1, marks[i]);
    }
    return 0;
}