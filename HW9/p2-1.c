#include <stdio.h>

/* 가. static 미사용: 누적값을 main의 변수에 포인터로 보관 */
void avg_ascii(char c, int *sum, int *len, double *avg)
{
    if (c >= 'A' && c <= 'Z') {           /* 소문자는 단어에서 제외 */
        *sum += c;
        (*len)++;
        *avg = (double)*sum / *len;
    }
}

int main(void)
{
    char word[21], c;
    int sum = 0, len = 0;
    double avg = 0;

    do {
        scanf(" %c", &c);                 /* 한 문자씩 입력 */
        avg_ascii(c, &sum, &len, &avg);
        if (c >= 'A' && c <= 'Z') word[len - 1] = c;
    } while (c >= 'A' && c <= 'Z');       /* 소문자가 나오면 단어 끝 */
    word[len] = '\0';

    printf("단어: %s\n길이: %d\nASCII 평균: %.2f\n", word, len, avg);
    return 0;
}
