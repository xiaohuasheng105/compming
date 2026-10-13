
#include <stdio.h>

int main(int argc, char *argv[])
{
    int a,b,c,d;
    int ma = 0; int mi = 100;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    ma = a > ma ? a : ma;
    mi = a < mi ? a : mi;
    ma = b > ma ? b : ma;
    mi = b < mi ? b : mi;
    ma = c > ma ? c : ma;
    mi = c < mi ? c : mi;
    ma = d > ma ? d : ma;
    mi = d < mi ? d : mi;

    char grade;

    switch ((int)((a+b+c+d-ma-mi)/2)/10){
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'F';
            break;
    }   

    if (grade == 'F') printf("DROP F %d %.2lf", (a+b+c+d), (double)(a+b+c+d)/4);
    else printf("PASS %c %d %.2lf",grade, (a+b+c+d), (double)(a+b+c+d)/4);
    
    return 0;
}
