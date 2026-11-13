#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort_asc(int *a, int n)              /* 버블 정렬 */
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1]) { t = a[j]; a[j] = a[j + 1]; a[j + 1] = t; }
}

/* 정렬된 a(na개)와 b(nb개)를 out에 합침, 합친 개수를 반환 */
int merge(int *a, int na, int *b, int nb, int *out)
{
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb)
        out[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
    while (i < na) out[k++] = a[i++];
    while (j < nb) out[k++] = b[j++];
    return k;
}

void print_arr(char *label, int *a, int n)
{
    int i;
    printf("%s(%d):", label, n);
    for (i = 0; i < n; i++) printf(" %d", a[i]);
    printf("\n");
}

int main(void)
{
    int g[4][20], n[4] = {0};             /* 4개 그룹을 2차원 배열 하나에 */
    int used[101] = {0};                  /* 중복 검사용: used[x] == 1이면 이미 생성 */
    int odd[20], even[20], all[20];
    int i, x, k, no, ne, na;
    char label[2] = "A";

    srand((unsigned)time(NULL));
    for (i = 0; i < 20; ) {
        x = rand() % 100 + 1;             /* 1 ~ 100 */
        if (used[x]) continue;
        used[x] = 1;
        i++;
        k = (x >= 50) + (x % 2 == 0) * 2; /* A=0 B=1 C=2 D=3 */
        g[k][n[k]++] = x;
    }

    for (k = 0; k < 4; k++) {
        sort_asc(g[k], n[k]);             /* g[k]는 k번째 행의 시작 주소 */
        label[0] = 'A' + k;
        print_arr(label, g[k], n[k]);
    }

    no = merge(g[0], n[0], g[1], n[1], odd);     /* A + B = 홀수 */
    ne = merge(g[2], n[2], g[3], n[3], even);    /* C + D = 짝수 */
    print_arr("홀수", odd, no);
    print_arr("짝수", even, ne);

    na = merge(odd, no, even, ne, all);
    print_arr("전체", all, na);

    return 0;
}