
#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b;
    char p;

    scanf("%d%c%d", &a,&p,&b);
    switch (p) {
        case '+':
            printf("%d", a+b);
            break;
        case '-':
            printf("%d", a-b);
            break;
        case '*':
            printf("%d", a*b);
            break;
        case '/':
            printf("%.2lf", (double)a/b);
            break;
        case '&':
            printf("%#X", a&b);
            break;
        case '|':
            printf("%#X",a|b);
            break;
        case '^':
            printf("%#X", a^b);
            break;
    }

    return 0;
}
