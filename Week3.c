#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_COWS 1000
#define MAX_DAYS 7
#define MAX_YIELDS (MAX_DAYS * 2)

// Struct to hold milk yield data for a single cow
typedef struct {
    int identity_code;
    double yields[MAX_YIELDS];
    int yield_count;
} Cow;

// Function prototypes
void recordYield(Cow cows[], int num_cows);
void calculateStatistics(Cow cows[], int num_cows);
void identifyMostProductiveAndLowVolumeCows(Cow cows[], int num_cows);

int main() {
    int num_cows;

    printf("Enter the number of cows in the herd: ");
    scanf("%d", &num_cows);

    if (num_cows <= 0 || num_cows > MAX_COWS) {
        printf("Invalid number of cows. Please enter a value between 1 and %d.\n", MAX_COWS);
        return 1;
    }

    Cow cows[MAX_COWS];

    // Initialize cow data
    for (int i = 0; i < num_cows; i++) {
        printf("Enter the identity code for cow %d: ", i + 1);
        scanf("%d", &cows[i].identity_code);
        cows[i].yield_count = 0;
    }

    // Perform tasks
    recordYield(cows, num_cows);
    calculateStatistics(cows, num_cows);
    identifyMostProductiveAndLowVolumeCows(cows, num_cows);

    return 0;
}

void recordYield(Cow cows[], int num_cows) {
    for (int i = 0; i < num_cows; i++) {
        printf("Recording yields for cow %d (identity code %d):\n", i + 1, cows[i].identity_code);
        for (int j = 0; j < MAX_YIELDS; j += 2) {
            printf("Enter yield for day %d, morning: ", (j / 2) + 1);
            scanf("%lf", &cows[i].yields[j]);
            printf("Enter yield for day %d, evening: ", (j / 2) + 1);
            scanf("%lf", &cows[i].yields[j + 1]);
            cows[i].yield_count += 2;
        }
    }
}

void calculateStatistics(Cow cows[], int num_cows) {
    double total_volume = 0.0;
    int total_yields = 0;

    for (int i = 0; i < num_cows; i++) {
        for (int j = 0; j < cows[i].yield_count; j++) {
            total_volume += cows[i].yields[j];
            total_yields++;
        }
    }

    double average_yield = total_volume / total_yields;
    printf("Total weekly volume of milk: %.0f litres\n", total_volume);
    printf("Average yield per cow in a week: %.0f litres\n", average_yield);
}

void identifyMostProductiveAndLowVolumeCows(Cow cows[], int num_cows) {
    int most_productive_index = 0;
    double max_yield = 0.0;

    printf("Most productive cow(s) this week:\n");

    for (int i = 0; i < num_cows; i++) {
        double weekly_yield = 0.0;
        for (int j = 0; j < cows[i].yield_count; j++) {
            weekly_yield += cows[i].yields[j];
        }
        if (weekly_yield > max_yield) {
            max_yield = weekly_yield;
            most_productive_index = i;
        }
        if (weekly_yield < 12 * 4) {
            printf("Low volume cow: identity code %d, weekly yield: %.1f litres\n", cows[i].identity_code, weekly_yield);
        }
    }

    printf("Identity code of the most productive cow: %d, weekly yield: %.1f litres\n", cows[most_productive_index].identity_code, max_yield);
}
