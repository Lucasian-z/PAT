#include <stdio.h>
int compare(char a, char b)
{
    if(a == 'J')
    {
        if(b == 'J')
            return 0;
        else if(b == 'C')
            return -1;
        else
            return 1;
    }
    if(a == 'C')
    {
        if(b == 'C')
            return 0;
        else if(b == 'B')
            return -1;
        else
            return 1;
    }
    if(a == 'B')
    {
        if(b == 'B')
            return 0;
        else if(b == 'J')
            return -1;
        else
            return 1;
    }
}

int main()
{
    int N;
    char a, b;
    int win1[3] = {0}, win2[3] = {0};
    int res = scanf("%d", &N);
    if(res != 1)
        return -1;
    int n = N;
    while(n--)
    {
        getchar();
        res = scanf("%c %c", &a, &b);
        if(res != 2)
            return -1;
        if(compare(a, b) == 1)
        {
            if(a == 'J')
                ++win1[0];
            else if(a == 'C')
                ++win1[1];
            else ++win1[2];
        }
        if(compare(a, b) == -1)
        {
            if(b == 'J')
                ++win2[0];
            else if(b == 'C')
                ++win2[1];
            else ++win2[2];
        }
    }
    int A_win_cnt = win1[0]+win1[1]+win1[2];
    int B_win_cnt = win2[0]+win2[1]+win2[2];
    char win1_c, win2_c;
    if(win1[2]>=win1[1] && win1[2] >= win1[0])
        win1_c = 'B';
    else if(win1[1]>=win1[0])
    {
        if(win1[1] > win1[2])
            win1_c = 'C';
        else
            win1_c = 'B';
    }
    else if(win1[0] > win1[1] && win1[0] > win1[2])
        win1_c = 'J';

    if(win2[2]>=win2[1] && win2[2] >= win2[0])
        win2_c = 'B';
    else if(win2[1]>=win2[0])
    {
        if(win2[1] > win2[2])
            win2_c = 'C';
        else
            win2_c = 'B';
    }
    else if(win2[0] > win2[1] && win2[0] > win2[2])
        win2_c = 'J';
    
    printf("%d %d %d\n", A_win_cnt, N-A_win_cnt-B_win_cnt , B_win_cnt);
    printf("%d %d %d\n", B_win_cnt, N-A_win_cnt-B_win_cnt , A_win_cnt);
    printf("%c %c", win1_c, win2_c);
    return 0;
}