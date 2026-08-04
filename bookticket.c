#include<stdio.h>
#include<string.h>
struct Ticket
{
    char name[20];
    int age;
    char gender;
    int busno;
    int seatno;
    char source[20];
    char destination[20];

};

int main()
{
    struct Ticket t;
    printf("=======BUS TICKET BOOKING=======\n");

    printf("Enter passenger name: ");
    scanf("%s", t.name);

    printf("Enter passenger age: ");
    scanf("%d", &t.age);

    printf("Enter passenger gender (M/F): ");
    scanf(" %c", &t.gender);

    printf("Enter bus number: ");
    scanf("%d", t.busno);

    printf("Enter seat number: ");
    scanf("%d", t.seatno);

    printf("Enter source: ");
    scanf("%s", t.source);

    printf("Enter destination: ");
    scanf("%s", t.destination);

    printf("\n\n===== TICKE BOOKED SUCCESSFULLY=====\n");

    printf("Passenger Name  :   %s\n", t.name);
    printf("Age             :   %d\n",  t.age);
    printf("Bus number      :  %d\n",  t.busno);
    printf("Seat number     :  %d\n",  t.seatno);
    printf("Source          :   %s\n",  t.source);
    printf("Destination     :   %s\n",  t.destination);
    printf("Gender          :   %s\n",  t.gender);
return 0;
}