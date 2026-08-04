#include<stdio.h>

struct contact
{
    char name[20];
    char mobile[20];
   
    char email[20];
    char city[20];

};
     int main(){
        struct contact c;
        
        printf("=======CONTACT MANAGEMENT PROGRAM=======\n\n");


        printf("Enter contact name: ");
        scanf("%s", c.name);

        printf("Enter contact mobile : ");
        scanf("%s", c.mobile);

        printf("Enter contact email : ");
        scanf("%s", c.email);

        printf("Enter contact city : ");
        scanf("%s", c.city);

        printf("\n\n===== CONTACT DETAILS =====\n");



        printf("contact Name  :  %s\n", c.name);
        printf("contact Mobile :  %s\n", c.mobile);
        printf("contact Email  : %s\n", c.email);
        printf("Contact city   : %s\n", c.city);
        
        return 0;

     }