#include <stdio.h>

int func(long n, int digit)
{
    int res = 0;
    while(n)
    {
        int tmp = n % 10;
        if(tmp == digit)
            ++res;
        n /= 10;
    }
    int number = 0;
    while(res--)
    {
        number = number * 10 + digit;
    }
    return number;
}

int main()
{
    long n1, n2;
    int digit1, digit2;
    int res = scanf("%ld %d %ld %d", &n1, &digit1, &n2, &digit2);
    if(res != 4)
        return -1;
    printf("%d", func(n1, digit1)+func(n2, digit2));
    return 0;
}