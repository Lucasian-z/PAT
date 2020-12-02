#include <stdio.h>

int main()
{
    int a[50] = {0};
    int i = 0, j = 0, n = 0;
    int num = 0, cnt = 0;
    for(; i < 10; ++i)
    {
        int res = scanf("%d", &num);
        if(res != 1)
            return 0;
        cnt += num;
        for(j = 0; j < num; ++j)
            a[n++] = i;
    }
    int min = 0, p = 0;
    for(i = 0; i < cnt-1; ++i)
    {
        min  = a[i];
        p = i;
        for(j = i + 1; j < cnt; ++j)
        {
            if(a[j] < min)
            {
                min = a[j];
                p = j;
            }
        }
        int tmp = a[i];
        a[i] = a[p];
        a[p] = tmp;
    }
    for(i = 0; a[i] == 0; ++i);
    if(i > 0)
    {
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
    }
    for(i = 0; i < cnt; ++i)
        printf("%d", a[i]);
    return 0;
}