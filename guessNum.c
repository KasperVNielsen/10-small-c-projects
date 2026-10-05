#include <stdio.h>
#include <stdlib.h>

int main(){

    int maxNum = 35;
    int number = rand() % (maxNum + 1);
    int input = 0;

    printf("enter a random number:\n");
    scanf("%d", &input);

    if(input == number){
        printf("you won");
    } else {
        printf("you lost");
    }

    return 0;

}