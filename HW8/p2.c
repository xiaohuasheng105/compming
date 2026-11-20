#include <stdio.h>

void swap_char(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

/* 학과명 오름차순, 같은 학과면 이름 오름차순. 두 배열을 항상 함께 교환 */
void sort_students(char *dept, char *name, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (dept[j] > dept[j + 1] ||
               (dept[j] == dept[j + 1] && name[j] > name[j + 1])) {
                swap_char(&dept[j], &dept[j + 1]);
                swap_char(&name[j], &name[j + 1]);
            }
}

/* 학과별로 출력하면서 각 학과 구간의 시작(start)과 끝(end, 미포함)을 기록. 학과 수를 반환 */
int print_by_dept(char *dept, char *name, int n, int *start, int *end)
{
    int i, d = 0;
    for (i = 0; i < n; i++) {
        if (i == 0 || dept[i] != dept[i - 1]) {      /* 새 학과 시작 */
            if (i > 0) printf("\n");
            printf("%c:", dept[i]);
            start[d++] = i;
        }
        printf(" %c", name[i]);
        end[d - 1] = i + 1;
    }
    printf("\n");
    return d;
}

/* 정렬된 학과 구간들의 맨 앞을 비교해 가장 작은 이름을 하나씩 꺼냄 (다중 merge) */
void merge_all(char *dept, char *name, int n, int *pos, int *end, int d)
{
    int k, c, best;
    for (c = 0; c < n; c++) {
        best = -1;
        for (k = 0; k < d; k++)
            if (pos[k] < end[k] &&
               (best < 0 || name[pos[k]] < name[pos[best]]))
                best = k;
        printf("%c(%c) ", name[pos[best]], dept[pos[best]]);
        pos[best]++;
    }
    printf("\n");
}

int main(void)
{
    char dept[10], name[10];
    int start[10], end[10], d, i;

    printf("학과명과 학생이름 10쌍 입력:\n");
    for (i = 0; i < 10; i++)
        if (scanf(" %c %c", &dept[i], &name[i]) != 2) {
            printf("입력 형식 오류\n");
            return 0;
        }

    sort_students(dept, name, 10);
    d = print_by_dept(dept, name, 10, start, end);
    if (d != 4) printf("(학과 수가 4개가 아닙니다: %d개)\n", d);

    printf("전체: ");
    merge_all(dept, name, 10, start, end, d);   /* start는 merge 중에 위치로 사용됨 */
    return 0;
}
