#include <stdio.h>
int main()
{
    int cnt[6] = {0};
    char c;
    while ((c = getchar()) != '\n')
    {
        switch (c)
        {
        case 'P':
            ++cnt[0];
            break;
        case 'A':
            ++cnt[1];
            break;
        case 'T':
            ++cnt[2];
            break;
        case 'e':
            ++cnt[3];
            break;
        case 's':
            ++cnt[4];
            break;
        case 't':
            ++cnt[5];
            break;
        default:
            break;
        }
    }
    while (cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] != 0)
    {
        if (cnt[0])
        {
            printf("P");
            --cnt[0];
        }

        if (cnt[1])
        {
            printf("A");
            --cnt[1];
        }

        if (cnt[2])
        {
            printf("T");
            --cnt[2];
        }

        if (cnt[3])
        {
            printf("e");
            --cnt[3];
        }

        if (cnt[4])
        {
            printf("s");
            --cnt[4];
        }

        if (cnt[5])
        {
            printf("t");
            --cnt[5];
        }
    }
    return 0;
}