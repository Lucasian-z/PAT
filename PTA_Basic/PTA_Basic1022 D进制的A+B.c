#include <stdio.h>

int In_convert(int n, int In, int *a)
{
    int i = 0;
    while(n)
    {   
        a[i++] = n % In;
        n /= In;
    }
    return i;
}

int main()
{
    int a[200] = {0};
    int n1, n2, In;
    int res = scanf("%d %d %d", &n1, &n2, &In);
    if(res != 3)
        return 0;
    int cnt = In_convert(n1+n2, In, a);
    if(cnt == 0)
        printf("0");
    for(int i = cnt-1; i >=0 ; --i)
    {
        printf("%d", a[i]);
    }
    return 0;
}