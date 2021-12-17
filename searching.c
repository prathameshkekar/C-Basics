#include<stdio.h>

void display(int arr[], int n)
{
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int recurBinarySearch(int arr[], int low, int high, int element)
{
    if (high>=low) {
        int mid = (low+high) / 2;
        
        if (arr[mid] == element) 
            return mid;

        if (arr[mid] > element) 
            return recurBinarySearch(arr,low,mid-1,element);

        return recurBinarySearch(arr,mid+1,high,element);
    }
}

int binarySearch(int arr[], int size, int element)
{
    int low=0, mid, high=size-1;
    while(low<=high){
        mid = (low + high)/2;
        if (arr[mid] == element) {
            return mid;
        }
        if (arr[mid] < element) {
            low = mid+1;
        } else {
            high = mid -1;
        }
    } 
    return -1;
    
}

int main()
{
    int arr[] = {5,11,13,14,24,25,29};
    int size = sizeof(arr)/sizeof(int);
    printf("Given array:\n");
    display(arr,size);
    int element = 24;
    printf("Given element: %d\n", element);
    // int idx = binarySearch(arr, size, element);
    int idx = recurBinarySearch(arr, 0, size, element);
    printf("The element is present at index: %d", idx);

    return 0;
}