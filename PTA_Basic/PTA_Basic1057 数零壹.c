#include <stdio.h>

int main()
{
    char c;
    int N = 0;
    while((c = getchar()) != '\n')
    {
        if(c <= 'z' && c >= 'a')
        {
            N += c-'a'+1;
        }
        else if(c <= 'Z' && c >= 'A')
        {
            N += c-'A'+1;
        }
    }
    int cnt0 = 0, cnt1 = 0;
    while (N)
    {
        if(N % 2)
            ++cnt1;
        else ++cnt0;
        N /= 2;
    }
    printf("%d %d", cnt0, cnt1);
    return 0;
}