#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a[11][2] = {0};
    srand(time(NULL));

    for (int i = 0; i < 20; i++){
        int t = rand() % 101;
        
        if (t == 100) a[0][0]++;
        else {
            a[9 - (t / 10)][0]++;
        }
        
        if (i < 11) a[i][1] = i;
    }

    for (int i = 0; i < 10; i++){
        for (int j = i+1; j < 10; j++){
            if (i == j) continue;
            if (a[i][0] < a[j][0] || (a[i][0] == a[j][0] && a[i][1] > a[j][1])){
                int temp = a[i][0];
                a[i][0] = a[j][0];
                a[j][0] = temp;
                temp = a[i][1];
                a[i][1] = a[j][1];
                a[j][1] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++){
        printf("%c:%d   ", 'A'+a[i][1], a[i][0]);
    }
    return 0;
}
