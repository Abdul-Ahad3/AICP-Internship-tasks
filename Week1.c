#include <stdio.h>

//Struct for the names since we can only use 1D arrays.
struct name{
    char letters[21];
};

//Task 1: Getting data for the students

//Function to get the weight. It also checks to see if it is invalid.
//I set a condition for the weight to be minimum 10 kilograms.
float getWeight(){
    float w;
    scanf("%f", &w);
    getchar();

    if(w < 10){
        printf("\nInvalid value. Re-enter weight.\n");
        return getWeight();
    }
    else{
        return w;
    }
}

//Function to get the data for each student.
void getData(struct name n[], float w[], char choice){
    if(choice == 's'){
        printf("Enter names and weights of the students: -\n");
        for(int i = 0; i < 30; i++){
            printf("Name:\t");
            scanf("%20s", n[i].letters);
            getchar();

            printf("Start-of-term weight:\t");
            w[i] = getWeight();
        }
    }
    else if(choice == 'e'){
        printf("Enter weights of the students: -\n");
        for(int i = 0; i < 30; i++){
            printf("End-of-term weight of %s:\t", n[i].letters);
            w[i] = getWeight();
        }
    }
}

//Task 2: Find and store differences in weights.

//Function to calculate the difference in weights 
void getDiff(float w1[], float w2[], float d[]){
    for(int i = 0; i < 30; i++)
        d[i] = w2[i] - w1[i];

    printf("\nDone!\n");
}

//Task 3: Display names and difference in weight of pupils 
//        whose weight is greater than 2.5 kilograms

//Function to check the differences and display those with difference greater than 2.5
void checkDiff(struct name n[], float d[]){
    for(int i = 0; i < 30; i++){
        if(d[i] > 2.5){
            printf("%s's weight has increased by %f\n", n[i].letters, d[i]);
        }
        else if(d[i] < -2.5){
            printf("%s's weight has decreased by %f\n", n[i].letters, -d[i]);
        }
    }
}

//Main function
//Implementation
int main(){
    struct name studentNames[30];
    float SOTWeights[30], EOTWeights[30], differences[30];
    int option = 0;

    while(1){
        printf("\n------------------------------------------\n");
        printf("What would you like to do?\n");
        printf("1. Enter start-of-term data\n2. Enter end-of-term data\n3. Calculate difference of weights\n4. Check differences\n5. Exit\n");

        printf("Enter choice:\t");
        scanf("%d", &option);
        printf("\n------------------------------------------\n");

        switch(option){
            case 1:
                getData(studentNames, SOTWeights, 's');
                break;

            case 2:
                getData(studentNames, EOTWeights, 'e');
                break;

            case 3:
                getDiff(SOTWeights, EOTWeights, differences);
                break;

            case 4:
                checkDiff(studentNames, differences);
                break;
        }

        if(option == 5){
            printf("Exited successfully!");
            break;
        }
    }

    return 0;
}