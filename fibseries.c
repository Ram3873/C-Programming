#include<stdio.h>
int main(){
    int n;
    int a = 1, b = 0 , next;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("fibonacci series: ");

    for(int i = 1; i <= n; i++)
    {
        printf("%d" , a);


        next = a + b;
        a = b;
        b = next;


    }
    return 0;
}