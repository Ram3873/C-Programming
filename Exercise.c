#include <stdio.h>

int main(){

      int num;
      printf("Enter the number you want multiplication table of:\n");

                scanf("%d", & num);

printf("multiplication table of %d is as follow :\n", num);


   for(int i = 1 ; 1 <= 10 ; i++)


   {

    printf("%d x %d = %d\n", num, i,  num * i);
   }

   return 0;
}