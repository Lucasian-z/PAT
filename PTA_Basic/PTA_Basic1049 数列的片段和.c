#include <stdio.h>

int main()
{
    int N = 0;
    int ret = scanf("%d", &N);
    if(ret != 1)
        return 0;
    int i = 0;
    double sum = 0.0, tmp;
    while (i < N)
    {
        ret = scanf("%lf", &tmp);
        if(ret != 1)
            return 0;
        sum += tmp * (N-i)*(i+1);
        ++i;
    }
    printf("%.2f", sum);
    return 0;
}