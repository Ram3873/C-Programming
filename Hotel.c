#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct
{
    int roomNumber;
    char customerName[50];
    int age;
    int days;
    float bill;
    int booked;
} Room;

void initializeRooms(Room rooms[])
{
    for (int i = 0; i < MAX_ROOMS; i++)
    {
        rooms[i].roomNumber = i + 1;
        rooms[i].customerName[0] = '\0';
        rooms[i].age = 0;
        rooms[i].days = 0;
        rooms[i].bill = 0;
        rooms[i].booked = 0;
    }
}

void showRooms(Room rooms[])
{
    printf("\n====================================\n");
    printf("           ROOM STATUS\n");
    printf("====================================\n");

    for (int i = 0; i < MAX_ROOMS; i++)
    {
        printf("Room %d : ", rooms[i].roomNumber);

        if (rooms[i].booked == 1)
        {
            printf("Booked\n");
        }
        else
        {
            printf("Available\n");
        }
    }
}

void bookRoom(Room rooms[])
{
    int roomNumber;

    printf("\nEnter room number (1-%d): ", MAX_ROOMS);
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > MAX_ROOMS)
    {
        printf("Invalid room number!\n");
        return;
    }

    if (rooms[roomNumber - 1].booked == 1)
    {
        printf("Sorry! This room is already booked.\n");
        return;
    }

    printf("Enter customer name: ");
    scanf(" %[^\n]", rooms[roomNumber - 1].customerName);

    printf("Enter customer age: ");
    scanf("%d", &rooms[roomNumber - 1].age);

    if (rooms[roomNumber - 1].age < 18)
    {
        printf("Customer must be 18 or older.\n");
        return;
    }

    printf("Enter number of days: ");
    scanf("%d", &rooms[roomNumber - 1].days);

    if (rooms[roomNumber - 1].days <= 0)
    {
        printf("Invalid number of days!\n");
        return;
    }

    rooms[roomNumber - 1].bill =
        rooms[roomNumber - 1].days * 1500;

    rooms[roomNumber - 1].booked = 1;

    printf("\nRoom booked successfully!\n");
    printf("Room Number : %d\n", roomNumber);
    printf("Customer    : %s\n",
           rooms[roomNumber - 1].customerName);
    printf("Days        : %d\n",
           rooms[roomNumber - 1].days);
    printf("Bill        : Rs. %.2f\n",
           rooms[roomNumber - 1].bill);
}

void viewCustomer(Room rooms[])
{
    int roomNumber;

    printf("\nEnter room number: ");
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > MAX_ROOMS)
    {
        printf("Invalid room number!\n");
        return;
    }

    Room *ptr = &rooms[roomNumber - 1];

    if (ptr->booked == 0)
    {
        printf("This room is available.\n");
        return;
    }

    printf("\n====================================\n");
    printf("        CUSTOMER DETAILS\n");
    printf("====================================\n");

    printf("Room Number : %d\n", ptr->roomNumber);
    printf("Name        : %s\n", ptr->customerName);
    printf("Age         : %d\n", ptr->age);
    printf("Days        : %d\n", ptr->days);
    printf("Bill        : Rs. %.2f\n", ptr->bill);
}

void checkout(Room rooms[])
{
    int roomNumber;

    printf("\nEnter room number: ");
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > MAX_ROOMS)
    {
        printf("Invalid room number!\n");
        return;
    }

    if (rooms[roomNumber - 1].booked == 0)
    {
        printf("This room is already available.\n");
        return;
    }

    printf("\n====================================\n");
    printf("           CHECKOUT\n");
    printf("====================================\n");

    printf("Customer : %s\n",
           rooms[roomNumber - 1].customerName);

    printf("Total Bill : Rs. %.2f\n",
           rooms[roomNumber - 1].bill);

    printf("Thank you for staying with us!\n");

    rooms[roomNumber - 1].customerName[0] = '\0';
    rooms[roomNumber - 1].age = 0;
    rooms[roomNumber - 1].days = 0;
    rooms[roomNumber - 1].bill = 0;
    rooms[roomNumber - 1].booked = 0;

    printf("Checkout completed successfully.\n");
}

void searchCustomer(Room rooms[])
{
    char searchName[50];
    int found = 0;

    printf("\nEnter customer name: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < MAX_ROOMS; i++)
    {
        if (rooms[i].booked == 1 &&
            strcmp(rooms[i].customerName, searchName) == 0)
        {
            printf("\nCustomer found!\n");
            printf("Room Number : %d\n", rooms[i].roomNumber);
            printf("Name        : %s\n", rooms[i].customerName);
            printf("Days        : %d\n", rooms[i].days);
            printf("Bill        : Rs. %.2f\n", rooms[i].bill);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Customer not found.\n");
    }
}

void showBookedRooms(Room rooms[])
{
    int found = 0;

    printf("\n====================================\n");
    printf("          BOOKED ROOMS\n");
    printf("====================================\n");

    for (int i = 0; i < MAX_ROOMS; i++)
    {
        if (rooms[i].booked == 1)
        {
            printf("Room %d -> %s\n",
                   rooms[i].roomNumber,
                   rooms[i].customerName);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("No rooms are currently booked.\n");
    }
}

void hotelInfo()
{
    printf("\n====================================\n");
    printf("           HOTEL INFORMATION\n");
    printf("====================================\n");

    printf("Hotel Name : Royal Stay Hotel\n");
    printf("Location   : City Center\n");
    printf("Room Rate  : Rs. 1500 per day\n");
    printf("Total Rooms: %d\n", MAX_ROOMS);
    printf("Check-in   : 12:00 PM\n");
    printf("Check-out  : 11:00 AM\n");
}

void calculateRevenue(Room rooms[])
{
    float total = 0;

    for (int i = 0; i < MAX_ROOMS; i++)
    {
        if (rooms[i].booked == 1)
        {
            total = total + rooms[i].bill;
        }
    }

    printf("\n====================================\n");
    printf("        CURRENT HOTEL REVENUE\n");
    printf("====================================\n");

    printf("Revenue : Rs. %.2f\n", total);
}

int main()
{
    Room rooms[MAX_ROOMS];

    int choice;

    initializeRooms(rooms);

    printf("====================================\n");
    printf("       ROYAL STAY HOTEL SYSTEM\n");
    printf("====================================\n");

    do
    {
        printf("\n");
        printf("========== MAIN MENU ==========\n");
        printf("1. Show Room Status\n");
        printf("2. Book Room\n");
        printf("3. View Customer\n");
        printf("4. Checkout\n");
        printf("5. Search Customer\n");
        printf("6. Show Booked Rooms\n");
        printf("7. Hotel Information\n");
        printf("8. Calculate Revenue\n");
        printf("9. Exit\n");
        printf("===============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                showRooms(rooms);
                break;

            case 2:
                bookRoom(rooms);
                break;

            case 3:
                viewCustomer(rooms);
                break;

            case 4:
                checkout(rooms);
                break;

            case 5:
                searchCustomer(rooms);
                break;

            case 6:
                showBookedRooms(rooms);
                break;

            case 7:
                hotelInfo();
                break;

            case 8:
                calculateRevenue(rooms);
                break;

            case 9:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}