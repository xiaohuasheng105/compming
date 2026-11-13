#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 내림차순 배열에서 이진 탐색 (반복) : 찾으면 인덱스, 없으면 -1 */
int bin_iter(int a[], int n, int key, int *cnt)
{
    int lo = 0, hi = n - 1, mid;

    *cnt = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        (*cnt)++;                         /* key와 a[mid]를 비교한 횟수 */
        if (a[mid] == key) return mid;
        if (a[mid] > key) lo = mid + 1;   /* 내림차순이므로 key는 오른쪽 */
        else              hi = mid - 1;
    }
    return -1;
}

/* 같은 탐색을 재귀로 (호출 전에 *cnt = 0으로 초기화) */
int bin_rec(int a[], int lo, int hi, int key, int *cnt)
{
    int mid;

    if (lo > hi) return -1;               /* 종료 조건: 범위가 비면 없음 */
    mid = (lo + hi) / 2;
    (*cnt)++;
    if (a[mid] == key) return mid;
    if (a[mid] > key) return bin_rec(a, mid + 1, hi, key, cnt);
    return bin_rec(a, lo, mid - 1, key, cnt);
}

int main(void)
{
    int a[30], i, j, t, x, key, dup, idx, cnt;

    srand((unsigned)time(NULL));
    for (i = 0; i < 30; ) {               /* 중복 없는 0~100 */
        x = rand() % 101;
        dup = 0;
        for (j = 0; j < i; j++)
            if (a[j] == x) dup = 1;
        if (!dup) a[i++] = x;
    }

    for (i = 0; i < 29; i++)              /* 내림차순 정렬 */
        for (j = 0; j < 30 - 1 - i; j++)
            if (a[j] < a[j + 1]) { t = a[j]; a[j] = a[j + 1]; a[j + 1] = t; }

    for (i = 0; i < 30; i++) printf("%d ", a[i]);
    printf("\n찾을 점수: ");
    if (scanf("%d", &key) != 1) return 0;

    idx = bin_iter(a, 30, key, &cnt);
    if (idx >= 0) printf("[반복] %d등, 비교 %d회\n", idx + 1, cnt);
    else          printf("[반복] NOT FOUND, 비교 %d회\n", cnt);

    cnt = 0;
    idx = bin_rec(a, 0, 29, key, &cnt);
    if (idx >= 0) printf("[재귀] %d등, 비교 %d회\n", idx + 1, cnt);
    else          printf("[재귀] NOT FOUND, 비교 %d회\n", cnt);

    return 0;
}