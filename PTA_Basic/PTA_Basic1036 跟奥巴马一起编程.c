#include <stdio.h>
int main()
{
    int N;
    char c;
    int ret = scanf("%d %c", &N, &c);
    if(ret != 2)
        return 0;
    int row = ((double)N/2*10+5)/10;
    for(int i = 0; i < N; ++i)
    {
        printf("%c", c);
    }
    printf("\n");
    for(int i = 0; i < row-2; ++i)
    {
        printf("%c", c);
        for(int j = 0; j < N-2; ++j)
            printf(" ");
        printf("%c", c);
        printf("\n");
    }
    for(int i = 0; i < N; ++i)
    {
        printf("%c", c);
    }
    return 0;
}