#include <stdio.h>

int main()
{
    int t1, t2;
    int res = scanf("%d %d", &t1, &t2);
    if(res != 2)
        return 0;
    double s = (double)(t2-t1)/100;
    //printf("%lf\n", s);
    s = s*10+5;
    s /= 10;
    int s1 = (int)s;
    if(s1 >= 3600)
    {
        printf("%02d:", s1/3600);
        s1 %= 3600;
    }
    else
        printf("00:");
    if (s1 >= 60)
    {
        printf("%02d:", s1/60);
        s1 %= 60;
    }
    else
        printf("00:");
    printf("%02d", s1);
    return 0;
}