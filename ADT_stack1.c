#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int* arr;
};

int isEmpty(struct stack* s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

int isFull(struct stack* s)
{
    if (s->top == s->size - 1)
        return 1;
    return 0;
}

void push(struct stack* s, int element)
{
    if (isFull(s))
        printf("Stack Overflow! Cannot push %d to stack\n", element);
    else {
        s->top++;
        s->arr[s->top] = element;
    }
}

int pop(struct stack* s)
{
    if (isEmpty(s)){
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    else {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int peek(struct stack* s, int idx)
{
    if (s->top-idx+1 < 0) {
        printf("Not a valid position");
        return -1;
    }
    return s->arr[s->top-idx+1];
}

void display(struct stack* s)
{
    for (int i=0; i<=s->top; i++){
        printf("%d ", s->arr[i]);
    }printf("\n");
}

int main()
{
    struct stack* s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    pop(s);
    push(s,11);
    push(s,12);
    push(s,13);
    push(s,14);
    push(s,15);
    push(s,16);
    push(s,17);
    push(s,18);
    push(s,19);
    push(s,20);
    push(s,21);
    pop(s);
    display(s);


    return 0;
}