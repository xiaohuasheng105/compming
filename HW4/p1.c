#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int n, i, k, d, started = 0;

    unsigned long long dh = 0, dl = 1;   
    unsigned long long bh = 0, bl = 1;   

    srand((unsigned)time(NULL));
    n = rand() % 16 + 10;                

    for (i = 2; i <= n; i++) {
        dl *= i;
        dh = dh * i + dl / 100000000000000000ULL;   
        dl %= 100000000000000000ULL;

        bl *= i;
        bh = bh * i + (bl >> 57);                   
        bl &= (1ULL << 57) - 1;                     
    }

    printf("n = %d\n", n);

    printf("n! = ");
    if (dh) printf("%llu%017llu\n", dh, dl);
    else    printf("%llu\n", dl);

    printf("8진수 = ");
    for (k = 39; k >= 0; k--) {
        if (k >= 19)
            d = (int)((bh >> (3 * (k - 19))) & 7);
        else
            d = (int)((bl >> (3 * k)) & 7);

        if (d || started || k == 0) {    
            putchar('0' + d);
            started = 1;
        }
    }
    putchar('\n');

    return 0;
}
