#include <stdio.h>

/* 합과 차를 포인터로 돌려줌 */
void add_sub(int m, int n, int *sum, int *diff)
{
    *sum = m + n;
    *diff = m - n;
}

/* m과 n을 교환한 후 합과 차를 다시 구함 */
void swap(int *m, int *n, int *sum, int *diff)
{
    int t = *m;
    *m = *n;
    *n = t;
    add_sub(*m, *n, sum, diff);
}

int main(void)
{
    int m, n, sum, diff;

    printf("정수 2개 입력: ");
    if (scanf("%d %d", &m, &n) != 2) return 0;

    add_sub(m, n, &sum, &diff);
    printf("교환 전: m=%d n=%d 합=%d 차=%d\n", m, n, sum, diff);

    swap(&m, &n, &sum, &diff);
    printf("교환 후: m=%d n=%d 합=%d 차=%d\n", m, n, sum, diff);

    return 0;
}