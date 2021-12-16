#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int tot_size;
    int used_size;
    int* ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    a->tot_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(uSize*(sizeof(int)));
}

void showArray(struct myArray *a)
{
    printf("Printing...\n");
    for (int i=0; i<a->used_size; i++){
        printf("%d\n", a->ptr[i]);
    }
}

void inputArray(struct myArray *a)
{
    int n;
    printf("Input the Array:\n");
    for (int i=0; i<a->used_size; i++){
        scanf("%d", &n);
        a->ptr[i] = n;
    }
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10, 5);
    inputArray(&marks);
    showArray(&marks);

    return 0;
}