#include<stdio.h>
#include<stdlib.h>

struct Node{
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

struct Node* insertCase1(struct Node* head, int data)
{
    struct Node* ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node* insertCase2(struct Node* head, int data, int idx)
{
    struct Node* ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;

    while (i != idx-1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->data = data;
    p->next = ptr;

    return head;
}

struct Node* insertCase3(struct Node* head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    ptr->data = data;
    
    while (p->next != NULL)
        p = p->next;

    p->next = ptr;
    ptr->next = NULL;

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
    third->next= NULL;

    // head = insertCase1(head,24);         //Insert at Start
    // head =  insertCase2(head, 11, 1);    //Insert at given index
    head = insertCase3(head, 56);           //Insert at end

    display(head);

    return 0;
}