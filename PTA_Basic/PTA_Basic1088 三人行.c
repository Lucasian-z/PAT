#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//本题关键在于丙的能力值可以为浮点数
int main()
{
    int M = 0, X = 0, Y = 0;
    int ret = scanf("%d %d %d", &M, &X, &Y);
    if (ret != 3)
        return 0;
    double a[3] = {0};
    int i = 99;
    while (i)
    {
        a[0] = i;
        a[1] = (i % 10) * 10 + i / 10;
        a[2] = fabs(a[0] - a[1]) / X;
        if (a[1] == a[2] * Y)
            break;
        --i;
    }
    if (a[0] < 10)
        printf("No Solution");
    else
    {
        printf("%d ", (int)a[0]);
        for (i = 0; i < 3; ++i)
        {
            if (a[i] > M)
                printf("Cong");
            else if (a[i] == M)
                printf("Ping");
            else
                printf("Gai");
            if (i != 2)
                printf(" ");
        }
    }
    return 0;
}