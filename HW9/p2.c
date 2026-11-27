#include <stdio.h>

/* 나. static 사용: 누적값을 함수 안의 static 변수에 보관 */
double avg_ascii(char c, int *len)
{
    static int sum = 0, cnt = 0;          /* 호출이 끝나도 값이 유지됨 */

    if (c >= 'A' && c <= 'Z') {
        sum += c;
        cnt++;
    }
    *len = cnt;
    return (double)sum / cnt;
}

int main(void)
{
    char word[21], c;
    int len = 0;
    double avg;

    do {
        scanf(" %c", &c);
        avg = avg_ascii(c, &len);
        if (c >= 'A' && c <= 'Z') word[len - 1] = c;
    } while (c >= 'A' && c <= 'Z');
    word[len] = '\0';

    printf("단어: %s\n길이: %d\nASCII 평균: %.2f\n", word, len, avg);
    return 0;
}
