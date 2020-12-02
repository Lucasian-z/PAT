#include <stdio.h>
#include <math.h>
int isPrime(int n)
{
    if(n == 1 || n == 0)
        return 0;
    for(int i = 2; i <= (int)sqrt(n); ++i)
        if(n % i == 0)
            return 0;
    return 1;
}
int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    int res = 0;
    for(int i = 0; i + 2 <= N; ++i)
    {
        if(isPrime(i) && isPrime(i+2))
        {
            ++res;
        }
            
    }
    printf("%d", res);
    return 0;
}