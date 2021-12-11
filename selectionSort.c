#include<stdio.h>

void printArray(int* A, int n){
    for (int i=0; i<n; i++)
    {
        printf("%d ", A[i]);
    }printf("\n");
}

void selectionSort(int* A, int n){
    for (int i=0; i<n-1; i++)
    {
        int j = i;                  //j is the index of minimum element
        for (int k=i+1; k<n; k++)
        {
            if (A[k] < A[j]) {
                j = k;
            }
        }
        // printArray(A,n);
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

int main()
{
    int n=6;
    int A[] = {5, 1, 4, 6, 2, 3};
    printArray(A, n);
    selectionSort(A,n);
    printf("Sorted Array:\n");
    printArray(A, n);
    
    return 0;
}