#include<stdio.h>

void display(int arr[], int n)
{
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity){
        return 0;
    }
    for (int i=size-1; i>=index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int deletion(int arr[], int size, int element, int capacity)
{
    int idx;

    //Liner Search

    for (int i=0; i<size; i++){
        if (arr[i] == element){
            idx = i;
        }
    }
    for (int i=idx; i<size; i++){
        arr[i] = arr[i+1];
    }
}

int main()
{
    int arr[100] = {1,2,3,5};
    int size = 4, element = 10, index = 0;
    display(arr, size);
    int res = insertion(arr, size, element, 100, index); 
    if(res){
        size += 1;
        printf("Insertion Successful\n");
        display(arr, size);
    } else {
        printf("Array index out of range!\n");
    }
    deletion(arr, size, element, 100); size -= 1;
    display(arr, size);
    
    return 0;
}