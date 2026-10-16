#include <stdio.h>

int main(void)
{
    int c, line = 0, inword = 0;
    int w = 0, len = 0, tw = 0, tlen = 0;


    while (line < 3) {
        c = getchar();

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (!inword) { w++; inword = 1; }
            len++;
        }
        else {
            inword = 0;                 
            if (c == '\n' || c == EOF) {
                line++;
                printf("%d번째 줄: 단어 %d개, 평균 단어길이 %.2f\n",
                       line, w, w ? (double)len / w : 0.0);
                tw += w; tlen += len;
                w = len = 0;
                if (c == EOF) break;
            }
        }
    }

    printf("전체: 단어 %d개, 평균 단어길이 %.2f\n", tw, tw ? (double)tlen / tw : 0.0);

    return 0;
}