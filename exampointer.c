#include <stdio.h>
int main(){
    int arr[6] = {10,20,30,40,50,60};
      int *ptr = arr;
    printf("%d\n", *(ptr + 0));      
    printf("%d\n", *(ptr + 1));
    printf("%d\n", *(ptr + 2));
    printf("%d\n", *(ptr + 3));
    printf("%d\n", *(ptr + 4));
    printf("%d\n", *(ptr + 5));
      return 0;
} 
