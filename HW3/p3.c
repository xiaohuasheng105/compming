#include <stdio.h>

int main(void)
{
    int a, b, c, d;
    int ga, gb, gc, gd;   /* 각 숫자의 그룹 번호 (A=0 B=1 C=2 D=3) */
    int p, q, r, s, t;    /* 정렬 키 = 멤버수 * 4 + (3 - 그룹번호) */

    scanf("%d %d %d %d", &a, &b, &c, &d);

    ga = (a >= 50) + (a % 2 == 0) * 2; //abcd를 각각 0,1,2,3으로 구분 가능
    gb = (b >= 50) + (b % 2 == 0) * 2;
    gc = (c >= 50) + (c % 2 == 0) * 2;
    gd = (d >= 50) + (d % 2 == 0) * 2;

    p = ((ga == 0) + (gb == 0) + (gc == 0) + (gd == 0)) * 4 + 3;  /* A */
    q = ((ga == 1) + (gb == 1) + (gc == 1) + (gd == 1)) * 4 + 2;  /* B */
    r = ((ga == 2) + (gb == 2) + (gc == 2) + (gd == 2)) * 4 + 1;  /* C */
    s = ((ga == 3) + (gb == 3) + (gc == 3) + (gd == 3)) * 4;      /* D */

    if (p > q) { t = p; p = q; q = t; }
    if (r > s) { t = r; r = s; s = t; }
    if (p > r) { t = p; p = r; r = t; }
    if (q > s) { t = q; q = s; s = t; }
    if (q > r) { t = q; q = r; r = t; }

    printf("%c:%d %c:%d %c:%d %c:%d\n",
           'D' - p % 4, p / 4, 'D' - q % 4, q / 4,
           'D' - r % 4, r / 4, 'D' - s % 4, s / 4);

    return 0;
}