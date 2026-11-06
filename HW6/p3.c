#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* cnt[]에서 target과 같은 그룹을 A부터 순서대로 모두 출력 */
void print_groups(char label[], int cnt[], int target)
{
    int i;
    printf("%s:", label);
    for (i = 0; i < 10; i++)
        if (cnt[i] == target) printf(" %c %d ", 'A' + i, cnt[i]);
    printf("\n");
}

int main(void)
{
    int cnt[10] = {0}, i, x, mx, mn;

    srand((unsigned)time(NULL));

    printf("생성된 수:");
    for (i = 0; i < 20; i++) {
        x = rand() % 100;                 /* 0 ~ 99 */
        printf(" %d", x);
        cnt[x / 10]++;                    /* 0~9 → A, ..., 90~99 → J */
    }
    printf("\n");

    for (i = 0; i < 10; i++) printf("%c:%d ", 'A' + i, cnt[i]);
    printf("\n");

    mx = mn = cnt[0];
    for (i = 1; i < 10; i++) {
        if (cnt[i] > mx) mx = cnt[i];
        if (cnt[i] < mn) mn = cnt[i];
    }

    print_groups("Max", cnt, mx);
    print_groups("Min", cnt, mn);

    return 0;
}