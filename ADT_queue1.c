#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct queue* q)
{
    if (q->f == q->r)
        return 1;
    return 0;
}

int isFull(struct queue* q)
{
    if (q->r == q->size-1)
        return 1;
    return 0;
}

int enqueue(struct queue* q, int element)
{
    if (isFull(q))
        return -1;
    q->r++;
    q->arr[q->r] = element;
}

int dequeue(struct queue* q)
{
    if (isEmpty(q)){
        printf("Queue is Empty!\n");
        return -1;
    }
    q->f++;
    int a = q->arr[q->f];

    return a;
}

int main()
{
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 10;
    q->r = q->f = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));

    enqueue(q,45);
    enqueue(q,2);
    enqueue(q,11);
    enqueue(q,29);
    printf("Dequeueing %d\n", dequeue(q));
    printf("Dequeueing %d\n", dequeue(q));
    printf("Dequeueing %d\n", dequeue(q));
    printf("Dequeueing %d\n", dequeue(q));
    dequeue(q);

    return 0;
}