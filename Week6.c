#include <stdio.h>

// Task 1
// Function to display Ticket options and attractions[^1^][1]
void displayDetails(int days) {
    if (days == 1) {
        printf("One-day ticket options and prices:\n");
        printf("One adult: $20.00\n");
        printf("One child: $12.00\n");
        printf("One senior: $16.00\n");
        printf("Family ticket: $60.00\n");
        printf("Group ticket: $15.00 per person\n");
        printf("Extra attractions:\n");
        printf("Lion feeding: $2.50\n");
        printf("Penguin feeding: $2.00\n");
    } else if (days == 2) {
        printf("Two-day ticket options and prices:\n");
        printf("One adult: $30.00\n");
        printf("One child: $18.00\n");
        printf("One senior: $24.00\n");
        printf("Family ticket: $90.00\n");
        printf("Group ticket: $22.50 per person\n");
        printf("Extra attractions:\n");
        printf("Lion feeding: $2.50\n");
        printf("Penguin feeding: $2.00\n");
        printf("Evening barbecue: $5.00\n");
    }
}

// Task 2
// Function to process booking
void booking(int *adults, int *children, int *seniors, int *family, int *group, int days) {
    printf("Enter the number of adult tickets: ");
    scanf("%d", adults);
    printf("Enter the number of child tickets: ");
    scanf("%d", children);
    printf("Enter the number of senior tickets: ");
    scanf("%d", seniors);
    printf("Enter the number of family tickets: ");
    scanf("%d", family);
    printf("Enter the number of group tickets: ");
    scanf("%d", group);

    // Calculate total cost based on the number of days
    float total = (*adults * 20.00 + *children * 12.00 + *seniors * 16.00 + *family * 60.00 + *group * 15.00);
    if (days == 2) {
        total *= 1.5; // Assuming two-day tickets cost 1.5 times the one-day ticket
    }
    printf("Total cost for tickets: $%.2f\n", total);
}

// Task 3
// Function to adjust total
void adjust(float *total, int adults, int children, int seniors, int family, int group) {
    // Apply a 10% discount for family tickets
    if (family > 0) {
        *total *= 0.9;
    }

    // Apply a 5% discount for senior tickets if more than two are purchased
    if (seniors > 2) {
        *total *= 0.95;
    }

    // Apply a 15% group discount if more than 10 group tickets are purchased
    if (group > 10) {
        *total *= 0.85;
    }

    printf("Adjusted total cost: $%.2f\n", *total);
}

int main() {
    printf("Welcome to the Wildlife Park Ticket Booking System\n");
    int adults, children, seniors, family, group;
    float total;
    int days = 1; // Assuming a one-day visit

    displayDetails(days);
    booking(&adults, &children, &seniors, &family, &group, days);
    adjust(&total, adults, children, seniors, family, group);

    // Further implementation would go here
    return 0;
}
