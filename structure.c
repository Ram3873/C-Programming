#include<stdio.h>
#include<string.h>

int main(){
    char s1[20] ="Ram";

    char s2[20]; s1;
    strcpy(s1, s2);

       printf("s2 =%s\n", s2);
       
       return 0;
}

