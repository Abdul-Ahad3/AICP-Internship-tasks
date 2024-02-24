#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct Item {
    int itemNum;
    int numBids;
    char description[100];
    float reservePrice;
    float highestBid;
    int buyerNum;
};

struct Item items[MAX_ITEMS];
int numItems = 0;

void addItem() {
    if(numItems >= MAX_ITEMS) {
        printf("Auction is full, cannot add more items.\n");
        return;
    }

    printf("Enter item number: ");
    scanf("%d", &items[numItems].itemNum);
    printf("Enter item description: ");
    scanf("%s", items[numItems].description);
    printf("Enter item reserve price: ");
    scanf("%f", &items[numItems].reservePrice);

    items[numItems].numBids = 0;
    items[numItems].highestBid = 0.0;
    items[numItems].buyerNum = -1;

    numItems++;
}

void placeBid() {
    int itemNum, buyerNum;
    float bid;

    printf("Enter item number: ");
    scanf("%d", &itemNum);
    printf("Enter buyer number: ");
    scanf("%d", &buyerNum);
    printf("Enter bid: ");
    scanf("%f", &bid);

    for(int i = 0; i < numItems; i++) {
        if(items[i].itemNum == itemNum) {
            if(bid > items[i].highestBid) {
                items[i].highestBid = bid;
                items[i].buyerNum = buyerNum;
                items[i].numBids++;
                printf("Bid placed successfully!\n");
            } else {
                printf("Your bid must be higher than the current highest bid.\n");
            }
            return;
        }
    }

    printf("Item not found.\n");
}

void endAuction() {
    float totalFee = 0.0;
    int soldItems = 0, notMetReserve = 0, noBids = 0;

    for(int i = 0; i < numItems; i++) {
        if(items[i].numBids == 0) {
            noBids++;
        } else if(items[i].highestBid < items[i].reservePrice) {
            notMetReserve++;
        } else {
            soldItems++;
            totalFee += items[i].highestBid * 0.1;
        }
    }

    printf("Number of items sold: %d\n", soldItems);
    printf("Number of items that did not meet reserve price: %d\n", notMetReserve);
    printf("Number of items with no bids: %d\n", noBids);
    printf("Total fee for all sold items: %.2f\n", totalFee);
}

int main() {
    char choice;

    while(1) {
        printf("1. Add item\n");
        printf("2. Place bid\n");
        printf("3. End auction\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                addItem();
                break;
            case '2':
                placeBid();
                break;
            case '3':
                endAuction();
                break;
            case '4':
                printf("Exited Successfully.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    }

    return 0;
}
