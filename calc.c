#include <stdio.h>

int main(){
    float num1, num2, result;
    char opt;

    printf("Enter the first number and operator ");
    scanf("%f %c", &num1, &opt);
    printf (" \n Enter the second number: ");  
    scanf (" %f", &num2);  

    switch (opt)
    {
    case  '+':
        result = num1 + num2;
        printf("\n result: %f ", result);
        break;
    case '-':
        result = num1 - num2;
        printf("\n result: %f ", result);
        break;
    case '*':
        result = num1 * num2;
        printf("\n result: %f", result);
        break;
    case '/':
        if(num2 == 0){
            printf (" \n You cannot divide by zero. Please enter another number. ");  
            scanf ("%f", &num2);
        }
         result = num1 / num2;
         printf (" result: %f ",result);  
         break;  
    default:
          printf (" Enter the following operators only: +, -, *, / "); 
    }
    return 0;
}