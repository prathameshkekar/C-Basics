#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void display(struct Node* head)
{
    struct Node* p = head;
    do{
        printf("%d\n", p->data);
        p = p->next;
    }
    while(p != head);  
}

struct Node* insert(struct Node* head, int element)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = element;
    struct Node* p = head->next;

    while (p->next != head)
        p = p->next;

    p->next = ptr;
    ptr->next = head;
    head = ptr;          //Remove this line to add at end
    
    return head;
}

int main()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 5;
    head->next = second;

    second->data = 6;
    second->next = third;

    third->data = 7;
    third->next= head;

    head = insert(head, 11);

    display(head);
    return 0;
}