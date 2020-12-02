#include <stdio.h>

int main()
{
    int N = 0, D = 0;
    double e = 0.0;
    int ret = scanf("%d %lf %d", &N, &e, &D);
    if(ret != 3)
        return 0;
    int n = 0, empty_cnt1 = 0, empty_cnt2 = 0, N2 = N;
    double data = 0.0;
    while (N2--)
    {
        int cnt= 0;
        ret = scanf("%d", &n);
        if(ret != 1)
            return 0;
        for(int i = 0; i < n; ++i)
        {
            ret = scanf("%lf", &data);
            if(ret != 1)
                return 0;
            if(data < e)
            {
                ++cnt;
            }
        }
        if(cnt > n/2)
        {
            if(n > D)
                ++empty_cnt2;
            else 
                ++empty_cnt1;
        }
    }
    printf("%.1f%% %.1f%%", (double)empty_cnt1/N*100, (double)empty_cnt2/N*100);
    return 0;
}