#include <stdio.h>

int main(void)
{
    long long a, b, num = 0, den = 1, x, y, t;
    int cnt = 0;



    while (scanf("%lld/%lld", &a, &b) == 2) {
        

        num = num * b + a * den; // 통분
        den *= b;

        // 유클리드 호제법 약분
        x = num; y = den;
        while (y) { t = x % y; x = y; y = t; }

        num /= x;
        den /= x;
        cnt++;
    }

    if (cnt == 0)
        printf("유효한 분수가 입력되지 않았습니다.\n");
    else if (num % den == 0)
        printf("%lld\n", num / den);
    else if (num < den)
        printf("%lld/%lld\n", num, den);
    else
        printf("%lld/%lld (%lld+%lld/%lld)\n", num, den, num / den, num % den, den);

    return 0;
}