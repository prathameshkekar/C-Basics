#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int top;
    int size;
    char* arr;
};

int isEmpty(struct stack* s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

void push(struct stack* s, char element)
{
    s->top++;
    s->arr[s->top] = element;
}

char pop(struct stack* s)
{
    if (isEmpty(s))
        return '\0';
    else {
        char ch = s->arr[s->top];
        s->top--;
        return ch;
    }
}

int isOperator(char ch)
{
    if (ch=='+' || ch=='-' || ch=='/' || ch=='*')
        return 1;
    return 0;
}

int precedence(char ch)
{
    if (ch=='+' || ch=='-')
        return 1;
    else if (ch=='/' || ch=='*')
        return 2;
}

char* infixToPostfix(char* exp)
{
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = strlen(exp);
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));
    char* postfix = (char*)malloc((strlen(exp) + 1) * sizeof(char));

    int i=0, j=0;
    while (exp[i]!='\0')
    {
        if (!isOperator(exp[i])) {
            postfix[j] = exp[i];
            i++; j++;
        } else {
            if (isEmpty(sp)) {
                push(sp, exp[i]);
                i++;
            }
            else if (precedence(exp[i]) > precedence(sp->arr[sp->top])) {
                push(sp, exp[i]);
                i++;
            } else {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char* infix;
    printf("Enter the infix notation:\n");
    scanf("%s", infix);
    printf("The postfix notation is:\n");
    printf("%s", infixToPostfix(infix));
    return 0;
}