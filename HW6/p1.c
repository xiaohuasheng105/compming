#include <stdio.h>

long long fact(int n)                 /* 가. 반복 방식 */
{
    long long f = 1;
    int i;
    for (i = 2; i <= n; i++) f *= i;
    return f;
}

long long fact2(int n)                 /* 나. 순환 방식 */
{
    if (n <= 1) return 1;             /* 종료 조건: 0! = 1! = 1 */
    return n * fact2(n - 1);
}

long long comb(int n, int r)          /* nCr = n! / ((n-r)! * r!) */
{
    return fact(n) / (fact(n - r) * fact(r));
}

int main(void)
{
    int n;

    printf("노드 개수(1~10): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 10) {
        printf("1~10 사이의 정수를 입력하세요.\n");
        return 0;
    }
    printf("%d개 노드의 이진 트리 개수: %lld\n", n, comb(2 * n, n));
    return 0;
}