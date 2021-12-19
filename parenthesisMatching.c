#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char* arr;
};

int isEmpty(struct stack* s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

void push(struct stack* s, char c)
{
    s->arr[s->top] = c;
    s->top++; 
}

void pop(struct stack* s)
{
    s->top--;
}

int parenthesisMatch(char* exp)
{
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = strlen(exp);
    s->arr = (char *)malloc(s->size * sizeof(char));
       
    for (int i=0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(') {
            push(s,exp[i]);
        }
        else if (exp[i] == ')') {
            if (isEmpty(s))
                return 0;
            else
                pop(s);
        }
    }
    return isEmpty(s);
}

int main()
{
    char* exp;
    printf("Enter the expression to be checked:\n");
    scanf("%s", exp);
    int exp_len = strlen(exp);
    // printf("%s", exp);

    if (parenthesisMatch(exp))
        printf("Parenthesis is matching");
    else
        printf("Parenthesis is not matching");
    return 0;
}