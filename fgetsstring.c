
#include <stdio.h>

int main(){
    
    char name[50];
    
    printf("Enter your name: ");
        
    fgets(name,(name), stdin);
        
        printf("%s", name);
        return 0;

    }
        
