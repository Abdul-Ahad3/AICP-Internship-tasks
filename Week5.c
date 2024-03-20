#include <stdio.h>
#include <stdbool.h>

double totalPayments = 0.0;

// Function to calculate modulo 11 check digit[^3^][3]
bool isValidFrequentNumber(int frequentNumber) {
    int sum = 0;
    for (int i = 4; i > 0; --i) {
        sum += (frequentNumber % 10) * i;
        frequentNumber /= 10;
    }
    return (sum % 11 == 0);
}

//Task 1
//Function to calculate Park Price[^1^][1]
double parkPrice(int day, int arrivalTime, int hours, int frequentNumber){
    double pricePerHour = 0.0;
    switch (day) {
        case 0: pricePerHour = (arrivalTime >= 16) ? 2.00 : 10.00; break; // Sunday
        case 1: // Monday
        case 2: // Tuesday
        case 3: // Wednesday
        case 4: // Thursday
        case 5: pricePerHour = 10.00; break; // Friday
        case 6: pricePerHour = (hours <= 4) ? 3.00 : 2.00; break; // Saturday
    }

    double discount = (arrivalTime >= 16) ? 0.5 : 0.1;
    double price = pricePerHour * hours;

    if (isValidFrequentNumber(frequentNumber)) {
        price *= (1 - discount);
    }

    return price;
}

//Task2 
//Keeping total of payments[^2^][2]
void dailyTotal(double amountPaid){
    totalPayments += amountPaid;
    printf("Total payments for the day: %.2f\n", totalPayments);
}

//Task 3
//Payment adjustment
double adjustedFare(int arrivalTime, int hours){
    if (arrivalTime < 16 && (arrivalTime + hours) > 16) {
        int pre16Hours = 16 - arrivalTime;
        int post16Hours = hours - pre16Hours;
        return parkPrice(0, arrivalTime, pre16Hours, 0) + parkPrice(0, 16, post16Hours, 0);
    }
    return parkPrice(0, arrivalTime, hours, 0);
}

int main(){
    int day, arrivalTime, hours, frequentNumber;

    printf("Enter the day (0=Sunday, 1=Monday, ..., 6=Saturday): ");
    scanf("%d", &day);
    printf("Enter the hour of arrival (0-23): ");
    scanf("%d", &arrivalTime);
    printf("Enter the number of hours to park: ");
    scanf("%d", &hours);
    printf("Enter your frequent parking number (0 if none): ");
    scanf("%d", &frequentNumber);

    double price = adjustedFare(arrivalTime, hours);
    printf("The price to park is: %.2f\n", price);

    printf("Enter the amount paid: ");
    double amountPaid;
    scanf("%lf", &amountPaid);
    if (amountPaid >= price) {
        dailyTotal(amountPaid);
    } else {
        printf("Error: Amount paid is less than the price to park.\n");
    }

    return 0;
}
