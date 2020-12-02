#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, i = 0;
    int *arr = (int *)calloc(1000, sizeof(int));
    while(scanf("%d",&n))
    {
        arr[i++] = n;
        if(getchar() == '\n')
            break;
    }
    int num = i;
    i = 1;
    int j = 0;
    while(i < num)
    {
        if(arr[i-1] == 0 || arr[i] == 0)
            i += 2;
        else
        {
            arr[j++] = arr[i-1]*arr[i];
            arr[j++] = arr[i]-1;
            i += 2;
        }
    }
    --j;
    if(j > 0)
    {
        for(i = 0; i < j; ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("%d", arr[j]);
    }
    else printf("0 0");
    return 0;
}