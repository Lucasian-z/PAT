//此题易错点是当A的位数大于B的位数时，B需要在前面补零

#include <stdio.h>
int main()
{
    int a[100] = {0}, b[100] = {0};
    char res[100];
    int i = 0, j = 0, k = 0;
    char c;
    while ((c = getchar()) != ' ')
    {
        a[i++] = c - '0';
    }
    while ((c = getchar()) != '\n')
    {
        b[j++] = c - '0';
    }
    --i;
    --j;
    if(i > j)
    {
        for(k = j; k >= 0; --k)
            b[i-j+k] = b[k];
        for(k = 0; k < i-j; ++k)
            b[k] = 0;
        j = i;
        k = 0;
    }
    int flag = 1;
    while (i >= 0 && j >= 0)
    {
        if (flag == 1)
        {
            int num = (a[i] + b[j]) % 13;
            if (num == 10)
                res[k++] = 'J';
            else if (num == 11)
                res[k++] = 'Q';
            else if (num == 12)
                res[k++] = 'K';
            else
                res[k++] = num + '0';
        }
        else
        {
            int num = b[j] - a[i] < 0 ? b[j] - a[i] + 10 : b[j] - a[i];
            res[k++] = num + '0';
        }
        --i;
        --j;
        flag *= -1;
    }
    while (j >=0)
    {
        res[k++] = b[j--]+'0';

    }
    while (k)
    {
        printf("%c", res[--k]);
    }
    return 0;
}