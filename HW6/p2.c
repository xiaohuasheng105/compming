#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* x가 s[0] ~ s[cnt-1] 중에 있으면 1, 없으면 0 */
int duplicated(int s[], int cnt, int x)
{
    int i;
    for (i = 0; i < cnt; i++)
        if (s[i] == x) return 1;
    return 0;
}

/* 점수 3개 중 가운데 값 = 합 - 최댓값 - 최솟값 */
int mid_cal(int s[])
{
    int mx = s[0], mn = s[0], i;
    for (i = 1; i < 3; i++) {
        if (s[i] > mx) mx = s[i];
        if (s[i] < mn) mn = s[i];
    }
    return s[0] + s[1] + s[2] - mx - mn;
}

/* 점수 내림차순으로 정렬하고 석차를 구함 (동일 석차: 1 1 3) */
void rank(char name[], char major[], int score[], int rk[], int n)
{
    int i, j, t;
    char c;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (score[j] < score[j + 1]) {
                t = score[j]; score[j] = score[j + 1]; score[j + 1] = t;
                c = name[j];  name[j]  = name[j + 1];  name[j + 1]  = c;
                c = major[j]; major[j] = major[j + 1]; major[j + 1] = c;
            }

    for (i = 0; i < n; i++) {
        rk[i] = 1;
        for (j = 0; j < n; j++)
            if (score[j] > score[i]) rk[i]++;
    }
}

double avg_cal(int score[], int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++) sum += score[i];
    return (double)sum / n;
}

int main(void)
{
    char name[5], major[5];
    int score[5], rk[5], s[3];
    int i, k, x;

    srand((unsigned)time(NULL));

    for (i = 0; i < 5; i++) {
        printf("%d번 학생의 이름과 전공(각 1자): ", i + 1);
        scanf(" %c %c", &name[i], &major[i]);

        for (k = 0; k < 3; ) {                /* 중복 없는 점수 3개 */
            x = rand() % 21 + 80;             /* 80 ~ 100 */
            if (!duplicated(s, k, x)) s[k++] = x;
        }
        printf("  점수: %d %d %d\n", s[0], s[1], s[2]);
        score[i] = mid_cal(s);
    }

    rank(name, major, score, rk, 5);

    for (i = 0; i < 5; i++)
        printf("%d등 %c %c %d\n", rk[i], name[i], major[i], score[i]);
    printf("전체 평균: %.2f\n", avg_cal(score, 5));

    return 0;
}