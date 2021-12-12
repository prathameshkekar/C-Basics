#include<stdio.h>
#include<string.h>

void swap(char* a, char* b)
{
    char temp;
    temp  = *a;
    *a = *b;
    *b = temp;
}

void perm(char* s, int a, int n)
{
    int i;
    if (a==n) {
        printf("%s\n", s);
    } else {
        for (i=a; i<=n; i++)
        {
            swap((s+a), (s+i));
            perm(s, a+1, n);
            swap((s+a), (s+i));
        }
    }
}

int main()
{
    char str[10];
    printf("Enter the string: ");
    scanf("%s", str);
    int n = strlen(str);
    printf("All possible permutations are:\n");
    perm(str, 0, n-1);
    return 0;
}