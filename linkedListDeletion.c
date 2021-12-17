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

struct Node* deleteCase1(struct Node* head)
{
    struct Node* ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

struct Node* deleteCase2(struct Node* head, int index){
    struct Node* p = head;
    struct Node* q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node* deleteCase3(struct Node* head, int value)
{
    struct Node* p = head;
    struct Node* q = head->next;
    if (p->data == value){
        head = p->next;
        free(p);
    }
    while (q->data != value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value){
        p->next = q->next;
        free(q);
    }

    return head;
}

struct Node* deleteCase4(struct Node* head)
{
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

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

    // head = deleteCase1(head);     //First Node
    // head = deleteCase2(head, 1);  //Node with known index
    // head = deleteCase3(head, 5);  //Node with known data
    head = deleteCase4(head);        //Last Node

    display(head);

    return 0;
}