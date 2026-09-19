#include<stdio.h>
int main(){

int ch;

printf("Enter your choice: ");
scanf("%d" , &ch);

switch(ch)
{
    case 1:
    printf("This is cat: ");
    break;

    case 2:
    printf("This is dog: ");
    break;

    case 3:
    printf("This is bird: ");
    break;

    case 4:
    printf("This is fish: ");
    break;

    case 5:
    printf("This is horse: ");
    break;

    case 6:
    printf("This is frog: ");
    break;

    case 7:
    printf("This is snake: ");
    break;

    }
    
    return 0;
}