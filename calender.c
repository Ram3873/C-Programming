#include <stdio.h>

int main() {
    int days, startDay, i;

    printf("Enter number of days in month (28-31): ");
    scanf("%d", &days);

    printf("Enter starting day (1=Mon, 2=Tue, ..., 7=Sun): ");
    scanf("%d", &startDay);

    printf("\nMon Tue Wed Thu Fri Sat Sun\n");

    for (i = 1; i < startDay; i++) {
        printf("    ");
    }

    for (i = 1; i <= days; i++) {
        printf("%3d ", i);

        if ((i + startDay - 1) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");

    return 0;
}