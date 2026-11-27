#include <stdio.h>

int total_cal(int s[])                    /* 한 학생의 총점 */
{
    return s[0] + s[1] + s[2];
}

double avg_cal(int total)                 /* 한 학생의 평균 */
{
    return total / 3.0;
}

int main(void)
{
    char name[5], tc;
    int score[5][3], total[5], i, j, ti;
    double avg[5], td;

    for (i = 0; i < 5; i++) {
        scanf(" %c %d %d %d", &name[i], &score[i][0], &score[i][1], &score[i][2]);
        total[i] = total_cal(score[i]);
        avg[i] = avg_cal(total[i]);
    }

    for (i = 0; i < 4; i++)               /* 이름 오름차순 정렬 */
        for (j = 0; j < 4 - i; j++)
            if (name[j] > name[j + 1]) {
                tc = name[j];  name[j]  = name[j + 1];  name[j + 1]  = tc;
                ti = total[j]; total[j] = total[j + 1]; total[j + 1] = ti;
                td = avg[j];   avg[j]   = avg[j + 1];   avg[j + 1]   = td;
            }

    for (i = 0; i < 5; i++)
        printf("%c %d %.2f\n", name[i], total[i], avg[i]);

    return 0;
}
