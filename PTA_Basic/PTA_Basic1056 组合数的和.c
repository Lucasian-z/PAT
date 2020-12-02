#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N = 0;
    int ret = scanf("%d", &N);
    if(ret != 1)
        return 0;
    int *arr = (int *)calloc(N, sizeof(int));
    if(arr == NULL)
        return 0;
    for (int i = 0; i < N; ++i)
    {
        ret = scanf("%d", &arr[i]);
        if(ret != 1)
            return 0;
    }
    int sum = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(i != j)
            {
                sum += arr[i]*10+arr[j];
            }
        }
    }
    printf("%d", sum);
    return 0;
}