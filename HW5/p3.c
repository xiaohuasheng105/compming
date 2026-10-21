#include <stdio.h>


int main(int argc, char *argv[])
{
    char a[5][6] = {0};
    char b[5];
    double grade[5] = {0};
    for (int i = 0; i < 5; i++){
        scanf(" %c", &b[i]);
        char ma = 'A';
        char mi = 'F';
        for (int j = 0; j < 6; j++){
            scanf(" %c", &a[i][j]);
            if (a[i][j] > ma) ma = a[i][j];
            if (a[i][j] < mi) mi = a[i][j];
            if (a[i][j] != 'F'){
                grade[i] += (4.5 - (a[i][j] - 'A'));
            }
        }
        grade[i] -= (ma != 'F') ? (4.5 - (ma - 'A')) : 0;
        grade[i] -= (mi != 'F') ? (4.5 - (mi - 'A')) : 0;

        grade[i]/=4.0;
    }

    for (int i = 0; i < 5; i++){
        for (int j = i+1 ; j < 5; j++){
            if (grade[i] < grade[j]){
                double temp = grade[i];
                grade[i] = grade[j];
                grade[j] = temp;
                char t = b[i];
                b[i] = b[j];
                b[j] = t;
            }
        }
    }
    int pre = 1;
    for (int i = 0; i < 5; i++) {
        if (i != 0 && grade[i] != grade[i-1]) pre = i + 1;
        printf("%d : %c %.2lf   ", pre, b[i], grade[i]);
    }
}
