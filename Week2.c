#include <stdio.h>

//Function to find the total cost 
float totalCost(int n){
    if(n < 10){
        printf("Insufficient people. More members required.\n");
    }
    if(n >= 10 && n < 17){
        return 150 + 14 + 21;
    }
    if(n >= 17 && n < 27){
        return 190 + 13.5 + 20;
    }
    if(n >= 27 && n < 37){
        return 225 + 13 + 19;
    }
    if(n >= 37){
        printf("Too many people.\n");
    }
}

//Function to find cost per head
float costPerHead(int n, int tc){
    return (float)tc / (float)n;
}

//Main function
//Implmentation
int main(){
    int numSC, numC, extra = 0;
    float tCost, phCost, payments[40], totalMoney = 0, profit = 0;
    char names[40][20];
    
    printf("Enter the number of people going on the outing:\t");
    scanf("%d", &numSC);
    tCost = totalCost(numSC);
    phCost = costPerHead(numSC, tCost);

    if(numSC <= 24){
        numC = 2;
    }else {
        numC = 3;
    }

    printf("Total people going on trip: %d\nSenior Citizen: %d\nCarers: %d\n", numSC + numC, numSC, numC);
    printf("Total cost to be collected: $ %f\nCost per head: $ %f\n", tCost, phCost);

    printf("\nEnter the names and the payments of the senior citizens:\n");
    for(int i = 0; i < numSC; i++){
        printf("Name of senior citizen %d:\t", i + 1);
        scanf("%s", names[i]);
        printf("Payment of senior citizen %d:\t$ ", i + 1);
        scanf("%f", &payments[i]);
        // Add the payment to the total amount of money collected
        totalMoney += payments[i];
    }

    printf("\nEnter the names of the carers:\n");
    for(int i = numSC; i < numSC + numC; i++){
        printf("Name of carer %d:\t", i + 1 - numSC);
        scanf("%s", names[i]);
        // Set the payment of the carer to zero
        payments[i] = 0;
    }

    // Check if there are spare places on the coach
    if(numSC + numC < 36){
        printf("\nThere are %d spare places on the coach.\n", 36 - numSC - numC);
        printf("Enter the number of extra people:\t");
        scanf("%d", &extra);
        // Check if the number of extra people is valid
        if(extra > 0 && extra <= 36 - numSC - numC){
            printf("\nEnter the names and the payments of the extra people:\n");
            for(int i = numSC + numC; i < numSC + numC + extra; i++){
                printf("Name of extra person %d:\t", i + 1 - numSC - numC);
                scanf("%s", names[i]);
                // Set the payment of the extra person to the same as the senior citizens
                payments[i] = phCost;
                // Add the payment to the total amount of money collected
                totalMoney += payments[i];
            }
        }else{
            printf("Invalid number of extra people.\n");
        }
    }

    printf("\nList of the people on the outing:\n");
    printf("Name\t\tPayment\n");
    for(int i = 0; i < numSC + numC + extra; i++){
        printf("%s\t\t%.2f\n", names[i], payments[i]);
    }

    printf("\nTotal amount of money collected: $ %.2f\n", totalMoney);

    // Calculate the profit or loss by subtracting the estimated cost from the money collected
    profit = totalMoney - tCost;

    // Check if the profit is positive, negative, or zero
    if(profit > 0){
        printf("\nThe outing has made a profit of $ %.2f\n", profit);
    }else if(profit < 0){
        printf("\nThe outing has made a loss of $ %.2f\n", -profit);
    }else{
        printf("\nThe outing has broken even.\n");
    }

    return 0;
}
