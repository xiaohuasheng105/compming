#include <stdio.h>

int main(void)
{
    int i, a, b, c, mx, mn, mid, lv;
    double sum = 0;

    for (i = 1; i <= 5; i++) {
        scanf("%d %d %d", &a, &b, &c);

        
        mx = a > b ? (a > c ? a : c) : (b > c ? b : c);
        mn = a < b ? (a < c ? a : c) : (b < c ? b : c);
        mid = a + b + c - mx - mn;

       
        lv = mid < 60 ? 0 : (mid >= 90 ? 4 : (mid - 50) / 10);

        printf("%d: %c\n", i, lv ? 'E' - lv : 'F');
        sum += lv ? lv + 0.5 : 0;
    }

    printf("전체 평점: %.2f\n", sum / 5);

    return 0;
}