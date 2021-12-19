#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void display(struct Node* p)
{
    while(p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int isEmpty(struct Node* top)
{
    if (top == NULL)
        return 1;
    return 0;
}

int isFull(struct Node* top)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL)
        return 1;
    return 0;
}

struct Node* push(struct Node* top, int element)
{
    if (isFull(top))
        printf("Stack Overflow! Cannot push %d to stack\n", element);
    else {
        struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr->data = element;
        ptr->next = top;
        top = ptr;
        return ptr;
    }
}

int pop(struct Node** top)
{
    if (isEmpty(*top)) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        struct Node* ptr = *top;
        *top = (*top)->next;
        int element = ptr->data;
        free(ptr);
        return element;
    }
}

int peek(struct Node** top, int idx)
{
    struct Node* ptr = *top;
    for (int i=0; (i<idx-1 && ptr!=NULL); i++)
        ptr = ptr->next;
    if (ptr != NULL)
        return ptr->data;
    return -1;
}

int main()
{
    struct Node* top = NULL;
    top = push(top,24);
    top = push(top,11);
    top = push(top,5);
    top = push(top,29);
    int x = pop(&top);  
    printf("%d was popped\n", x);

    display(top);
    // for (int i=1; i<=3; i++)
    // printf("The value at idx %d is %d\n", i, peek(&top, i));
    return 0;
}