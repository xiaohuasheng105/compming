#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_gen(int *a, int n)            /* 1 ~ 50 무작위 */
{
    int i;
    for (i = 0; i < n; i++) a[i] = rand() % 50 + 1;
}

/* 가장 작은 수를 마지막 자리에 놓고, 나머지 n-1개로 재귀 → 내림차순 */
void selection_sort(int *a, int n)
{
    int i, min = 0, t;

    if (n <= 1) return;                   /* 종료 조건 */
    for (i = 1; i < n; i++)
        if (a[i] < a[min]) min = i;
    t = a[min]; a[min] = a[n - 1]; a[n - 1] = t;
    selection_sort(a, n - 1);
}

/* 탐색 범위(lo, hi)를 static 변수로 유지하는 재귀 이진 탐색 (내림차순 배열) */
int bin_search(int *a, int n, int key)
{
    static int lo, hi, started = 0;
    int mid;

    if (!started) { lo = 0; hi = n - 1; started = 1; }   /* 첫 호출에서만 초기화 */

    if (lo > hi) { started = 0; return -1; }             /* 없음 */
    mid = (lo + hi) / 2;
    if (a[mid] == key) { started = 0; return mid; }      /* 찾음 */

    if (a[mid] > key) lo = mid + 1;       /* 내림차순이므로 key는 오른쪽 */
    else              hi = mid - 1;
    return bin_search(a, n, key);
}

int main(void)
{
    int a[20], i, key, pos;

    srand((unsigned)time(NULL));
    random_gen(a, 20);
    selection_sort(a, 20);

    for (i = 0; i < 20; i++) printf("%d ", a[i]);
    printf("\n찾을 수: ");
    scanf("%d", &key);

    pos = bin_search(a, 20, key);
    if (pos >= 0) printf("위치: %d번째\n", pos + 1);
    else          printf("NOT FOUND\n");

    return 0;
}
