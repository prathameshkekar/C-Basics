#include<stdio.h>

void towersOfHanoi(int n, char A, char C, char B)
{
    if (n==0) {return ;}
    towersOfHanoi(n-1,A, B, C);
    printf("Move a disk from %c to %c\n", A, C);
    towersOfHanoi(n-1,B,C,A);
}

int main()
{
    int n;
    char A = 'A', B = 'B', C = 'C';
    printf("Input the number of disks: ");
    scanf("%d", &n);
    towersOfHanoi(n,A,C,B);
    return 0;
}