#include <stdio.h>

int main()
{
    int P_index = 0, T_index = 0;
    int N = 0;
    int ret = scanf("%d", &N);
    if (ret != 1)
        return 0;
    getchar();
    char c;
    while (N--)
    {
        int P = 0, T = 0, notA = 0, i = 0;
        while ((c = getchar()) != '\n')
        {

            if (c == 'P')
            {
                ++P;
                P_index = i;
            }
            else if (c == 'T')
            {
                ++T;
                T_index = i;
            }
            else if (c != 'A')
                ++notA;
            ++i;
        }
        if (P != 1 || T != 1 || notA || T_index - P_index <= 1)
        {
            printf("NO\n");
            continue;
        }
        int x = P_index, y = T_index - P_index - 1, z = i - T_index - 1;
        if (x * y == z)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}