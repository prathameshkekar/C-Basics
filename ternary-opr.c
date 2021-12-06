#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a, b, res;

    scanf("%d%d", &a, &b);
    /*
    if (a == 1) {
        if (b == 2) {
            res = 3;
        } else {
            res = 5;
        }
    } else {
        res = 0;
    }
    */
    res = (a == 1 ? (b == 2 ? 3 : 5) : 0);

    printf("%d", res);

    return 0;

}