#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    while(x >= 100)
    {
        printf("B");
        x -= 100;
    }
       
    while(x >= 10)
    {
        printf("S");
        x -= 10;
    }
    if(x != 0)
    {
        for(int i = 1; i <= x; ++i)
            printf("%d", i);
    }
    return 0;
}