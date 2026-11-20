#include <stdio.h>

/* 과목 sub의 점수로 학생 번호(ord)를 내림차순 정렬 */
void sort_by_subject(int score[][3], int n, int sub, int *ord)
{
    int i, j, t;

    for (i = 0; i < n; i++) ord[i] = i;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (score[ord[j]][sub] < score[ord[j + 1]][sub]) {
                t = ord[j]; ord[j] = ord[j + 1]; ord[j + 1] = t;
            }
}

/* 석차 = 나보다 점수가 높은 학생 수 + 1  (1,2,2,2,5) */
int get_rank(int score[][3], int n, int sub, int me)
{
    int i, r = 1;
    for (i = 0; i < n; i++)
        if (score[i][sub] > score[me][sub]) r++;
    return r;
}

int main(void)
{
    char name[5], dept[5];
    int id[5], score[5][3], ord[5];       /* 성적은 2차원 배열 하나에 저장 */
    char *subject[3] = {"Korean", "English", "Math"};
    int i, s, k;

    for (i = 0; i < 5; i++)
        scanf(" %c %c %d %d %d %d", &name[i], &dept[i], &id[i],
              &score[i][0], &score[i][1], &score[i][2]);

    for (s = 0; s < 3; s++) {
        printf("%s:\n", subject[s]);
        sort_by_subject(score, 5, s, ord);
        for (k = 0; k < 5; k++) {
            i = ord[k];
            printf("%d %c %d %c %d\n", get_rank(score, 5, s, i),
                   name[i], id[i], dept[i], score[i][s]);
        }
    }
    return 0;
}
