#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num;
    printf("Enter any number (1-100): ");
    scanf("%d", &num);

    switch(num){
        case 1 ... 50:
            printf("Number is in between 1 to 50");
            break;
        case 51 ... 100:
            printf("Number is in between 51 to 100");
            break;
        default:
            printf("Number is out of range!");
    }

    return 0;
}