#include <stdio.h>

int compare(long x1, long x2, long x3)
{
    return x1 + x2 > x3;
}
int main()
{
    long x1, x2, x3;
    int n, i = 0;
    scanf("%d", &n);
    getchar();
    while(i < n)
    {
        scanf("%ld %ld %ld", &x1,&x2,&x3);
        getchar();
        fflush(stdin);
        ++i;
        if(compare(x1,x2,x3))
        {
            fflush(stdout);
            printf("Case #%d: true", i);
        }
        else
        {
            fflush(stdout);
            printf("Case #%d: false", i);
            
        }
        if(i < n)
            printf("\n");
    }
    return 0;
}