#include <stdio.h>
#include <math.h>
#define _N 1000000

int main()
{
    int M, N, i, j;
    int p = 0;
    int isNotPrime[_N] = {0};
    int prime[_N/10];
    isNotPrime[0] = isNotPrime[1] = 1;
    for(i = 2; i <= _N; ++i)
    {
        if(!isNotPrime[i])
        {
            prime[p] = i;
            ++p;
            for(j = 2*i; j <= _N; j+=i)
                isNotPrime[j] = 1;
        }
    }
    scanf("%d %d", &M, &N);
    for(i = M-1; i < N; ++i)
    {
        printf("%d", prime[i]);
        if((i - M + 2)%10 && i != N-1)
            printf(" ");
        else if((i - M + 2)%10 == 0)
            printf("\n");
    }
    return 0;
}